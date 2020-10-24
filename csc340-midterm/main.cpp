//
//  main.cpp
//  csc340-midterm
//
//  Created by Jinjian Tan on 10/20/20.
//
#include "Data/Utilities.h"

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    /* // thest fot testing the function 
    string gameName =  "Wii Sports";
    string platform = "Wii";
    int yearOfRelease = 2006;
    string genre = "Sports";
    string publisher = "Nintendo";
    double NASales = 41.36;
    double EUSales = 28.96;
    double JPSales = 3.77;
    double otherSales = 8.45;
    double globalSales = 82.53;
    int criticScore = 76;
    int criticCount = 51;
    double userScore = 8.0;
    int userCount = 322;
    string developer = "Nintendo";
    string rating = "E";
    Sales sales(gameName, platform, yearOfRelease, NASales, EUSales, JPSales, otherSales, globalSales);
    Scores scores(gameName, platform, yearOfRelease, criticScore, criticCount, userScore, userCount);
    Game game(gameName, platform, yearOfRelease, genre, publisher, sales, scores, developer, rating);
    
   // game.printInfo();
    cout << game;
    */
    // Chagee the filepath to your local (absolute) path of data.csv
    string filepath = "/Users/jinjiantan/Git/csc340-midterm/csc340-midterm/Data/data.csv";
    Utilities utilities;
    utilities.LoadFile(filepath);
    int i;
    // The code below is the example of filtering by field developer and genre
    vector<Game> gamesByDev = utilities.getGamesByDeveloper("Nintendo");
    vector<Game> gamesByDevThenByGenre = utilities.getGamesByGenre(gamesByDev, "Platform");
    
/*    for(i = 0; i < gamesByDevThenByGenre.size(); ++i){
        cout << gamesByDevThenByGenre.at(i);
    }
    cout << i << " games have been listed." << endl;
    
      
    vector<Game> gamesByGenre =
    utilities.getGamesByGenre("Platform");
    cout << gamesByGenre.size() << " games have been listed." << endl;
 */
    string fields[] = {"Name", "Platform", "EUSales"};
    int fieldSize = 3;
    utilities.printByFields(gamesByDevThenByGenre,fields, fieldSize);
    return 0;
}
