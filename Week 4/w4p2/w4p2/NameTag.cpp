//
//  NameTag.cpp
//  w4p2
//
//  Created by Dhruv  on 2020-10-17.
//
#include<iostream>
#include<cstring>
#include "NameTag.h"

using namespace std;

namespace sdds{
NameTag::NameTag(){
    c_name = nullptr;
    c_ext = 0;
}

NameTag::NameTag(const char* name, int ext){
    c_ext = ext;
    read(name, ext);
}

NameTag& NameTag::read(const char* name, int ext){
    int value = 0;
    char x;
    c_name = nullptr;
    c_name = new char[41];
    strcpy(c_name, name);
    cout << "Would you like to enter an extension? (Y)es/(N)o: ";
    cin >> x;
    if(x == 'y' || x == 'Y'){
        cout << "Please enter a 5 digit phone extension: ";
        cin >> value;
        while(value <= 10000 || value >= 99999){
            cout << "Invalid value [10000<=value<=99999]: ";
        }
    }
    return *this;
}



}
