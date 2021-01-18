/*
 "I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments."
 Name: Dhruv Bipinbhai Patel
 Email: dbpatel31@myseneca.ca
 StudentID: 142572197
 Date: 10/04/20
*/
// Workshop 2:
// Version: 0.9
// Date: 09/25/2020
// Author: Fardad Soleimanloo
// Reviewed by: Michael Huang
// Description:
// This file tests the DIY section of your workshop
// Do not modify your code
/////////////////////////////////////////////
#include "Account.h"
using namespace sdds;
int main() {
   if (load("accounts.csv")) {
      display();
   }
   deallocateMemory();
   return 0;
}
