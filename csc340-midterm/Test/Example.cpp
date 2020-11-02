//
//  Example.cpp
//  csc340-midterm
//
//  Created by Jinjian Tan on 10/27/20.
//
#include "GenreAnalysis.h"
#include "DeveloperAnalysis.h"
#include "Utilities.h"
#include<iostream>
#include<algorithm>
using namespace std;
/*
int main(int argc, const char * argv[]){
    Utilities utilities;
    // Load data file, pls change to you own path
    utilities.LoadFile("/Users/jinjiantan/Git/csc340-midterm/csc340-midterm/Data/data.csv");
    // Print all games
    // utilities.printAllGames();
    // Get all games
    vector<Game> games = utilities.getAllGames();
    
    // Get games by a given developer
    //vector<Game> gamesByDev = utilities.getGamesByDeveloper("Nintendo");
    
    // Set up a string array holds fileds to print, check README.md
    // to see the schema
    //string fields[] = {"All"};
    
    // Print the games in the given collection (vector)
    // by given fields.
    //utilities.printByFields(gamesByDev, fields, 1);
    
    /* The example below is to filter the given collection
       by a given field. At this example, filtered genre as "platform" under developer "Nintendo".
     */
    //vector<Game> devPlatform = utilities.getGamesByGenre(gamesByDev, "Platform");
    //utilities.printByFields(devPlatform,fields,1);
    
    /*
     Basic example of get top 10 sales of developer Nitendo
     */
    /*
    struct{
        bool operator()(Game a, Game b) const
        {
            return a.getSales().getGlobalSales()
            < b.getSales().getGlobalSales();
        }
    }globalSalesAscending;
    
    sort(devPlatform.begin(), devPlatform.end(), globalSalesAscending);
    utilities.printByFields(devPlatform,fields,1);
    */
    /*
    GenreAnalysis genreAnalysis;
    genreAnalysis.getPopularGenresBySales(games);
    DeveloperAnalysis developAnalysis(utilities);
    developAnalysis.getPercentageDevByPub();
    developAnalysis.getPopularGamesByDeveloper("Nintendo", "userScore");
    return 0;
}

*/
