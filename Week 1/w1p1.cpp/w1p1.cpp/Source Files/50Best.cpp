/*
 "I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments."
 Name: Dhruv Bipinbhai Patel
 Email: dbpatel31@myseneca.ca
 StudentID: 142572197
 Date: 09/23/20
*/
#include<iostream>
#include"Movie.h"
using namespace std;
using namespace sdds;

void flushkeys()
{
   while (cin.get() != '\n');
}

bool yes()
{
   char ch = cin.get();
   flushkeys();
   return ch == 'y' || ch == 'Y';
}

int main()
{
   bool done = false;
   char genre[128];
   loadMovies();
   cout << "Welcome to 50 top movies of all times \"genre\" search." << endl << endl;
   while (!done)
   {
      cout << "Enter the movie genre to start the search: ";
      cin >> genre;
      flushkeys();
      displayMoviesWithGenre(genre);
      cout << "Do another search? (Y)es: ";
      done = !yes();
      cout << endl;
   }
   cout << "Goodbye!" << endl;
   return 0;
}
