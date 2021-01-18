/*
 "I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments."
 Name: Dhruv Bipinbhai Patel
 Email: dbpatel31@myseneca.ca
 StudentID: 142572197
 Date: 10/09/20
*/
#ifndef Subject_h
#define Subject_h

namespace sdds{
class Subject{
private:
    char m_code[7];
    int m_mark;
    char grade()const;
public:
    void setEmpty();
    void set(const char* code, int mark);
    float scale4()const;
    bool isValid()const;
    void display()const;
};
}
#endif 
