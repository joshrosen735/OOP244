/*
 "I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments."
 Name: Dhruv Bipinbhai Patel
 Email: dbpatel31@myseneca.ca
 StudentID: 142572197
 Date: 09/27/20
*/
#ifndef School_H
#define School_H

namespace scl
{
struct School
{
   char c_code[25];
   int c_ext;
};

bool loadSchools();
bool hasContact(const School* cod, const char contact[]);
void displayContact(const School* cod);
void displayContactsWithCode(const char contact[]);
}

#endif
