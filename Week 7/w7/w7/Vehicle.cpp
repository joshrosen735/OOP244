/*
 "I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments."
 Name: Dhruv Bipinbhai Patel
 Email: dbpatel31@myseneca.ca
 StudentID: 142572197
 Date: 11/11/20
 */
#define _CRT_SECURE_NO_WARNINGS

#include "Vehicle.h"
#include <iostream>
#include <iomanip>
#include <assert.h>

using namespace std;

namespace sdds
{

Vehicle::Vehicle(const char licencePlateNumber[], int yearMade)
{
    if(strlen(licencePlateNumber) < sizeof(licencePlate))
        strcpy(licencePlate, licencePlateNumber);
    
    year = yearMade;
    strcpy(addressOfVehicle, "Factory");
    
}

void Vehicle::moveTo(const char* address)
{
    
    if (address != addressOfVehicle)
    {
        
        cout << "|" << right << setw(8) << licencePlate << "| |" << setw(20) << right <<
        addressOfVehicle << " ---> " << setw(20) << left << address << "|" << endl;
        
        if(strlen(address) < sizeof(addressOfVehicle))
            strcpy(addressOfVehicle, address);
    }
}

ostream& Vehicle::write(ostream& os)const
{
    
    os << "| " << year << " | " << licencePlate << " | " << addressOfVehicle;
    return os;
}

istream& Vehicle::read(istream& is)
{
    cout << "Built year: ";
    is >> year;
    cout << "License plate: ";
    is >> licencePlate;
    cout << "Current location: ";
    is >> addressOfVehicle;
    return is;
}

ostream& operator<<(ostream& os, const Vehicle& m)
{
    return m.write(os);
}

istream& operator>>(istream& is, Vehicle& m)
{
    return m.read(is);
}

Vehicle::~Vehicle()
{
}
}
