/*
 "I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments."
 Name: Dhruv Bipinbhai Patel
 Email: dbpatel31@myseneca.ca
 StudentID: 142572197
 Date: 10/11/20
 */
#include<iostream>
#include<cstring>
#include <iomanip>
#include "Bar.h"

using namespace std;

namespace sdds{

void Bar::setEmpty(){
    b_value = -1;
    b_name[0] = '\0';
}

void Bar::set(const char* name, int value){
    if(value < 0 || value > 100){
        setEmpty();
    }
    else{
        strcpy(b_name,name);
        b_value = value;
    }
}

bool Bar::isValid()const{
    bool ok = false;
    if(b_value >= 0 && b_value <= 100) ok = true;
    return ok;
}

void Bar::draw()const{
    if(isValid()){
        cout.width(20);
        cout.fill('.');
        cout.setf(ios::left);
        cout << b_name;
        cout << "|";
        for(int i=0;i<(b_value/2);i++)
        {
            cout << "=";
        }
        cout << endl;
    }
}
}
