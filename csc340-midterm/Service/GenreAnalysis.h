//
//  GenreAnalysis.h
//  csc340-midterm
//
//  Created by Jinjian Tan on 10/30/20.
//

#ifndef GenreAnalysis_h
#define GenreAnalysis_h
#include "Utilities.h"
#include <string>
#include <vector>
using namespace std;
class GenreAnalysis{
public:
    /*
        This function addresses the question 1) in the proposal
        
        steps (in general):
        1) sort all the game base on the sales
        2) set tokens to count how many games for a given genre
           occurs in the first 50% of the sorted games.
           for example, if there are 15 games of genre "platform"
           in the sorted games, then the token of "platform" should
           be 15.
        3) count the total(global) sales of games for a given genre;
            
        4) List(print) the top 5 genres by tokens and print their total sales. (sort by tokens but not sales)
         
    */
    void getPopularGenresBySales(vector<Game> games);
    
    /*
        This function addresses the question 4) in the proposal

        parameter @fieldname is the field be used to sort the games, it could be developer, sales, userscores or critic scores.
        parameter @platform is the platform to be researched
        
     steps (in general):
        1) get all the games by the given platform
        2) sort them by the given field.
        3) set tokens to count how many games for a give genre occures in all the games.
        4) List(print) the top 5 genres by tokens.
       
     */
    void getPopularGenresByPlatform(Utilities utility,string platform, string fieldname);
    /*
        This function addresses the question 5) in the proposal
     
        parameter @genre is the genre to be analyzed
     
     *  1) get all the games by the given genre
        2) set tokens to count how many games in each year (1984-2015) , for example, if genre "platform" appeared
           15 times in 1984, then the token "1984" should be 15
        3) list all the tokens and do a litter analysis on it
           (increasing or decrease by year? floating? flat?)
     */
    void getGenreOverYear(string genre);
    
    GenreAnalysis(Utilities utility);
    
private:
    Utilities utility;
};
 
#endif /* GenreAnalysis_h */
