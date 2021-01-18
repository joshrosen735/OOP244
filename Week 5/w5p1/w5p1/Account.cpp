/*
 "I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments."
 Name: Dhruv Bipinbhai Patel
 Email: dbpatel31@myseneca.ca
 StudentID: 142572197
 Date: 10/26/20
 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
void Account::setEmpty() {
    m_number = -1;
    m_balance = 0.0;
}

// New account
Account::Account() {
    m_number = 0;
    m_balance = 0.0;
}

// Valid
Account::Account(int number, double balance) {
    setEmpty();
    if (number >= 10000 && number <= 99999
        && balance > 0) {
        m_number = number;
        m_balance = balance;
    }
}

std::ostream& Account::display() const{
    if (*this) {
        cout << "Acc#: ";
        if (~(*this))
            cout << "Not Set";
        else
            cout << " " << m_number << " ";
        cout << ", Balance: ";
        cout.width(12);
        cout.precision(2);
        cout.setf(ios::right);
        cout.setf(ios::fixed);
        cout << m_balance;
        cout.unsetf(ios::right);
        // I (Fardad) removed the "return cout", this was a mistake
        // (copied and pasted by mistake)
        // and had no effect to the execution of the program.
        // As mentioned before we should have only
        // one return statement in a function.
    }
    else {
        cout << "Invalid Account";
    }
    return cout;
}


// type conversion operators

Account::operator bool()const
{
    bool status = false;
    if (m_number !=-1)
    {
        status = true;
    }
    return status;
}


Account::operator int()const
{
    return m_number;
}

Account::operator double()const
{
    return m_balance;
}

//Unary operator
bool Account::operator ~()const
{
    bool status = false;
    if (m_number == 0)
    {
        status= true;
    }
    return status;
}

Account& Account::operator=(int number)
{
    if (number < 10000 || number > 99999)
    {
        setEmpty();
    }
    else if(m_number==0)
    {
        m_number = number;
    }
    return *this;
}

Account& Account::operator=(Account& another)
{
    if (m_number != -1)
    {
        if (another.m_number >= 10000 && another.m_number <= 99999)
        {
            m_balance = another.m_balance;
            another.m_balance = 0.0;
        }
    }
    return *this;
}

Account& Account::operator+=(double balance)
{
    if (balance < 0 || m_balance < 0)
    {
        
    }
    else
    {
        m_balance += balance;
    }
    return *this;
}

Account& Account::operator-=(double balance)
{
    
    if (m_balance < 0 || balance < 0 || m_balance < balance)
    {
    
    }
    else
    {
        m_balance -= balance;
    }
    return *this;
}

//For helper func
double Account::getBalance()const
{
    return m_balance;
}

//Binary helper func
double operator+(const Account& helperA, const Account& helperB)
{
    
    if (helperA.getBalance() < 0 || helperB.getBalance() < 0)
    {
        return 0.0;
    }
    return (helperA.getBalance() + helperB.getBalance());
}

double operator+=(double& helperC, const Account& helperD)
{
    helperC += helperD.getBalance();
    return helperC;
}

}
