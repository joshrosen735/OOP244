/*
 "I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments."
 Name: Dhruv Bipinbhai Patel
 Email: dbpatel31@myseneca.ca
 StudentID: 142572197
 Date: 10/16/20
 */

#ifndef Box_h
#define Box_h

#include <stdio.h>

namespace sdds{
class Box{
    char* m_contentName = nullptr;
    int m_width;
    int m_height;
    int m_length;
    int m_contentVolume;
    
private:
    void setName(const char* Cstr);
    void setUnusable();
    bool isUnusable()const;
    bool hasContent()const;
    
public:
    int capacity()const;
    int quantity()const;
    Box& setContent(const char* contentName);
    std::ostream& display()const;
    Box& add(int quantity);
    Box& add(Box& B);
    
    //Constructors
    Box();
    Box(int sideLength, const char* contentName = nullptr);
    Box(int width, int height, int length, const char* contentName = nullptr);
    
    //Destructor
    ~Box();
};
}
#endif
