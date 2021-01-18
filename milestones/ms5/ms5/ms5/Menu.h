/* Citation and Sources...
Final Project Milestone 5
Module: Menu
Filename: Menu.h
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

#ifndef SDDS_MENU_H_

#define _CRT_SECURE_NO_WARNINGS
#define SDDS_MENU_H_
#include <iostream>
namespace sdds {
class Menu{
    char* m_text;
    int m_noOfSel;
public:
    Menu(const char* text, int NoOfSelections);
    virtual ~Menu();
    Menu(const Menu&) = delete;
    Menu& operator=(const Menu&) = delete;
    std::ostream& display(std::ostream& ostr = std::cout)const;
    int& operator>>(int& Selection);
};
}
#endif // !SDDS_MENU_H_
