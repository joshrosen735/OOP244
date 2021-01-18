/* Citation and Sources...
 Final Project Milestone 3
 Module: Time
 Filename: Time.cpp
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

#define _CRT_SECURE_NO_WARNINGS
#include "Time.h"
#include "utils.h"
#include<iostream>
#include<iomanip>
using namespace std;
namespace sdds {

Time& Time::reset(){
    m_min = getTime();
    return *this;
}

Time::Time(unsigned int min){
    m_min = min;
}

std::ostream& Time::write(ostream& ostr)const {
    ostr << setfill('0') << setw(2) << right << m_min/60 << ":" << setw(2) << m_min % 60;
    ostr.unsetf(ios::right);
    return ostr;
}

std::istream& Time::read(std::istream& istr){
    int hour = 0, mins = 0;
    char col = 'X';
    istr >> hour >> col;
    if (col != ':')
        istr.setstate(ios::failbit);
    else
    {
        istr >> mins;
        m_min = hour * 60 + mins;
    }
    return istr;
}

Time::operator int()const{
    return m_min;
}

Time& Time::operator *= (int val){
    m_min *= val;
    return *this;
}

Time& Time::operator-=(const Time& D){
    if (D.m_min > m_min) m_min += 24 * 60;
    m_min -= D.m_min;
    return *this;
}

std::istream& operator>>(std::istream& in, Time& a) {
    return a.read(in);
}

std::ostream& operator<<(std::ostream& out, Time& b) {
    return b.write(out);
}

}
