/*
 "I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments."
 Name: Dhruv Bipinbhai Patel
 Email: dbpatel31@myseneca.ca
 StudentID: 142572197
 Date: 11/11/20
 */

#ifndef TRUCK_H_
#define TRUCK_H_
#include "Vehicle.h"
#include <iostream>
#include <string.h>

using namespace std;

namespace sdds
{

class Truck : public Vehicle
{
    
    double maxWeight;
    double currentWeight;
    
public:
    
    Truck(const char licencePlateNumber[], int year, double capacity, const char* currentAddress);
    
    bool addCargo(double cargo);
    bool unloadCargo();
    
    ostream& write(ostream& os)const;
    istream& read(istream& in);
    
    
    
    ~Truck();
};
// HELPER FUNCTIONS:
ostream& operator<<(ostream& os, const Truck& t);
istream& operator>>(istream& is, Truck& t);

}

#endif /* SRC_TRUCK_H_ */

