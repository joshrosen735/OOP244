/*
 "I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments."
 Name: Dhruv Bipinbhai Patel
 Email: dbpatel31@myseneca.ca
 StudentID: 142572197
 Date: 10/04/20
*/
#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_

#define DATAFILE "accounts.csv"
namespace sdds {
   struct Account {
      char* m_accountNumber;
      float m_balance;
   };
   void sort();
   bool load(const char filename[]);
   bool load(Account &accounts);
void display(Account& accounts);
void display(void);
void deallocateMemory(void);
}
#endif

