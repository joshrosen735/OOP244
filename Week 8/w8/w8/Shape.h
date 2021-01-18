#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H
#include <iomanip>
#include <iostream>
#include <string.h>
#include <iostream>
namespace sdds {
   class Shape {
   public:
       //pure virtual functions
       virtual void draw(std::ostream&)const = 0;
       virtual void getSpecs(std::istream&) = 0;

       //Virtual destructor
       virtual ~Shape();
      
   };
   // Operator overloadings
   std::ostream& operator<<(std::ostream&, Shape& );
   std::istream& operator>>(std::istream&, Shape&);
}

#endif // !SDDS_SHAPE_H

