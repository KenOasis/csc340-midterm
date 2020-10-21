//
//  Game.h
//  csc340-midterm
//
//  Created by Jinjian Tan on 10/20/20.
//

#ifndef Game_h
#define Game_h

#include "Scores.h"
#include "Sales.h"
using namespace std;

class Game{
    public:
        
        Game();
        
        Game(string gameName, string platform, int yearOfRelease, string genre, string publisher, Sales sales, Scores scores, string developer, string rating);
        
        string getGameName() const;
        
        string getPlatform() const;
        
        int getYearOfRelease() const;
        
        string getGenre() const;
        
        string getPublisher() const;
        
        Sales getSales() const;
        
        Scores getScores() const;
        
        string getDeveloper() const;
        
        string getRating()const;
        
        void printInfo() const;
    private:
        string id;
        
        string gameName;
        
        string platform;
        
        int yearOfRelease;
        
        string genre;
        
        string publisher;
        
        Sales sales;
        
        Scores scores;
        
        string developer;
        
        string rating;
        
};

#endif /* Game_h */
