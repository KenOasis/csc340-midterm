//
//  main.cpp
//  csc340-midterm
//  Print Menu and Main
//  Created by Kami Sawekchim on 10/30/20.
//
#include <iostream>
#include "GenreAnalysis.h"
#include "DeveloperAnalyis.h"

using namespace std;

void PrintMenu();


void PrintMenu() {
      char option;

   do {
      cout << "What question would you like to ask?" << endl;
      cout << "A - Based on global/NA/EU/Japan/other video game sales and development, what are the ten most popular video game genres?" << endl;
      cout << "B - What percentage of developers outsource their publishing?" << endl;
      cout << "C - For a given developer, what are the most popular games they developed (by scores or by sales)" << endl;
      cout << "D - For each specific platform, what are the most popular genres of games based on sales or user scores? " << endl;
      cout << "F -  How has the popularity of certain genres changed over time? Which ones have grown? Which ones have fallen in popularity?" << endl;
      cout << "Q - No Questions. Quit. " << endl;

      cout << "Choose a letter: ";
      cin >> option;

      switch (option) {
      case 'A':
         cout << "Based on global/NA/EU/Japan/other video game sales and development, what are the ten most popular video game genres?" << getPopularGenresBySales(vector<Game> games) << endl;
         break;

      case 'B':
         cout << " What percentage of developers outsource their publishing?" << getPercentageDevByPub() << endl;
         break;

      case 'C':
         cout << "For a given developer, what are the most popular games they developed (by scores or by sales)" << getPopularGamesByDeveloper(string developer string fieldname)<< endl; 
         break;

      case 'D':
         cout << "For each specific platform, what are the most popular genres of games based on sales or user scores? " << getPopularGenresByPlaform(string platform, string fieldname);
         break;

      case 'F':
         cout << "How has the popularity of certain genres changed over time? Which ones have grown? Which ones have fallen in popularity?" << getGenereOverYear(string genre);
         break;

      case 'Q':        
         cout << "No Questions. Quit."  << endl;
         break;

     default:
         cout << "option unknown." << endl;
         break;
   }
   }while (option != 'Q');

}



int main() {

   
   PrintMenu();
   return 0;
}