/* Citation and Sources...
 Final Project Milestone 4
 Module: IOAble
 Filename: IOAble.cpp
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

#include <iostream>
#include <stdio.h>
#include<fstream>
#include "IOAble.h"
using namespace std;
namespace sdds{

IOAble::~IOAble(){

}

istream& operator>>(istream& in, IOAble& obj) {
    return obj.read(in);
}

ostream& operator<<(ostream& out, IOAble& obj) {
    return obj.write(out);
}

}
