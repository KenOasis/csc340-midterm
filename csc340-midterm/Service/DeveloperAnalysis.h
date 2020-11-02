
//
//  DeveloperAnalysis.h
//  csc340-midterm
//
//  Created by Jinjian Tan on 10/30/20.
//  Implemented by Juan Hernandez 11/1/20

#ifndef DeveloperAnalysis_h
#define DeveloperAnalysis_h

#include "Utilities.h"
#include "Game.h"
#include <vector>
class DeveloperAnalysis{
public:

    DeveloperAnalysis(Utilities tools);
    /*
        This function addresses the question b) in the proposal
     
        1) get all the games
        2) count the number of entry which "publisher" equal "developer"
        3) count the percentage as (the above number/total number of games) * 100%
        4) print the result
     
     */
    void getPercentageDevByPub();
    
    /*
        This function addresses the question c) in the proposal
        parameter @developer is the developer to be analyzed
        parameter @fieldname is the field be used to sort the game
                             it could be sales or userscore
        1) get all the games by given developer
        2) sort the games by the given fields (sales or userscores)
        3) print out top 10 games of the sorting result.
     */
    void getPopularGamesByDeveloper(string developer, string fieldname);
private:
    Utilities utility;
    vector<Game> gameList;
};

#endif /* DeveloperAnalysis_h */
