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
#include "Transcript.h"
#include "Subject.h"

using namespace std;

namespace sdds {

void Transcript::setEmpty(){
    m_studentName[0] = '\0';
    m_subjects = nullptr;
}

bool Transcript::isValid()const{
    bool valid = false;
    int i;
    if (m_studentName != nullptr && m_subjects != nullptr) {
        for (i = 0; i < m_noOfSubjects && valid == false; i++) {
            if (!m_subjects[i].isValid()){
                valid = true;
            }
            else valid = false;
        }
    }
    return valid;
}

void Transcript::Title()const{
    cout << m_studentName << endl;
    int i;
    for(i=0;i<29;i++)cout << "-";
    cout << endl;
}

float Transcript::gpa()const{
    float total=0.0, avg=0.0;
    int i;
    for(i=0;i<m_noOfSubjects;i++)
    {
        total += m_subjects[i].scale4();
    }
    avg=total/m_noOfSubjects;
    return avg;
}

void Transcript::footer()const{
    int i;
    for(i=0;i<29;i++) cout << "-";
    cout << endl;
    cout.width(26);
    cout.setf(ios::right);
    cout << "GPA: " << setprecision(2) << gpa() << endl;
}

void Transcript::init(const char* studentName, int noOfSubjects){
    if(studentName == nullptr || noOfSubjects < 1){
        setEmpty();
    }
    else{
        m_noOfSubjects = noOfSubjects;
        m_subjectsAdded = 0;
        m_studentName = new char[strlen(studentName) + 1];
        strcpy(m_studentName,studentName);
        m_subjects = new Subject[m_noOfSubjects];
        for(int i=0;i<m_noOfSubjects;i++)
        {
            m_subjects[i].setEmpty();
        }
    }
}

bool Transcript::add(const char* subject_code, int mark){
    if(m_subjectsAdded < m_noOfSubjects){
        m_subjects[m_subjectsAdded].set(subject_code, mark);
        m_subjectsAdded += 1;
        return true;
    }
    return false;
}

void Transcript::display()const{
    int i;
    if(!isValid()){
        Title();
        for(i=0;i<m_noOfSubjects;i++)
        {
            m_subjects[i].display();
        }
        footer();
    }
    else{
        cout << "Invalid Transcript!" << endl;
    }
}

void Transcript::deallocate(){
    delete[] m_studentName;
    m_studentName = nullptr;
    delete[] m_subjects;
    m_subjects = nullptr;
}
}
