//
//  Utilities.h
//  csc340-midterm
//
//  Created by Jinjian Tan on 10/20/20.
//

#ifndef Utilities_h
#define Utilities_h
#include "Game.h"
#include <vector>
class Utilities{
    public:
    
        int LoadFile(string filepath);
        // Initializing the data
        Utilities();
        
        // Get all the games in a vector
        vector<Game> getAllGames() const;
        

        // Get games from dataset by a given developer
        vector<Game> getGamesByDeveloper(string developer) const;
        
        // Get games from a given collection of Game by a given developer
        vector<Game> getGamesByDeveloper(const vector<Game> gamesCollection, string developer) const;
    
        // Get games from dataset by a given genre
        vector<Game> getGamesByGenre(string genre) const;
        
        // Get games from a given collection of Game by a given genre
        vector<Game> getGamesByGenre(const vector<Game> gamesCollection , string genre) const;

   
        // Get games from dataset by a given year of release
        vector<Game> getGamesByYears(int year) const;
    
        // Get games from a given Game by a given year of release
        vector<Game> getGamesByYears(const vector<Game> gamesCollection, int year) const;

        // Get games from dataset by a given platfrom
        vector<Game> getGamesByPlatform(string platform) const;
        
        // Get games from a given collection of Game by a given platfrom
        vector<Game> getGamesByPlatform(const vector<Game> gamesCollection, string platform) const;
        
        // Get games from dataset by a given publisher
        vector<Game> getGamesByPublisher(string publisher) const;
    
        // Get games from a given collection of Game by a given publisher
        vector<Game> getGamesByPublisher(vector<Game> gamesCollection, string publisher) const;
        
        // Get games from a dataset by a given publihser
        vector<Game> getGamesByRating(string rating) const;
        
        // Get games from a given collection of Game by a given rating
        vector<Game> getGamesByRating(vector<Game> gamesCollection, string rating) const;
    
    // Print out all the info of all the Game in whole dataset
    void printAllGames() const;
    
    // Print a given set of fileds from a given set of Game collection
    // fields is an array of string which respresent the fileds you want to print
    // please check README.md to see the schema.
    // filedNum is the number of fields.
    void printByFields(vector<Game> gameCollection, string fields[], int fieldNum) const;
    private:
        vector<Game> games;
    
};

#endif /* Utilities_h */
