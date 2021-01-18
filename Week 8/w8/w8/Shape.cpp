#include<iostream>
#include "Shape.h"
namespace sdds {
    //Virtual destructor
    Shape::~Shape()
    {
        
    }

    // Operator overloadings
    std::ostream& operator<<(std::ostream& output, Shape& S)
    {
        S.draw(output);
        return output;
    }
    std::istream& operator>>(std::istream& input, Shape& S)
    {
        S.getSpecs(input);
        return input;
    }

}
