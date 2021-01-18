/* Citation and Sources...
Final Project Milestone 5
Module: Menu
Filename: Menu.cpp
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
#include<iostream>
#include<string.h>
#include "utils.h"
#include "Menu.h"
using namespace std;
namespace sdds {

Menu::Menu(const char* text, int NoOfSelections){
    m_text = nullptr;
    m_text = new char[strlen(text) + 1];
    strcpy(m_text, text);
    m_noOfSel = NoOfSelections;
}

Menu::~Menu(){
    delete[] m_text;
    m_text = nullptr;
}

ostream& Menu::display(ostream& ostr) const{
    cout << m_text << endl;
    cout << "0- Exit" << endl;
    cout << "> ";
    return ostr;
}

int& Menu::operator>>(int& Selection){
    bool ok = false;
    display( );
    int selectedOpt;
    
    while(ok == false){
        cin >> selectedOpt;
        if(selectedOpt >= 0 && selectedOpt <= m_noOfSel){
            Selection = selectedOpt;
            ok = true;
        }
        else{
            cout << "Invalid value enterd, retry[0 <= value <= 3]: ";
        }
        
        if(cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            ok = false;
            cout << "Bad integer value, try again: ";
        }
    }
    return Selection;
}

}
