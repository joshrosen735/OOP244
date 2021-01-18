/*
 "I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments."
 Name: Dhruv Bipinbhai Patel
 Email: dbpatel31@myseneca.ca
 StudentID: 142572197
 Date: 10/04/20
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cstring>
#include "Account.h"
#include "File.h"
using namespace std;
namespace sdds {
   int noOfAccounts;
   Account* accounts = nullptr;


   void sort() {
      int i, j;
      Account temp;
      for (i = noOfAccounts - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (accounts[j].m_balance > accounts[j + 1].m_balance) {
               temp = accounts[j];
               accounts[j] = accounts[j + 1];
               accounts[j + 1] = temp;
            }
         }
      }
   }

      bool load(Account &accounts) {
      bool ok = false;
      char number[10];
          if (read(number)) {
              accounts.m_accountNumber = new char[strlen(number) + 1];
              strcpy(accounts.m_accountNumber, number);
              read(accounts.m_balance);
              ok = true;
      }
      return ok;
   }
   bool load(const char filename[]) {
      bool ok = false;
      int i = 0;
      if (openFile(DATAFILE)) {
          noOfAccounts = noOfRecords();
          accounts = new Account[noOfAccounts];
          for(i=0;i<noOfAccounts;i++)
          {
              load(accounts[i]);
          }
         if (i != noOfAccounts){
             cout << "Error: incorrect number of records read; the data is possibly corrupted!" << endl;
         }
         else {
            ok = true;
         }
         closeFile();
      }
      else {
         cout << "Could not open data file: " << DATAFILE<< endl;
      }
      return ok;
   }
void display(Account& accounts)
{
    cout << accounts.m_accountNumber << "  " << accounts.m_balance << endl;
}

void display(void)
{
    int i,j;
    sort();
    cout << "Account#: " << "Balance" << endl;
    for(i=0,j=1;i<noOfAccounts;i++)
    {
        cout << j++ << ": ";
        display(accounts[i]);
    }
}

void deallocateMemory(void)
{
    int i;
    for(i=0;i<noOfAccounts;i++)
    {
        delete [] accounts[i].m_accountNumber;
        accounts[i].m_accountNumber = nullptr;
    }
    delete[] accounts;
    accounts = nullptr;
}
}

