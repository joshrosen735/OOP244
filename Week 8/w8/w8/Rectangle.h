#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H
#include "LblShape.h"
namespace sdds {
   class Rectangle:public LblShape {
   private:
       int m_width;
       int m_height;

   public:
       //Constructors
       Rectangle();
       Rectangle(const char*, int, int);

       //Destructor
     

       // Overriding of the Shape's func
       void getSpecs(std::istream&);

       void draw(std::ostream&)const;


   };
}
#endif
