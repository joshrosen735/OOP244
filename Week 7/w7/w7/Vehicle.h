/*
 "I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments."
 Name: Dhruv Bipinbhai Patel
 Email: dbpatel31@myseneca.ca
 StudentID: 142572197
 Date: 11/11/20
 */

#ifndef Vehicle_H_
#define Vehicle_H_
#include <iostream>
#include <string.h>

using namespace std;

const int MAX_PLATE = 32;
const int MAX_ADDRESS = 64;

namespace sdds
{

class Vehicle
{
    
    char licencePlate[MAX_PLATE];
    char addressOfVehicle[MAX_ADDRESS];
    int year;
    
public:
    Vehicle(const char licencePlateNumber[], int yearMade);
    void moveTo(const char* address);
    
    /* Reference: */
    ostream& write(ostream& os)const;
    istream& read(istream& is);
    
    
    
    
    ~Vehicle();
    
};
// HELPER FUNCTIONS:
ostream& operator<<(ostream& os, const Vehicle& m);
istream& operator>>(istream& os, Vehicle& m);

}

#endif
