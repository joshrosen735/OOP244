#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <string.h>
#include "LblShape.h"
using namespace std;
namespace sdds {

const char* LblShape::label()const
{
    return m_label;
}
//constructors
LblShape::LblShape()
{
    if (m_label == nullptr)
    {

    }
    else
    {
        m_label = nullptr;
    }
}

LblShape::LblShape(const char* Cstring)
{
    m_label = nullptr;
    m_label = new char[strlen(Cstring)+1];
    strcpy(m_label, Cstring);
}

//destructor
LblShape::~LblShape()
{
    delete[] m_label;
    m_label = nullptr;
}

void LblShape::getSpecs(istream& in)
{
    char arr[21];
    in.get(arr, 21, ',');
    m_label = nullptr;
    m_label = new char[strlen(arr) + 1];
    strcpy(m_label, arr);
    in.ignore(20, ',');
}

}


