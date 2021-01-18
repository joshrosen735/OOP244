/* Citation and Sources...
 Final Project Milestone 5
 Module: Patient
 Filename: Patient.h
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

#include <iostream>
#include "IOAble.h"
#include "Ticket.h"
#ifndef SDDS_PATIENT_H_
#define SDDS_PATIENT_H_
namespace sdds {
class Patient:public IOAble{
    char* p_name;
    int p_num;
    Ticket ticketObj;
    bool flag;
public:
    Patient(int, bool);
    ~Patient();
    Patient(const Patient&) = delete;
    Patient& operator=(const Patient&) = delete;
    
    bool fileIO() const;
    void fileIO(bool);
    void setArrivalTime();
    virtual char type() const = 0;
    operator Time() const;
    int number() const;
    virtual ostream& csvWrite(ostream&) const;
    virtual istream& csvRead(istream&);
    virtual ostream& write(ostream&) const;
    virtual istream& read(istream&);
};

bool operator==(const Patient& P, char ch);
bool operator==(const Patient& P1, const Patient& P2);

}
#endif // !SDDS_PATIENT_H_

