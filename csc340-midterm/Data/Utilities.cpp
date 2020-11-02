//
//  Utilities.cpp
//  csc340-midterm
//
//  Created by Jinjian Tan on 10/20/20.
//


#include "Utilities.h"
#include <fstream>

//helper method to tokenize the string.
const vector<string> spilt(const string &s, const char &c){
    string buffer("");
    vector<string> tokens;
    bool canPush = true;
    for(int i = 0; i < s.length(); ++i){
        if(s.at(i) != c){
            buffer += s.at(i);
            //in some column they may cotain ","(same as delimiter in their description, use this to include the ","
            //for exampale, row 950 has the game name "Hey you, Pikachu!".
            if(s.at(i) == '"'){
                canPush = (!canPush);
            }
        }else if( (s.at(i) == c) && canPush){
            tokens.push_back(buffer);
            buffer = "";
        }else{
            buffer += s.at(i);
        }
    }
    if(buffer != "" ){
        tokens.push_back(buffer);
    }
    return tokens;
}

//Builder function from tokens to a Game object
Game gameBuilder(vector<string> tokens){
    string gameName;
    string platform;
    int yearOfRelease;
    string genre;
    string publisher;
    double NASales;
    double EUSales;
    double JPSales;
    double otherSales;
    double globalSales;
    int criticScore;
    int criticCount;
    double userScore;
    int userCount;
    string developer;
    string rating;
    
    gameName = tokens.at(0);
    platform = tokens.at(1);
    if(tokens.at(2) == "N/A"){
        yearOfRelease = -1;
    }else{
        yearOfRelease = stoi(tokens.at(2));
    }
    genre = tokens.at(3);
    publisher = tokens.at(4);
    NASales = stod(tokens.at(5));
    EUSales = stod(tokens.at(6));
    JPSales = stod(tokens.at(7));
    otherSales = stod(tokens.at(8));
    globalSales = stod(tokens.at(9));
    Sales sales(gameName, platform, yearOfRelease, NASales, EUSales, JPSales, otherSales, globalSales);
    // if the scores column is empty or tbd, set it to -1.
    if(tokens.at(10) == ""){
        criticScore  = -1;
    }else{
        criticScore = stoi(tokens.at(10));
    }
    if(tokens.at(11) == ""){
        criticCount = -1;
    }else{
        criticCount = stoi(tokens.at(11));
    }
    if( (tokens.at(12) == "") || (tokens.at(12) == "tbd")){
        userScore = -1.0;
    }else{
        userScore = stod(tokens.at(12));
    }
    
    if( (tokens.at(13) == "")){
        userCount = -1;
    }else{
        userCount = stoi(tokens.at(13));
    }
    developer = tokens.at(14);
    rating = tokens.at(15);
    Scores scores(gameName, platform, yearOfRelease, criticScore, criticCount, userScore, userCount);
    Game game(gameName, platform, yearOfRelease, genre, publisher, sales, scores, developer, rating);
    return game;
}

int Utilities::LoadFile(string filename){
    ifstream inFS;
    inFS.open(filename);
    if(!inFS.is_open()){
        cout << "Could not open the file " << filename << endl;
        return -1;
    }
    
    cout << "Starting read from file: " << filename << endl;
    
    string line;
    int numOfEntriesRead = 0;
    char delimiter = ',';
    // skip title column
    getline(inFS, line);
    while(!inFS.eof()){
        getline(inFS, line);
        if(!inFS.fail()){
            vector<string> tokens = spilt(line, delimiter);
            Game game = gameBuilder(tokens);
            games.push_back(game);
            numOfEntriesRead++;
        }
    }
    inFS.close();
    cout<< "Reading is finished for file: " << filename << endl;
    cout<< "In total, " << numOfEntriesRead << " entries have read." << endl;
    return 0;
}

Utilities::Utilities(){
    cout << "Utilities initialized." << endl;
}


vector<Game> Utilities::getAllGames() const{
    return games;
}

vector<Game> Utilities::getGamesByDeveloper(string developer) const{
    vector<Game> gamesByDeveloper;
    if(!games.empty()){
        for(int i = 0; i < games.size(); ++i){
            if(games.at(i).getDeveloper() == developer){
                gamesByDeveloper.push_back(games.at(i));
            }
        }
    }
    return gamesByDeveloper;
}

vector<Game> Utilities::getGamesByDeveloper(const vector<Game> gamesCollection, string developer) const{
    vector<Game> gamesByDeveloper;
    if(!gamesCollection.empty()){
        for(int i = 0; i < gamesCollection.size(); ++i){
            if(gamesCollection.at(i).getDeveloper() == developer)
                gamesByDeveloper.push_back(gamesCollection.at(i));
        }
    }
    return gamesByDeveloper;
}

vector<Game> Utilities::getGamesByGenre(string genre) const {
    vector<Game> gamesByGenre;
    if(!games.empty()){
        for(int i = 0; i < games.size(); ++i){
            if(games.at(i).getGenre() == genre){
                gamesByGenre.push_back(games.at(i));
            }
        }
    }
    return gamesByGenre;
}

vector<Game> Utilities::getGamesByGenre(const vector<Game> gamesCollection, string genre) const {
    vector<Game> gamesByGenre;
    if(!gamesCollection.empty()){
        for(int i = 0; i < gamesCollection.size(); ++i){
            if(gamesCollection.at(i).getGenre() == genre){
                gamesByGenre.push_back(gamesCollection.at(i));
            }
        }
    }
    return gamesByGenre;
}

vector<Game> Utilities::getGamesByYears(int year) const{
    vector<Game> gamesByYears;
    if(!games.empty()){
        for(int i = 0; i < games.size(); ++i){
            if(games.at(i).getYearOfRelease() == year){
                gamesByYears.push_back(games.at(i));
            }
        }
    }
    return gamesByYears;
}

vector<Game> Utilities::getGamesByYears(const vector<Game> gamesCollection, int year) const{
    vector<Game> gamesByYears;
    if(!gamesCollection.empty()){
        for(int i = 0; i < gamesCollection.size(); ++i){
            if(gamesCollection.at(i).getYearOfRelease() == year){
                gamesByYears.push_back(gamesCollection.at(i));
            }
        }
    }
    return gamesByYears;
}
vector<Game> Utilities::getGamesByPlatform(string platform) const{
    vector<Game> gamesByPlatform;
    if(!games.empty()){
        for(int i = 0; i < games.size(); ++i){
            if(games.at(i).getPlatform() == platform){
                gamesByPlatform.push_back(games.at(i));
            }
        }
    }
    return gamesByPlatform;
}

vector<Game> Utilities::getGamesByPlatform(vector<Game> gamesCollection, string platform) const{
    vector<Game> gamesByPlatform;
    if(!gamesCollection.empty()){
        for(int i = 0; i < gamesCollection.size(); ++i){
            if(gamesCollection.at(i).getPlatform() == platform){
                gamesByPlatform.push_back(gamesCollection.at(i));
            }
        }
    }
    return gamesByPlatform;
}

vector<Game> Utilities::getGamesByPublisher(string publisher) const{
    vector<Game> gamesByPublisher;
    if(!games.empty()){
        for(int i = 0; i < games.size(); ++i){
            if(games.at(i).getPublisher() == publisher){
                gamesByPublisher.push_back(games.at(i));
            }
        }
    }
    return gamesByPublisher;
}

vector<Game> Utilities::getGamesByPublisher(vector<Game> gamesCollection, string publisher) const{
    vector<Game> gamesByPublisher;
    if(!gamesCollection.empty()){
        for(int i = 0; i < gamesCollection.size(); ++i){
            if(gamesCollection.at(i).getPublisher() == publisher){
                gamesByPublisher.push_back(gamesCollection.at(i));
            }
        }
    }
    return gamesByPublisher;
}

vector<Game> Utilities::getGamesByRating(string rating) const{
    vector<Game> gamesByRating;
    if(!games.empty()){
        for(int i = 0; i < games.size(); ++i){
            if(games.at(i).getRating() == rating){
                gamesByRating.push_back(games.at(i));
            }
        }
    }
    return gamesByRating;
}

vector<Game> Utilities::getGamesByRating(vector<Game> gamesCollection, string rating) const{
    vector<Game> gamesByRating;
    if(!gamesCollection.empty()){
        for(int i = 0; i < gamesCollection.size(); ++i){
            if(gamesCollection.at(i).getRating() == rating)
                gamesByRating.push_back(gamesCollection.at(i));
        }
    }
    return gamesByRating;
}
void Utilities::printAllGames() const{
    int i;
    for(i = 0; i < games.size(); ++i){
        cout << games.at(i);
    }
    cout << "In total, " << i << " games have been listed." << endl;
}
// helper method to compare two string ignoring the case
bool equalIgnoreCase(string s1, string s2){
    unsigned long size = s1.size();
    if(s2.size() != size){
        return false;
    }
    for(unsigned long i = 0; i < size; ++i){
        if(tolower(s1[i]) != tolower(s2[i])){
            return false;
        }
    }
    return true;
}
void printGameByFields(Game game, string fields[],int fieldNum ) {
    cout << setfill('-') << setw(24) << "" << endl;
    for(int i = 0; i < fieldNum; ++i){
        if(equalIgnoreCase(fields[i], "Name")){
            cout << "Name: " << game.getGameName() << endl;
        }else if(equalIgnoreCase(fields[i], "Platform")){
            cout << "Platform: " << game.getPlatform() << endl;
        }else if(equalIgnoreCase(fields[i], "YearOfRelease")){
            cout << "Year of Release: " << game.getYearOfRelease() << endl;
        }else if(equalIgnoreCase(fields[i], "Genre")){
            cout << "Genre: " << game.getGenre() << endl;
        }else if(equalIgnoreCase(fields[i], "Publisher")){
            cout << "Publisher: " << game.getPublisher() << endl;
        }else if(equalIgnoreCase(fields[i], "EUSales")){
            cout << "Euro sales: " << game.getSales().getEUSales() << endl;
        }else if(equalIgnoreCase(fields[i], "JPSales")){
            cout << "Japan sales: " << game.getSales().getJPSales() << endl;
        }else if(equalIgnoreCase(fields[i], "NASales")){
            cout << "North America sales: " << game.getSales().getNASales() << endl;
        }else if(equalIgnoreCase(fields[i], "OtherSales")){
            cout << "Other area sales: " << game.getSales().getOtherSales() << endl;
        }else if(equalIgnoreCase(fields[i], "GlobalSales")){
            cout << "Global sales(Total): " << game.getSales().getGlobalSales() << endl;
        }else if(equalIgnoreCase(fields[i], "CriticScore")){
            cout << "Critic score: " << game.getScores().getCriticScore() << endl;
        }else if(equalIgnoreCase(fields[i], "CriticCount")){
            cout << "Critic count: " << game.getScores().getCriticCount() << endl;
        }else if(equalIgnoreCase(fields[i], "UserScore")){
            cout << "Critic count: " << game.getScores().getUserScore() << endl;
        }else if(equalIgnoreCase(fields[i], "UserCount")){
            cout << "User count: " << game.getScores().getUserCount() << endl;
        }else if(equalIgnoreCase(fields[i], "Developer")){
            cout << "Developer: " << game.getDeveloper() << endl;
        }else if(equalIgnoreCase(fields[i], "Rating")){
            cout << "Rating: " << game.getRating() << endl;
        }else if(equalIgnoreCase(fields[i], "All")){
            cout << game << endl;
        }else{
            cout << "Wrong Filed Names as " << fields[i] << ", please correct it" << endl;
        }
    }
}
void Utilities::printByFields(vector<Game> gameCollection, string fields[], int fieldNum) const{
    if(fieldNum != 0){
        int i;
        for(i = 0; i < gameCollection.size(); ++i){
            printGameByFields(gameCollection.at(i), fields, fieldNum);
        }
        cout << "In total, " << i << " games have been listed." << endl;
    }
}


    
