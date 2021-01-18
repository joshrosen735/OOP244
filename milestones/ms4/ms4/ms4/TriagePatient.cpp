/* Citation and Sources...
 Final Project Milestone 4
 Module: TriagePatient
 Filename: TriagePatient.cpp
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

#include<cstring>
#include "TriagePatient.h"
using namespace std;
namespace sdds {
   int nextTriageTicket = 1;
 
TriagePatient::TriagePatient():Patient(nextTriageTicket, fileIO()){
    symptoms = nullptr;
    nextTriageTicket++;
}

TriagePatient::~TriagePatient(){
    delete[] symptoms;
    symptoms = nullptr;
}

char TriagePatient::type() const{
    return 'T';
}

ostream& TriagePatient::csvWrite(ostream& ostr)const {
Patient::csvWrite(ostr);
    ostr << "," << symptoms;
    return ostr;
}

istream& TriagePatient::csvRead(istream& istr){
    char symptomName[511];
    delete[] symptoms;
    Patient::csvRead(istr);
    istr.ignore(511,',');
    istr.get(symptomName, 511, '\n');
    symptoms = new char[strlen(symptomName) + 1];
    strcpy(symptoms, symptomName);
    nextTriageTicket = (Patient::number() + 1);
    return istr;
    
}

ostream& TriagePatient::write(ostream& ostr)const{
    if(fileIO())csvWrite(ostr);
    else{
        ostr << "TRIAGE" << endl;
        Patient::write(ostr) << endl;
        ostr << "Symptoms: " << symptoms << endl;
    }
    return ostr;
}

istream& TriagePatient::read(istream& istr){
    if(fileIO())csvRead(istr);
    else{
        char sym[511];
        delete [] symptoms;
        Patient::read(istr);
        cout << "Symptoms: ";
        istr.get(sym, 511, '\n');
        istr.ignore(511,'\n');
        symptoms = new char[strlen(sym) + 1];
        strcpy(symptoms, sym);
    }
    return istr;
}

}
