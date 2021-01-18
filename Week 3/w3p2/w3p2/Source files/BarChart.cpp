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
#include "BarChart.h"
#include "Bar.h"

using namespace std;

namespace sdds {

void BarChart::setEmpty(){
    c_title[0] = '\0';
    bars = nullptr;
}

void BarChart::Title()const{
    cout << c_title << endl;
    int i;
    for(i=0;i<71;i++)cout << "-";
    cout << endl;
}

void BarChart::footer()const{
    int i;
    for(i=0;i<71;i++) cout << "-";
    cout << endl;
}

bool BarChart::isValid()const{
    bool valid = false;
    int i;
    if (c_title != nullptr && bars != nullptr) {
        for (i = 0; i < c_size && valid == false; i++) {
            if (!bars[i].isValid()){
                valid = true;
            }
            else valid = false;
        }
    }
    return valid;
}


void BarChart::init(const char* title, int noOfSamples, char fill){
    if(title == nullptr || noOfSamples < 1){
        setEmpty();
    }
    else{
        c_size = noOfSamples;
        c_samplesAdded = 0;
        c_title = new char[strlen(title) + 1];
        strcpy(c_title,title);
        bars = new Bar[c_size];
        for(int i=0;i<c_size;i++)
        {
            bars[i].setEmpty();
        }
    }
}

bool BarChart::add(const char* bar_title, int value){
    if(c_samplesAdded < c_size){
        bars[c_samplesAdded].set(bar_title, value);
        c_samplesAdded += 1;
        return true;
    }
    return false;
}

void BarChart::draw()const{
    int i;
    if(!isValid()){
        Title();
        for(i=0;i<c_size;i++)
        {
            bars[i].draw();
        }
        footer();
    }
    else{
        cout << "Invalid Chart!" << endl;
    }
}

void BarChart::deallocate(){
    delete[] c_title;
    c_title = nullptr;
    delete[] bars;
    bars = nullptr;
}
}
