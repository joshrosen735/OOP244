/*
 "I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments."
 Name: Dhruv Bipinbhai Patel
 Email: dbpatel31@myseneca.ca
 StudentID: 142572197
 Date: 10/09/20
*/
#include<iostream>
#include<cstring>
#include <iomanip>
#include "Subject.h"

using namespace std;

namespace sdds{

char Subject::grade()const{
    char result = '\0';
    if(m_mark >=0 && m_mark < 50) result = 'F';
    else if(m_mark >=50 && m_mark < 60) result = 'D';
    else if(m_mark >=60 && m_mark < 70) result = 'C';
    else if(m_mark >=70 && m_mark < 80) result = 'B';
    else if(m_mark >=80 && m_mark <= 100) result = 'A';
    return result;
}

void Subject::setEmpty(){
    m_mark = -1;
    m_code[0] = '\0';
}

void Subject::set(const char* code, int mark){
    if(mark < 0 || mark > 100){
        setEmpty();
    }
    else{
        strcpy(m_code,code);
        m_mark = mark;
    }
}

float Subject::scale4()const{
    float gpa=0.0;
    if(m_mark >=0 && m_mark < 50) gpa = 0.0;
    else if(m_mark >=50 && m_mark < 60) gpa = 1.0;
    else if(m_mark >=60 && m_mark < 70) gpa = 2.0;
    else if(m_mark >=70 && m_mark < 80) gpa = 3.0;
    else if(m_mark >=80 && m_mark <= 100) gpa = 4.0;
    return gpa;
}

bool Subject::isValid()const{
    bool ok = false;
    if(m_mark >= 0 && m_mark <= 100) ok = true;
    return ok;
}

void Subject::display()const{
    if(isValid()){
        cout.setf(ios::left);
        cout << m_code;
        cout.width(12);
        cout.setf(ios::right);
        cout << m_mark;
        cout.width(10);
        cout.setf(ios::right);
        cout << grade();
        cout << endl;
    }
}
}
