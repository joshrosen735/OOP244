/* Citation and Sources...
 Final Project Milestone 5
 Module: TriagePatient
 Filename: TriagePatient.h
 Version 1.0
 Author    Dhruv Bipinbhai Patel
 Revision History
 -----------------------------------------------------------
 Date        Reason
 2020/11/11  Preliminary release
 2020/11/11  Debugged DMA
 -----------------------------------------------------------
 I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.
 -----------------------------------------------------------*/

#ifndef SDDS_TRIAGE_H
#define SDDS_TRIAGE_H
#include <iostream>
#include "IOAble.h"
#include "Patient.h"
namespace sdds {
   class TriagePatient: public Patient {
       char* symptoms;
   public:
       TriagePatient();
       ~TriagePatient();
       virtual char type() const;
       virtual ostream& csvWrite(ostream&) const;
       virtual istream& csvRead(istream&);
       virtual ostream& write(ostream&) const;
       virtual istream& read(istream&);
   };

}
#endif // !SDDS_
