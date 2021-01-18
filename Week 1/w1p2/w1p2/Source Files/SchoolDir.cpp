/*
 "I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments."
 Name: Dhruv Bipinbhai Patel
 Email: dbpatel31@myseneca.ca
 StudentID: 142572197
 Date: 09/27/20
*/
#include<iostream>
#include<cstring>
#include"School.h"

using namespace std;
using namespace scl;

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

int main( )
{
    bool done = false;
    char codes[25];
    loadSchools( );
    cout << "Seneca School Extension search." << endl << endl;
    while (!done)
    {
       cout << "Enter the School code: ";
       cin >> codes;
       flushkeys();
       displayContactsWithCode(codes);
       cout << "Do another search? (Y)es: ";
       done = !yes();
       cout << endl;
    }
    cout << "Goodbye!" << endl;
    return 0;
}
