/*
 "I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments."
 Name: Dhruv Bipinbhai Patel
 Email: dbpatel31@myseneca.ca
 StudentID: 142572197
 Date: 09/27/20
*/
#include<cstring>
#include<iostream>
#include<cstdio>
using namespace std;
#include"School.h"
#include"File.h"

namespace scl
{
School schools[24];
bool loadSchools()
{
   School cd;
   int num = 0;
   bool ok = true;
   if (openFile("schools.dat")){
      while (ok && num < 24) {
         ok = readCode(cd.c_code) &&
          readExt(&cd.c_ext);
         if (ok) schools[num++] = cd;
      }
      closeFile();
   }
   return num == 24;
}

bool hasContact(const School* cod, const char contact[])
{
    int i=0;
   bool found = false;
   while (!found && cod->c_code[i]) {
      if (strstr(&cod->c_code[i++], contact)) {
         found = true;
      }
   }
   return found;
}

void displayContact(const School* cod)
{
    cout << "416 491 5050 x " <<  cod->c_ext << endl;
}

void displayContactsWithCode(const char contact[]) {
   int i, j=1;
   for (i = 0; i < 24; i++) {
       if (hasContact(&schools[i], contact))
       {
           j=0;
           displayContact(&schools[i]);
      }
   }
   if (j == 1) {
      cout << contact << " School code not found!" << endl;
   }
}
}

