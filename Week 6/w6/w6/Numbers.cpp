/*
 "I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments."
 Name: Dhruv Bipinbhai Patel
 Email: dbpatel31@myseneca.ca
 StudentID: 142572197
 Date: 11/08/20
 */

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include "Numbers.h"
using namespace std;
namespace sdds {


Numbers::Numbers() {
    setEmpty();
    m_isOriginal = false;
}

Numbers::Numbers(const Numbers& source){
    setEmpty();
    m_isOriginal=false;
    *this = source;
}

Numbers& Numbers::operator=(const Numbers& src){
    if (this != &src) {
        m_numCount = src.m_numCount;
        if (src.m_filename != nullptr && src.m_numbers != nullptr) {
            delete[] m_numbers;
            delete[] m_filename;
            m_filename = new char[strlen(src.m_filename) + 1];
            strcpy(m_filename, src.m_filename);
            m_numbers = new double[m_numCount];
            for (int i = 0; i < m_numCount; i++) {
                m_numbers[i] = src.m_numbers[i];
            }
        }
    }
    return *this;
}

Numbers::Numbers(const char* filename) {
    setEmpty();
    m_isOriginal = true;
    setFilename(filename);
    m_numCount = numberCount();
    if (m_numCount == 0 || !load()) {
        delete[] m_numbers;
        delete[] m_filename;
        setEmpty();
        m_isOriginal = false;
    }
    else {
        sort();
    }
}

Numbers::~Numbers() {
    save();
    delete[] m_numbers;
    delete[] m_filename;
}

bool Numbers::isEmpty() const {
    return m_numbers == nullptr;
}

void Numbers::setEmpty() {
    m_numbers = nullptr;
    m_filename = nullptr;
    m_numCount = 0;
}

void Numbers::setFilename(const char* filename) {
    delete[] m_filename;
    m_filename = new char[strlen(filename) + 1];
    strcpy(m_filename, filename);
}

void Numbers::sort() {
    int i, j;
    double temp;
    for (i = m_numCount - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (m_numbers[j] > m_numbers[j + 1]) {
                temp = m_numbers[j];
                m_numbers[j] = m_numbers[j + 1];
                m_numbers[j + 1] = temp;
            }
        }
    }
}

double Numbers::average() const {
    double aver = 0.0;
    if (!isEmpty()) {
        for (int i = 0; i < m_numCount; i++)
        aver += m_numbers[i];
        aver = aver / m_numCount;
    }
    return aver;
}

double Numbers::min() const {
    double minVal = 0.0;
    if (!isEmpty()) {
        minVal = m_numbers[0];
        for (int i = 1; i < m_numCount; i++)
        if (minVal > m_numbers[i]) minVal = m_numbers[i];
    }
    return minVal;
}

double Numbers::max() const {
    double maxVal = 0.0;
    if (!isEmpty()) {
        maxVal = m_numbers[0];
        for (int i = 1; i < m_numCount; i++)
        if (maxVal < m_numbers[i]) maxVal = m_numbers[i];
    }
    return maxVal;
}

int Numbers::numberCount() const{
    double value;
    int count=0;
    bool check = 1;
    ifstream file;
    file.open(m_filename);
    if(file.is_open()){
        while(file && check){
            file >> value;
            count++;
            if(file.fail()){
                check = 0;
                count--;
            }
        }
    }
    return count;
}

bool Numbers::load(){
    bool  check = false;
    int i = 0;
    double num;
    if(m_numCount>0){
        delete [] m_numbers;
        m_numbers = new double[m_numCount];
        ifstream f;
        f.open(m_filename);
        if(f.is_open()){
            if(f.fail()) cout << "fail!";
            else{
                for(i=0;i<m_numCount;i++)
                {
                    f >> num;
                    m_numbers[i] = num;
                }
                if(i==m_numCount) check = true;
            }
        }
    }
    return check;
}

void Numbers::save(){
    if(!isEmpty() || m_isOriginal){
        ofstream file(m_filename);
        if(file.is_open()){
            for(int i=0;i<m_numCount;i++){
                file << m_numbers[i] << endl;
            }
        }
    }
}

Numbers& Numbers::operator+=(double num){
    double* temp = nullptr;
    if(num){
        m_numCount++;
        temp = new double[m_numCount];
        if(!isEmpty()){
            for(int i=0;i<m_numCount - 1;i++){
                temp[i]=m_numbers[i];
            }
            temp[m_numCount-1] = num;
        }
        delete[] m_numbers;
        m_numbers=temp;
        sort();
    }
    return *this;
}

std::ostream& Numbers::display(std::ostream& ostr) const{
    if(isEmpty()){
        ostr << "Empty list";
    }
    else{
        ostr << "=========================" << endl;
        if(m_isOriginal){
            ostr << m_filename << endl;
        }
        else{
            ostr << "*** COPY ***" << endl;
        }
        for (int i = 0; i < m_numCount - 1; i++) {
            ostr << m_numbers[i] << ", " ;
        }
        ostr << m_numbers[m_numCount-1];
        ostr << endl;
        ostr << "-------------------------" << endl;
        ostr << "Total of " << m_numCount << " number(s)" << endl;
        ostr << "Largest number:  " << max() << endl;
        ostr << "Smallest number: " << min() << endl;
        ostr << "Average :        " << average() << endl;
        ostr << "=========================";
    }
    return ostr;
}


std::ostream& operator<<(std::ostream& os, const Numbers& N){
    N.display(os);
    return os;
}

std::istream& operator>>(std::istream& istr, Numbers& N){
    double value;
    istr >> value;
    N += value;
    return istr;
}

}
