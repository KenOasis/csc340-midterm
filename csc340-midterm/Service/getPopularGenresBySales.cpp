#include "GenreAnalysis.h"
#include "Game.h"
#include "Sales.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

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
		if (i == 0) {
			genres.push_back(games[i].getGenre());
			count.push_back(1);
			totalSales.push_back(games[i].getSales().getGlobalSales());
		}
		else {
			for (int k = 0; k < genres.size(); k++) {
				if (genres[k] == games[i].getGenre()) {
					count[k]++;
					totalSales[k] += games[i].getSales().getGlobalSales();
				}
				//!!!! the else if branch is always exectued since k will always add up to genere.size() - 1;
				// also, we need to skip the genre "Misc" since this kind is miscellaneous.
				else if (k == (genres.size() - 1)) {
					notIncluded = true;
				}
			}
			if (notIncluded) {
				genres.push_back(games[i].getGenre());
				count.push_back(1);
				totalSales.push_back(games[i].getSales().getGlobalSales());
				notIncluded = false;
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

	for (int i = 0; i < 5; i++) {
		cout << (i + 1) << ". " << genres[i] << "  $" << totalSales[i] << endl;
	}
}
