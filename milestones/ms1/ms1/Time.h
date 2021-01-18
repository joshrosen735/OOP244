/* Citation and Sources...
Final Project Milestone 3
Module: Time
Filename: Time.h
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

#ifndef SDDS_TIME_H
#define SDDS_TIME_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
namespace sdds {
class Time {
    unsigned int m_min;
public:
    Time& reset();
    Time(unsigned int min = 0);
    std::ostream& write(std::ostream& ostr) const;
    std::istream& read(std::istream& istr);
    operator int()const;
    Time& operator *= (int val);
    Time& operator-=(const Time& D);
};
// helper operator << and >> prototypes
std::istream& operator>>(std::istream& in, Time&);

std::ostream& operator<<(std::ostream& out, Time&);
}

#endif // !SDDS_TIME_H
