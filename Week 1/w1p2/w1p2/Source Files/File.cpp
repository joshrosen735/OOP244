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
#include"File.h"

namespace scl
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

bool readCode(char code[]) {
    return fscanf(fptr, "%s ", code) == 1 ;
}

bool readExt(int* ext)
{
   return fscanf(fptr, "%d\n", ext) == 1;
}
}

