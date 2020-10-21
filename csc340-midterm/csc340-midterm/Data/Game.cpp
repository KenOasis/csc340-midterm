//
//  Game.cpp
//  csc340-midterm
//
//  Created by Jinjian Tan on 10/20/20.
//

#include "Game.h"
#include <iomanip>

/*
    The empty constructor should be never used in this project since
    we read from.csv file only.
*/
Game::Game(){
    gameName = "None";
    platform = "None";
    yearOfRelease = 1900;
    genre = "None";
    publisher = "None";
    developer = "None";
    rating = "None";
    id = gameName + platform;
}

Game::Game(string gameName, string platform, int yearOfRelease, string genre, string publisher, Sales sales, Scores scores, string developer, string rating){
    this->gameName = gameName;
    this->platform = platform;
    this->yearOfRelease = yearOfRelease;
    this->genre = genre;
    this->publisher = publisher;
    this->sales = sales;
    this->scores = scores;
    this->developer = developer;
    this->rating = rating;
    id = gameName + platform;
}

string Game::getGameName() const{
    return gameName;
}

string Game::getPlatform() const{
    return platform;
}

int Game::getYearOfRelease() const{
    return yearOfRelease;
}

string Game::getGenre() const{
    return genre;
}

string Game::getPublisher() const{
    return publisher;
}

Sales Game::getSales() const{
    return sales;
}

Scores Game::getScores() const{
    return scores;
}

string Game::getDeveloper() const{
    return developer;
}

string Game::getRating() const{
    return rating;
}

void Game::printInfo() const{
    cout << setfill('-') << setw(24) << "" << endl;
    cout << "Name: " << gameName << endl;
    cout << "Platform: " << platform << endl;
    cout << "Year of Release: " << yearOfRelease << endl;
    cout << "Genre: " << genre << endl;
    cout << "Publisher: " << publisher << endl;
    sales.printSalesOnly();
    scores.printScoresOnly();
    cout << "Developer: " << developer << endl;
    cout << "Rating: " << rating << endl;
}

//This function is act exactly as printInfo()
ostream &operator<<(ostream &os, const Game game){
    cout << setfill('-') << setw(24) << "" << endl
         << "Name: " << game.getGameName() << endl
         << "Platform: " << game.getPlatform() << endl
         << "Year of Release: " << game.getYearOfRelease() << endl
         << "Genre: " << game.getGenre() << endl
         << "Publisher: " << game.getPublisher()<< endl
         << game.getSales()
         << game.getScores()
         << "Developer: " << game.getDeveloper() << endl
         << "Rating: " << game.getRating() << endl;
    return os;
}
