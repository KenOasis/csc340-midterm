//
//  main.cpp
//  csc340-midterm
//  Print Menu and Main
//  Created by Kami Sawekchim on 10/30/20.
//
#include "DeveloperAnalysis.h"
#include "GenreAnalysis.h"
#include <iostream>
using namespace std;

static string selectGenre();
static void PrintMenu(Utilities);
int main() {
   Utilities utility;
   string filepath = "/Users/jinjiantan/Git/csc340-midterm/csc340-midterm/Data/data.csv";
   utility.LoadFile(filepath);

   PrintMenu(utility);
    
   return 0;
}

static void PrintMenu(Utilities utility) {
      char option;
      vector<Game> games = utility.getAllGames();
      GenreAnalysis genreAnalysis(utility);
      DeveloperAnalysis developAnalysis(utility);
      do {
          cout << "What question would you like to ask?" << endl;
          cout << "1 - What's the most popular video game genre based on sales data?" << endl;
          cout << "2 - What percentage of developers outsource their publishing?" << endl;
          cout << "3 - For a given developer, what is the most popular games they developed (by scores or by sales)" << endl;
          cout << "4 - For each specific platform (Game console: N64, GB, PS, etc.), what are the most popular genres of games based on sales or scores? " << endl;
          cout << "5 - How has the popularity of certain genres changed over time? Which ones have grown? Which ones have fallen in popularity? " << endl;
          cout << "6 - No Questions. Quit. " << endl;
          cout << "Choose a number: ";
          cin >> option;

          switch (option) {
              case '1':
              genreAnalysis.getPopularGenresBySales(games);
              break;

              case '2':
              developAnalysis.getPercentageDevByPub();
              break;

              case '3':
              {
                  string developer;
    
                  int option;
                  cout << "Please enter the developer:" << endl;
                  cin >> developer;
                  cout << "Please select:" << endl;
                  cout << "1 - Global Sales" << endl;
                  cout << "2 - User Score" << endl;
                  cin >> option;
                  if(option == 1){
                      developAnalysis.getPopularGamesByDeveloper(developer, "sales");
                  }else if(option == 2){
                      developAnalysis.getPopularGamesByDeveloper(developer, "userScore");
                  }else{
                      cout << "Wrong options" << endl;
                  }
              }
              break;
                
                
              case '4':
              cout <<"4" << endl;
              break;

              case '4':
              cout << "4" << endl;
              break;

              case '5':
              {
                  string genre;
                  cout <<"What genre do you want to check?" << endl;
                  genre = selectGenre();
                  genreAnalysis.getGenreOverYear(genre);
              }
              break;

              case '6':
              cout << "No Questions. Quit."  << endl;
              break;

              default:
              cout << "option unknown." << endl;
              break;
          }
   }while (option != '6');
}
// Print the sub-menu and get genre from user selection.
static string selectGenre(){
    string genre;
    int option;
    cout << "Please selet one of the genre:" << endl;
    cout << "1 - Action" << endl;
    cout << "2 - Adventure" << endl;
    cout << "3 - Fighting" << endl;
    cout << "4 - Platform" << endl;
    cout << "5 - Puzzle" << endl;
    cout << "6 - Racing" << endl;
    cout << "7 - Role-Playing" << endl;
    cout << "8 - Shooter" << endl;
    cout << "9 - Simulation" << endl;
    cout << "10 - Sports" << endl;
    cout << "11 - Strategy" << endl;
    cout << "other - Misc" << endl;
    cin >> option;
    switch (option){
        case 1:
            genre = "Action";
            break;
        case 2:
            genre = "Adventure";
            break;
        case 3:
            genre = "Fighting";
            break;
        case 4:
            genre = "Platform";
            break;
        case 5:
            genre = "Puzzle";
            break;
        case 6:
            genre = "Racing";
            break;
        case 7:
            genre = "Role-Playing";
            break;
        case 8:
            genre = "Shooter";
            break;
        case 9:
            genre = "Simulation";
            break;
        case 10:
            genre = "Sports";
            break;
        case 11:
            genre = "Strategy";
            break;
        default:
            genre = "Misc";
            break;
    }
    return genre;
}
