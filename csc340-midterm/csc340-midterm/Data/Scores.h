//
//  Scores.h
//  csc340-midterm
//
//  Created by Jinjian Tan on 10/20/20.
//

#ifndef Scores_h
#define Scores_h
#include <iostream>
#include <string>
using namespace std;

class Scores{
    public:
        // constructors
        Scores();
    
        Scores(string gameName, string platform,int yearOfRelease, int criticScore, int criticCount, double userScore, int userCount);
        
        
        //Accessors
        string getGameName() const;
        
        string getPlatform() const;
        
        int getYearOfRelease() const;
        
        int getCriticScore() const;
        
        int getCriticCount() const;
        
        double getUserScore() const;
        
        int getUserCount() const;
    
        void printInfo() const;
    
        void printScoresOnly() const;
        
        friend ostream &operator<<(ostream &os, const Scores scores);
    
    private:
        string id;
        string gameName;
        string platform;
        int yearOfRelease;
        int criticScore;
        int criticCount;
        double userScore;
        int userCount;
};
#endif /* Scores_h */
