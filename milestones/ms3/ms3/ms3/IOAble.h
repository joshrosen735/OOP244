/* Citation and Sources...
 Final Project Milestone 3
 Module: IOAble
 Filename: IOAble.h
 Version 1.0
 Author    Dhruv Bipinbhai Patel
 Revision History
 -----------------------------------------------------------
 Date        Reason
 2020/11/11  Preliminary release
 2020/11/11  Debugged DMA
 -----------------------------------------------------------
 I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.
 -----------------------------------------------------------*/

#ifndef IOAble_hpp
#define IOAble_hpp

#include <stdio.h>
#include<fstream>
#include <iostream>
using namespace std;
namespace sdds{
// IOAble class

class IOAble {
    
    // All Required pure virtual functions
    
public:
    
    /*
     csvWrite function
     */
    
    virtual ostream& csvWrite(ostream&) const = 0;
    
    /*
     csvRead function
     */
    
    virtual istream& csvRead(istream&) = 0;
    
    /*
     write function
     */
    
    virtual ostream& write(ostream&) const = 0;
    
    /*
     read function
     */
    
    virtual istream& read(istream&) = 0;
    
    /*
     virtual destructor
     */
    
    virtual ~IOAble() = 0;
};

// Overloading extraction & insertion operator

istream& operator>>(istream& in, IOAble& obj);

ostream& operator<<(ostream& out, IOAble& obj);
}

#endif /* IOAble_hpp */
