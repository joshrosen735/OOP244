#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H
#include "Shape.h"
namespace sdds {
   class LblShape:public Shape  {
   private:
       char* m_label = nullptr;

   protected:
       const char* label()const;

   public:
       //constructors
       LblShape();
       LblShape(const char* Cstring);

       //destructor
       virtual ~LblShape();

       //copy constructor =delete
       LblShape(const LblShape&)=delete;

       //copy assignment operator =delete
       LblShape& operator=(const LblShape&) = delete;

       //Overriding of the Shape's func
       void getSpecs(std::istream&);

       virtual void draw(std::ostream&)const = 0;

   };
}
#endif // !SDDS_LBLSHAPE_H


