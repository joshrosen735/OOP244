/*
 "I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments."
 Name: Dhruv Bipinbhai Patel
 Email: dbpatel31@myseneca.ca
 StudentID: 142572197
 Date: 10/26/20
 */
#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();
   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;

      // type conversion operators
      operator bool()const;
      operator int()const;
      operator double()const;

      //Unary operator
      bool operator ~()const;

      //Binary operators
      Account& operator=(int number);
      Account& operator=(Account& another);
      Account& operator+=(double balance);
      Account& operator-=(double balance);
      

      //For helper func
      double getBalance()const;

   };

   //Binary helper func
   double operator+(const Account& helperA, const Account& helperB);
   double operator+=(double& helperC, const Account& helperD);

   

}
#endif // SDDS_ACCOUNT_H_
