#include <iomanip>
#include <iostream>
#include <string.h>
#include "Line.h"
#include "Line.h"
using namespace std;
namespace sdds {

    //Constructors
    Line::Line():LblShape()
    {
        m_length = 0;
    }
    Line::Line(const char* Cstring, int length):LblShape(Cstring)
    {
        m_length = length;
    }

    //Overriding of the Shape's func
    void Line::getSpecs(std::istream& i)
    {
        LblShape::getSpecs(i);
        i >> m_length;
        i.ignore(100, '\n');
    }
    void Line::draw(std::ostream& o)const
    {
        if (m_length > 0 && label() != nullptr)
        {
            o << label() << endl;
            for (int i = 0; i < m_length; i++)
            {
                o << "=";
            }
        }
        else
        {

        }
    }
}
