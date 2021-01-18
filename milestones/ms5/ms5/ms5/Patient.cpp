/* Citation and Sources...
 Final Project Milestone 5
 Module: Patient
 Filename: Patient.cpp
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
#include <iostream>
#include <cstring>
#include "Patient.h"
#include "utils.h"
using namespace std;
namespace sdds {

char Patient::type() const{
    char x = 'W';
    return x;
}

Patient::Patient(int ticketNumber, bool fileIO):ticketObj(ticketNumber){
    p_name = nullptr;
    p_num = 0;
    flag = fileIO;
}

Patient::~Patient(){
    delete[] p_name;
    p_name = nullptr;
}

bool Patient::fileIO() const{
    return flag;
}

void Patient::fileIO(bool val){
    flag = val;
}

bool operator==(const Patient& P, const char ch){
    return P.type() == ch;
}

bool operator==(const Patient& P1, const Patient& P2){
    return P1.type() == P2.type();
}

Patient::operator Time()const{
    return Time(ticketObj);
}

void Patient::setArrivalTime(){
    ticketObj.resetTime();
}

int Patient::number() const{
    return ticketObj.number();
}
ostream& Patient::csvWrite(ostream& ostr)const {
    ostr << type() << "," << p_name << "," << p_num << ",";
    ticketObj.csvWrite(ostr);
    return ostr;
}

istream& Patient::csvRead(istream& istr) {
    char name[51];
    istr.get(name, 51, ',');
    delete[] p_name;
    p_name = new char[strlen(name) + 1];
    strcpy(p_name,name);
    istr.ignore(51, ',');
    istr >> p_num;
    istr.ignore(51, ',');
    ticketObj.csvRead(istr);
    return istr;
}

ostream& Patient::write(ostream& ostr)const {
    ticketObj.write(ostr);
    ostr << endl << p_name << ", OHIP: " << p_num;
    return ostr;
}

istream& Patient::read(istream& istr) {
    char name[51];
    bool ok = false;
    int num;
    cout << "Name: ";
    istr.get(name, 51, '\n');
    delete[] p_name;
    p_name = new char[strlen(name) + 1];
    strcpy(p_name,name);
    istr.ignore(51, '\n');
    cout << "OHIP: ";
    while(ok == false){
        istr >> num;
        if(num > 100000000 && num < 999999999){
            p_num = num;
            ok = true;
            cin.clear();
            cin.ignore(51, '\n');
        }
        else if(cin.fail()) {
            cin.clear();
            cin.ignore(51, '\n');
            ok = false;
            cout << "Bad integer value, try again: ";
        }
        else{
            cout << "Invalid value enterd, retry[100000000 <= value <= 999999999]: ";
        }
    }
    return istr;
}

}
