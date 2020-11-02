//
//  getPopularGenresBySales.cpp
//  csc340-midterm
//

#include "GenreAnalysis.h"
#include "Utilities.h"
#include <iomanip>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

// Created by Francis Ranallo
// Test and modifed by Jinjian Tan
void GenreAnalysis::getPopularGenresBySales(vector<Game> games)
{/*sort games based on sales
 go through top 50% of games
 add new genre when encountered or increment number of games with that genre by one
 also total the sales based on genre
 then print out top 5 genres by number of games of that genre*/
    
//sort
    Game game;
    int j;
    for (int i = 1; i < games.size(); i++) {//insertion sort games by sales in descending order
        game = games[i];
        j = i - 1;
        while (j >= 0 && ((games[j].getSales().getGlobalSales()) < (game.getSales().getGlobalSales()))) {
            games[j + 1] = games[j];
            j--;
        }
        games[j + 1] = game;
    }

//go through top 50% of games
    vector<string> genres;
    vector<int> count;
    vector<double> totalSales;

    bool notIncluded = false;
    for (int i = 0; i < (games.size() / 2); i++) {
        if(games[i].getGenre() != "Misc"){ // skip genre "Misc"
            if (i == 0) {
                genres.push_back(games[i].getGenre());
                count.push_back(1);
                totalSales.push_back(games[i].getSales().getGlobalSales());
            }
            else {
                int k; //fixed
                for (k = 0; k < genres.size(); k++) {
                    // if genre exists then counter plus one
                    if (genres[k] == games[i].getGenre()) {
                        count[k]++;
                        totalSales[k] += games[i].getSales().getGlobalSales();
                        break;
                    }
                }
                // if genre does not exist then add a new genre
                if (k == (genres.size())) {
                    notIncluded = true;
                }
                if (notIncluded) {
                    genres.push_back(games[i].getGenre());
                    count.push_back(1);
                    totalSales.push_back(games[i].getSales().getGlobalSales());
                    notIncluded = false;
                }
            }
        }
    }
    

//sort top genres in decreasing order by amount of occurences
    int num;
    string genre;
    double sales;
    for (int i = 1; i < genres.size(); i++) {
        num = count[i];
        genre = genres[i];
        sales = totalSales[i];
        j = i - 1;
        while (j >= 0 && (count[j] < num)) {
            count[j + 1] = count[j];
            genres[j + 1] = genres[j];
            totalSales[j + 1] = totalSales[j];
            j--;
        }
        count[j + 1] = num;
        genres[j + 1] = genre;
        totalSales[j + 1] = sales;
    }
    cout << setw(15) << left << "Genre" << "|";
    cout << setw(15) << left << "Games #" << "|";
    cout << setw(15) << left << "Sales Total(millions)" << endl;
    cout << setfill('-') << setw(47) << "" << endl;
    cout << setfill(' ');
    for (int i = 0; i < 5; i++) {
        cout << setw(15) << left << genres[i] << "|";
        cout << setw(15) << left << count[i]  << "|";
        cout << setw(15) << left << totalSales[i] << endl;
    }
    cout << setfill('-') << setw(47) << endl;
}

GenreAnalysis::GenreAnalysis(){
    
}
