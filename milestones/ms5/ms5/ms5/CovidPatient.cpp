/* Citation and Sources...
 Final Project Milestone 5
 Module: CovidPatient
 Filename: CovidPatient.cpp
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

#include "CovidPatient.h"
using namespace std;
namespace sdds {
int nextCovidTicket = 1;

CovidPatient::CovidPatient():Patient(nextCovidTicket, fileIO()){
    nextCovidTicket++;
}

char CovidPatient::type() const{
    return 'C';
}

ostream& CovidPatient::csvWrite(ostream& ostr)const {
    Patient::csvWrite(ostr);
    return ostr;
}

istream& CovidPatient::csvRead(istream& istr) {
    Patient::csvRead(istr);
    nextCovidTicket = (Patient::number() + 1);
    return istr;
}

ostream& CovidPatient::write(ostream& ostr)const{
    if(fileIO()) Patient::csvWrite(ostr);
    else{
        ostr << "COVID TEST" << endl;
        Patient::write(ostr) << endl;
    }
    return ostr;
}

istream& CovidPatient::read(istream& istr){
    if(fileIO()) csvRead(istr);
    else Patient::read(istr);
    return istr;
}

}
