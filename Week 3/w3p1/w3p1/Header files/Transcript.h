/*
 "I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments."
 Name: Dhruv Bipinbhai Patel
 Email: dbpatel31@myseneca.ca
 StudentID: 142572197
 Date: 10/09/20
*/
#ifndef Transcript_h
#define Transcript_h
#include "Subject.h"

namespace sdds{
class Transcript{
    char* m_studentName;
    Subject* m_subjects;
    int m_noOfSubjects;
    int m_subjectsAdded;
private:
    void setEmpty();
    bool isValid()const;
    void Title()const;
    float gpa()const;
    void footer()const;
public:
    void init(const char* studentName, int noOfSubjects);
    bool add(const char* subject_code, int mark);
    void display()const;
    void deallocate();
};
}

#endif 
