/*
 "I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments."
 Name: Dhruv Bipinbhai Patel
 Email: dbpatel31@myseneca.ca
 StudentID: 142572197
 Date: 10/11/20
 */
#ifndef Bar_h
#define Bar_h

namespace sdds{
class Bar{
    char b_name[21];
    char b_fill;
    int b_value;
    
public:
    void setEmpty();
    void set(const char* name, int value);
    bool isValid()const;
    void draw()const;
};
}
#endif
