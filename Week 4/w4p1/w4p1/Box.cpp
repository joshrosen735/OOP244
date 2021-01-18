/*
 "I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments."
 Name: Dhruv Bipinbhai Patel
 Email: dbpatel31@myseneca.ca
 StudentID: 142572197
 Date: 10/16/20
 */

#include<iostream>
#include<cstring>
#include <iomanip>
#include "Box.h"

using namespace std;

namespace sdds{

void Box::setName(const char* Cstr){
    if(Cstr){
        m_contentName = nullptr;
        m_contentName = new char[strlen(Cstr) + 1];
        strcpy(m_contentName,Cstr);
    }
    else{
        return;
    }
}

void Box::setUnusable(){
    m_contentName = nullptr;
    m_width = -1;
    m_height = -1;
    m_length = -1;
    m_contentVolume = -1;
}

bool Box::isUnusable()const{
    bool status = false;
    if(m_width == -1 || m_height == -1 || m_length == -1 || m_contentVolume == -1){
        status = true;
    }
        return status;
}

bool Box::hasContent()const{
    bool status = false;
    if(m_contentVolume > 0){
        status = true;
    }
    return status;
}

Box::Box(){
    m_width = 12;
    m_height = 12;
    m_length = 12;
    m_contentName = nullptr;
    m_contentVolume = 0;
}

Box::Box(int sideLength, const char* contentName){
    if(sideLength < 5 || sideLength > 36){
        setUnusable();
        return;
    }
    else{
        m_width = sideLength;
        m_height = sideLength;
        m_length = sideLength;
        m_contentVolume = 0;
        setName(contentName);
    }
}

Box::Box(int width, int height, int length, const char* contentName){
    if(width < 5 || width > 36 || height < 5 || height > 36 || length < 5 || length > 36){
        setUnusable();
        return;
    }
    else{
        m_width = width;
        m_height = height;
        m_length = length;
        m_contentVolume = 0;
        setName(contentName);
    }
}

Box::~Box(){
    delete [] m_contentName;
    m_contentName = nullptr;
}

int Box::capacity()const{
    return m_width * m_height * m_length;
}

int Box::quantity()const{
    return m_contentVolume;
}

Box& Box::setContent(const char* contentName){
    if(hasContent() && contentName){
        setUnusable();
        return *this;
    }
    setName(contentName);
    return *this;
}

ostream& Box::display()const{
    
    if(isUnusable()){
        
        return cout << "Unusable box, discard the content, and recycle.";
    }
    else{
        
        if(m_contentName == nullptr){
            cout << std::left << std::setfill('.') << std::setw(30) << "Empty box" ;
        }
        
        else{
            cout << std::left << std::setfill('.') << std::setw(30) << m_contentName ;
        }
        
        cout << "  ";
        
        cout << std::right << std::setfill('0') << std::setw(2) << m_width << "x";
        
        cout << std::right << std::setfill('0') << std::setw(2) << m_height << "x";
        
        cout << std::right << std::setfill('0') << std::setw(2) << m_length << " ";
        
        cout << std::right << std::setfill(' ') << std::setw(7) << quantity() << "/" << capacity() << " C.I.";
        
        return cout;
    }
}

Box& Box::add(int quantity){
    int sum = 0;
    sum = quantity + Box::quantity();
    if(sum < capacity()){
        m_contentVolume += quantity;
        return *this;
    }
    else{
        setUnusable();
        return *this;
    }
}

Box& Box::add(Box& B){
    if (m_contentName == nullptr || quantity() == 0) {
         setContent(B.m_contentName);
      }
      if (strcmp(m_contentName, B.m_contentName) == 0) {
         if (quantity() + B.quantity() <= capacity()) {
            add(B.quantity());
            B.m_contentVolume = 0;
         }
         else {
            B.m_contentVolume -= (capacity() - quantity());
            m_contentVolume = capacity();
         }
      }
      else {
         if (quantity() + B.quantity() <= capacity()) {
            B.m_contentVolume = 0;
         }
         else {
            B.m_contentVolume -= (capacity() - quantity());
         }
         setUnusable();
      }
      return *this;
}

}

