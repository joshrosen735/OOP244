/*
 "I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments."
 Name: Dhruv Bipinbhai Patel
 Email: dbpatel31@myseneca.ca
 StudentID: 142572197
 Date: 11/08/20
 */

#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
namespace sdds {
class Numbers {
    double* m_numbers;
    char* m_filename;
    bool m_isOriginal;
    int m_numCount;
    bool isEmpty()const;
    void setEmpty();
    void setFilename(const char* filename);
    void sort();
public:
    Numbers();
    Numbers(const char* filename);
    Numbers(const Numbers& source);
    Numbers& operator=(const Numbers& src);
    int numberCount() const;
    bool load();
    void save();
    Numbers& operator+=(double num);
    double average()const;
    double max()const;
    double min()const;
    ~Numbers();
    
    std::ostream& display(std::ostream& ostr = std::cout) const;
};
std::ostream& operator<<(std::ostream& os, const Numbers& N);
std::istream& operator>>(std::istream& istr, Numbers& N);
}
#endif // !SDDS_NUMBERS_H_
