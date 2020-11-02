#include "Utilities.h"
#include "Game.h"
#include "DeveloperAnalysis.h"
#include <vector>
#include <iostream>
using namespace std;

DeveloperAnalysis::DeveloperAnalysis(Utilities tools, vector<> games) {
   utility = tools;
   gameList = utility.getAllGames();
}

/*
        This function addresses the question b) in the proposal

        1) get all the games
        2) count the number of entry which "publisher" equal "developer"
        3) count the percentage as (the above number/total number of games) * 100%
        4) print the result

     */

void DeveloperAnalysis::getPercentageDevByPub() {
    double pubEqualsdev = 0;
    double percentage;
    for(int i=0; i < gameList.size(); i++) {
       if(gameList.at(i).getDeveloper == gameList.at(i).getPublisher) {
          pubEqualsdev = pubEqualsdev + 1;
       }
    }
    percentage = (pubEqualsdev / gameList.size()) * 100;

    cout << percentage << "% of developers publish their own games." << endl;
}

 /*
        This function addresses the question c) in the proposal
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
                if(gamesbyDev.at(j).getSales().getGlobalSales() > currMax) {
                    maxIndex = j;
                    currMax = gamesByDev.at(j).getSales().getGlobalSales();
                }
          }

         temp1 = new Game(
            gamesbyDev.at(i).getGameName(),
            gamesByDev.at(i).getPlatform(),
            gamesByDev.at(i).getYearOfRelease(),
            gamesByDev.at(i).getGenre(),
            gamesByDev.at(i).getPublisher(),
            gamesByDev.at(i).getSales(),
            gamesByDev.at(i).getScores(),
            gamesByDev.at(i).getDeveloper(),
            gamesByDev.at(i).getRating()
            );

         temp2 = new Game(
            gamesbyDev.at(maxIndex).getGameName(),
            gamesByDev.at(maxIndex).getPlatform(),
            gamesByDev.at(maxIndex).getYearOfRelease(),
            gamesByDev.at(maxIndex).getGenre(),
            gamesByDev.at(maxIndex).getPublisher(),
            gamesByDev.at(maxIndex).getSales(),
            gamesByDev.at(maxIndex).getScores(),
            gamesByDev.at(maxIndex).getDeveloper(),
            gamesByDev.at(maxIndex).getRating()
            );

         gamesByDev.at(i) = temp2;
         gamesByDev.at(maxIndex) = temp1;
       }

       cout << "The top ten games based on sales are: " << endl;
       for(int i = 0; i < 10; i++){
          cout << gamesByDev.at(i).getGameName() << ": " << gamesByDev.at(i).getSales().getGlobalSales() << " million units"<< endl;
       }
    }
    else if(fieldname == "userScore") {
        for(int i = 0; i < gamesByDev.size(); ++i) {
            currMax = gamesByDev.at(i).getScores().getUserScore();
            maxIndex = i;

            for (int j = i; j < gamesByDev.size(); ++j) {
                if(gamesbyDev.at(j).getScores().getUserScore() > currMax) {
                    maxIndex = j;
                    currMax = gamesByDev.at(j).getScores().getUserScore();
                }
          }

         temp1 = new Game(
            gamesbyDev.at(i).getGameName(),
            gamesByDev.at(i).getPlatform(),
            gamesByDev.at(i).getYearOfRelease(),
            gamesByDev.at(i).getGenre(),
            gamesByDev.at(i).getPublisher(),
            gamesByDev.at(i).getSales(),
            gamesByDev.at(i).getScores(),
            gamesByDev.at(i).getDeveloper(),
            gamesByDev.at(i).getRating()
            );

         temp2 = new Game(
            gamesbyDev.at(maxIndex).getGameName(),
            gamesByDev.at(maxIndex).getPlatform(),
            gamesByDev.at(maxIndex).getYearOfRelease(),
            gamesByDev.at(maxIndex).getGenre(),
            gamesByDev.at(maxIndex).getPublisher(),
            gamesByDev.at(maxIndex).getSales(),
            gamesByDev.at(maxIndex).getScores(),
            gamesByDev.at(maxIndex).getDeveloper(),
            gamesByDev.at(maxIndex).getRating()
            );

         gamesByDev.at(i) = temp2;
         gamesByDev.at(maxIndex) = temp1;
       }

       cout << "The top ten games based on user scores are: " << endl;
       for(int i = 0; i < 10; i++){
          cout << gamesByDev.at(i).getGameName() << ": " << gamesByDev.at(i).getSales().getGlobalSales() << " /10 according to users."<< endl;
       }

    }


 }