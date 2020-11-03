
//
//  DeveloperAnalysis.h
//  csc340-midterm
//
//  Created by Jinjian Tan on 10/30/20.
//  Implemented by Juan Hernandez 11/1/20
#include "DeveloperAnalysis.h"
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

DeveloperAnalysis::DeveloperAnalysis(Utilities tools){
    utility = tools;
    gameList = utility.getAllGames();
}

/*
        This function addresses the question 2) in the proposal

        1) get all the games
        2) count the number of entry which "publisher" equal "developer"
        3) count the percentage as (the above number/total number of games) * 100%
        4) print the result

     */

void DeveloperAnalysis::getPercentageDevByPub() {
    double pubEqualsdev = 0;
    double percentage;
    for(int i=0; i < gameList.size(); i++) {
       if(gameList.at(i).getDeveloper() == gameList.at(i).getPublisher()) {
          pubEqualsdev = pubEqualsdev + 1;
       }
    }
    percentage = (pubEqualsdev / gameList.size()) * 100;

    cout << endl << percentage << "% of developers publish their own games." << endl << endl;
}

 /*
        This function addresses the question 3) in the proposal
        parameter @developer is the developer to be analyzed
        parameter @fieldname is the field be used to sort the game
                             it could be sales or userscore
        1) get all the games by given developer
        2) sort the games by the given fields (sales or userscores)
        3) print out top 10 games of the sorting result.
     */

 void DeveloperAnalysis::getPopularGamesByDeveloper(string developer, string fieldname) {
    vector<Game> gamesByDev = utility.getGamesByDeveloper(gameList, developer);
    int maxIndex;
    Game temp1, temp2;
    double currMax;
    if(fieldname == "sales") {
        for(int i = 0; i < gamesByDev.size(); ++i) {
            currMax = gamesByDev.at(i).getSales().getGlobalSales();
            maxIndex = i;

            for (int j = i; j < gamesByDev.size(); ++j) {
                if(gamesByDev.at(j).getSales().getGlobalSales() > currMax) {
                    maxIndex = j;
                    currMax = gamesByDev.at(j).getSales().getGlobalSales();
                }
          }

            temp1 = gamesByDev.at(i);
            temp2 = gamesByDev.at(maxIndex);

         gamesByDev.at(i) = temp2;
         gamesByDev.at(maxIndex) = temp1;
       }

        cout << "The top ten games based on sales are: " << endl;
        int i;
        cout << endl;
        for(i = 0; i < gamesByDev.size(); i++){
            if(i == 10)break;
           if(gamesByDev.at(i).getSales().getGlobalSales() != -1){
               cout << setfill('-') << setw(47) << "" << endl;
               cout << gamesByDev.at(i).getGameName() << ": " << gamesByDev.at(i).getSales().getGlobalSales() << " million units"<< endl;
           }
        }
        cout << setfill('-') << setw(47) << "" << endl;
        cout << "There are total: " << i << " game(s) listed." << endl;
        cout << endl;
    }
    else if(fieldname == "userScore") {
        for(int i = 0; i < gamesByDev.size(); ++i) {
            currMax = gamesByDev.at(i).getScores().getUserScore();
            maxIndex = i;

            for (int j = i; j < gamesByDev.size(); ++j) {
                if(gamesByDev.at(j).getScores().getUserScore() > currMax) {
                    maxIndex = j;
                    currMax = gamesByDev.at(j).getScores().getUserScore();
                }
            }


            temp1 = gamesByDev.at(i);

            temp2 = gamesByDev.at(maxIndex);
            gamesByDev.at(i) = temp2;
            gamesByDev.at(maxIndex) = temp1;
       }

        cout << "The top ten games based on user scores are: " << endl;
        int i;
        cout << endl;
        for(i = 0; i < gamesByDev.size(); i++){
            if(i == 10)break;
            if(gamesByDev.at(i).getScores().getUserScore() != -1){
                cout << setfill('-') << setw(47) << "" << endl
                cout << gamesByDev.at(i).getGameName() << ": " << gamesByDev.at(i).getScores().getUserScore() << " /10 according to users."<< endl;
            }
        }
        cout << setfill('-') << setw(47) << "" << endl;
        cout << "There are total: " << i << " game(s) listed." << endl;
        cout << endl;

    }


 }




void DeveloperAnalysis::getPopularGenresByPlatform(string platform, string fieldname) {

vector<Game> Gamelist = getGamesByPlatform( gameCollection, platform);

int topList = 10;
int totalSize;
int MaxVal;

if (fieldname == "sales") {

for ( int  i = 1 ; i < Gamelist.size() ; i++ ) {
    MaxVal = Gamelist.at(i).getSales().getGlobalSales();
    totalSize = i;
}

for ( int j = i ; j < GameList.size() ; j++ ) {
if (Gamelist.at(j).GetSales().getGlobalSales()  > MaxVal) {
	totalSize = j;
	MaxVal = Gamelist.at(j).getSales().getGlobalSales();
}
}
}
		

cout << “The most popular Platforms based on Sales are: ” << endl << endl;

for ( int i = 0; i < Gamelist.size(); i++ ){
if ( i >= topList ) {
	break;
}

else {
cout << Gamelist.at(i).getPlatform() “, ” 
cout << Gamelist.at(i).getSales().getGlobalSales() << “ Million Copies.” << endl;
}
}

if (fieldname == “userScore”) {

for ( int  i = 1 ; i < Gamelist.size() ; i++ ) {
MaxVal = Gamelist.at(i).getScores().getUserScore();
totalSize = i;
}

for ( int j = i ; j < GameList.size() ; j++ ) {
if (Gamelist.at(j).getScores().getUserScore()  > MaxVal) {
	totalSize = j;
	MaxVal = Gamelist.at(j).getScores().getUserScore();
}
}
}


cout << “The most popular Platforms based on Scores are: ” << endl << endl;


for ( int i = 0; i < Gamelist.size(); i++ ){
if ( i >= topList ) {
	break;
}

else {
cout << Gamelist.at(i).getPlatform() "," 
cout  <<  ", With a rating of "  << Gamelist.at(i).getScores().getUserScore << "/10." << endl;
}
}



