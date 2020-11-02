//
//  main.cpp
//  csc340-midterm
//  Print Menu and Main
//  Created by Kami Sawekchim on 10/30/20.
//
#include <iostream>


using namespace std;

void PrintMenu();


void PrintMenu() {
      char option;

   do {
      cout << "What question would you like to ask?" << endl;
      cout << "1 - Based on global/NA/EU/Japan/other video game sales and development, what are the ten most popular video game genres?" << endl;
      cout << "2 - Based on global/NA/EU/Japan/other video game sales and development, what are the ten least popular video game genres?" << endl;
      cout << "3 - What percentage of developers outsource their publishing?" << endl;
      cout << "4 - How many developers use the same publisher?" << endl;
      cout << "5 - For each specific platform, what are the most popular genres of games based on development, sales, user scores, and critic scores? " << endl;
      cout << "6 - No Questions. Quit. " << endl;

      cout << "Choose a number: ";
      cin >> option;

      switch (option) {
      case '1':
         cout << "Based on global/NA/EU/Japan/other video game sales and development, what are the ten most popular video game genres?" << GetMostPopVG() << endl;
         break;

      case '2':
         cout << "Based on global/NA/EU/Japan/other video game sales and development, what are the ten least popular video game genres?" << GetLeastPopVG() << endl;
         break;

      case '3':
         cout << "What percentage of developers outsource their publishing?" << GetDevOutsource() << endl; // please add correct get function
         break;

      case '4':
         cout << "How many developers use the same publisher?" << GetSamePub() << endl; // please add correct get function
         break;

      case '5':
         cout << "For each specific platform, what are the most popular genres of games based on development, sales, user scores, and critic scores? " << GetMostBasedOn());
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



int main() {

   
   PrintMenu();
   return 0;
}