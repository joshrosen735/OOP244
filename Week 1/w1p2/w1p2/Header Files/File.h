/*
 "I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments."
 Name: Dhruv Bipinbhai Patel
 Email: dbpatel31@myseneca.ca
 StudentID: 142572197
 Date: 09/27/20
*/
#ifndef FILE_H
#define FILE_H

namespace scl
{
bool openFile(const char filename[]);
void closeFile();
bool readCode(char code[]);
bool readExt(int* ext);
}

#endif
