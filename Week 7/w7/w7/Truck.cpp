/*
 "I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments."
 Name: Dhruv Bipinbhai Patel
 Email: dbpatel31@myseneca.ca
 StudentID: 142572197
 Date: 11/11/20
 */

#define _CRT_SECURE_NO_WARNINGS
#include "Truck.h"
#include "Vehicle.h"
#include <iomanip>
#include <iostream>
#include <string.h>

using namespace std;

namespace sdds
{

Truck::Truck(const char licencePlateNumber[], int year, double capacity, const char* currentAddress) : Vehicle(licencePlateNumber, year)
{
    
    maxWeight = capacity;
    currentWeight = 0;
    
    Vehicle::moveTo(currentAddress);
}

bool Truck::addCargo(double cargo)
{
    bool flag = false;
    double tempWeight = currentWeight + cargo;
    
    if (currentWeight != maxWeight)
    {
        if (tempWeight <= maxWeight)
        {
            currentWeight = currentWeight + cargo;
            flag = true;
        }
        else
        {
            currentWeight = maxWeight;
            flag = true;
        }
    }
    return flag;
    
}

bool Truck::unloadCargo()
{
    
    bool flag = false;
    
    if (currentWeight != 0)
    {
        currentWeight = 0;
        flag = true;
    }
    return flag;
}

ostream& Truck::write(ostream& os)const
{
    Vehicle::write(os);
    
    os << " | " << currentWeight << "/" << maxWeight;
    return os;
}

istream& Truck::read(istream& in)
{
    Vehicle::read(in);//calling superclass function
    cout << "Capacity: ";
    in >> this->maxWeight;
    cout << "Cargo: ";
    in >> this->currentWeight;
    return in;
}

ostream& operator<<(ostream& os, const Truck& t)
{
    
    t.write(os);
    return os;
    
}

istream& operator>>(istream& is, Truck& t)
{
    return t.read(is);
}

Truck::~Truck()
{
}

}
