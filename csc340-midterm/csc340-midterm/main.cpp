//
//  main.cpp
//  csc340-midterm
//
//  Created by Jinjian Tan on 10/20/20.
//
#include "Data/Game.h"

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
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
    
    game.printInfo();
    return 0;
}
