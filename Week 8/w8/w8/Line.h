#ifndef SDDS_LINE_H
#define SDDS_LINE_H
#include<iostream>
#include "LblShape.h"
namespace sdds {
   class Line:public LblShape{
   private:
       int m_length;

   public:
       //Constructors
       Line();
       Line(const char* Cstring, int);

       //Destructor
      

       //Overriding of the Shape's func
       void getSpecs(std::istream&);

       void draw(std::ostream&)const;
   };
}
#endif // !SDDS_LINE_H

