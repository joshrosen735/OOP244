/*
 "I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments."
 Name: Dhruv Bipinbhai Patel
 Email: dbpatel31@myseneca.ca
 StudentID: 142572197
 Date: 10/11/20
 */
#ifndef BarChart_h
#define BarChart_h
#include "Bar.h"
namespace sdds{
class BarChart{
    char* c_title;
    Bar* bars;
    char c_fill;
    int c_size;
    int c_samplesAdded;

public:
    bool isValid()const;
    void setEmpty();
    void Title()const;
    void footer()const;
    void init(const char* title, int noOfSamples, char fill);
    bool add(const char* bar_title, int value);
    void draw()const;
    void deallocate();
};
}
#endif
