//
//  Scores.cpp
//  csc340-midterm
//
//  Created by Jinjian Tan on 10/20/20.
//

#include "Scores.h"
#include <iomanip>
/*
    The empty constructor should be never used in this project since
    we read from.csv file only.
*/
Scores::Scores(){
    gameName = "None";
    platform = "None";
    yearOfRelease = 1900;
    criticScore = 0;
    criticCount = 0;
    userScore = 0.0;
    userCount = 0;
    id = gameName + platform;
}

Scores::Scores(string gameName, string platform, int yearOfRelease, int criticScore, int criticCount, double userScore, int userCount){
    this->gameName = gameName;
    this->platform = platform;
    this->yearOfRelease = yearOfRelease;
    this->criticScore = criticScore;
    this->criticCount = criticCount;
    this->userScore = userScore;
    this->userCount = userCount;
    id = gameName + platform;
}

string Scores::getGameName() const{
    return gameName;
}

string Scores::getPlatform() const{
    return platform;
}

int Scores::getYearOfRelease() const{
    return yearOfRelease;
}

int Scores::getCriticScore() const{
    return criticScore;
}

int Scores::getCriticCount() const{
    return criticCount;
}

double Scores::getUserScore() const{
    return userScore;
}

int Scores::getUserCount() const{
    return userCount;
}

void Scores::printInfo() const{
    cout << setfill('-') << setw(24) << "" << endl;
    cout << "Name: " << gameName << endl;
    cout << "Platform: " << platform << endl;
    cout << "Year of Release: " << yearOfRelease << endl;
    printScoresOnly();
    
}

void Scores::printScoresOnly() const{
    cout << "Critic Score: " << criticScore << endl;
    cout << "Critic Count: " << criticCount << endl;
    cout << "User Score: " << userScore << endl;
    cout << "User Count: " << userCount << endl;
}

//this function act exactly like printScoresOnly()
ostream &operator<<(ostream &os, const Scores scores){
    os << "Critic Score: " << scores.getCriticScore() << endl
       << "Critic Count: " << scores.getCriticCount() << endl
       << "User Score: " << scores.getUserScore() << endl
       << "User Count: " << scores.getUserCount() << endl;
    return os;
}
