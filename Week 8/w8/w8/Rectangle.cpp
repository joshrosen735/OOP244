
#include <cstring>
#include "Rectangle.h"
using namespace std;
namespace sdds {

    //Constructors
    Rectangle::Rectangle():LblShape()
    {
        m_width = 0;
        m_height = 0;
    }
    Rectangle::Rectangle(const char* Cstring, int width, int height):LblShape(Cstring)
    {
        m_width = width;
        m_height = height;

        int len = strlen(label());

        if (m_height < 3 || m_width < len + 2)
        {
            m_width = 0;
            m_height = 0;
        }
    }

    // Overriding of the Shape's func
    void Rectangle::getSpecs(std::istream& i)
    {
        LblShape::getSpecs(i);
        i >> m_width;
        i.ignore(100, ',');
        i >> m_height;
        i.ignore(100, '\n');
    }

    void Rectangle::draw(std::ostream& out)const
    {
        if (m_height != 0 || m_width != 0)
        {
            int len = strlen(label());
            out << "+";
            for (int i = 0; i < m_width - 2; i++)
            {
                out << "-";
            }
            out << "+" << endl;

            out << "|";
            out << left << label();
            for (int i = 0; i < (m_width - 2)-len; i++)
            {
                out << " ";
            }
            
            out << "|" << endl;

            for (int i = 0; i < m_height - 3; i++)
            {
                out << "|";
                for (int j = 0; j < m_width - 2; j++)
                {
                    out << " ";
                }
                out << "|" << endl;
            }

            out << "+";
            for (int i = 0; i < m_width - 2; i++)
            {
                out << "-";
            }
            out << "+";

        }
        else
        {

        }
    }

}
