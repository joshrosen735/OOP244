/*
 "I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments."
 Name: Dhruv Bipinbhai Patel
 Email: dbpatel31@myseneca.ca
 StudentID: 142572197
 Date: 09/23/20
*/
#include<cstring>
#include<iostream>
#include<cstdio>
using namespace std;
#include"File.h"

namespace sdds
{
FILE* fptr;

bool openFile(const char filename[])
{
   fptr = fopen(filename, "r");
   return fptr != NULL;
}

void closeFile()
{
   if (fptr) fclose(fptr);
}

bool readTitle(char title[])
{
   return fscanf(fptr, "%[^(](", title) == 1;
}

bool readYear(int* year)
{
   return fscanf(fptr, "%d)", year) == 1;
}

bool readMovieRating(char rating[])
{
   return fscanf(fptr, " %[^|]|", rating) == 1;
}

bool readDuration(int* duration)
{
   return fscanf(fptr, "%d|", duration) == 1;
}

bool readGenres(char genre[][11])
{
   char genres[256];
   int gi = 0; //genres index;
   int i = 0;// genre[i] index
   int j = 0;// genre[i][j] index
   bool res = fscanf(fptr, " %[^|]|", genres);
   if (res) { //spreading csv to array of strings
      res = false;
      while (genres[gi]) {
         if (genres[gi] != ',') {
            genre[i][j++] = genres[gi++];
            res = true;
         }
         else {
            genre[i][j] = '\0';
            i++;
            gi++;
            j = 0;
         }
      }
   }
   genre[i++][j] = '\0';
   genre[i][0] = '\0'; // NULL terminating the array of strings
   return res;
}

bool readConsumerRating(float* rating)
{
   return fscanf(fptr, "%f\n", rating) == 1;
}
}
