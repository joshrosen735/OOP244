/*
 "I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments."
 Name: Dhruv Bipinbhai Patel
 Email: dbpatel31@myseneca.ca
 StudentID: 142572197
 Date: 09/23/20
*/
#ifndef FILE_H
#define FILE_H

namespace sdds
{
bool openFile(const char filename[]);
void closeFile();
bool readTitle(char title[]);
bool readYear(int* year);
bool readMovieRating(char rating[]);
bool readDuration(int* duration);
bool readGenres(char genres[][11]);
bool readConsumerRating(float* rating);
}

#endif
