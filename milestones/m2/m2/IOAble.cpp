#include <iostream>
#include <stdio.h>
#include<fstream>
#include "IOAble.h"
using namespace std;
namespace sdds{

std::ostream& IOAble::csvWrite(std::ostream &a) const{
    return a;
}

std::istream& IOAble::csvRead(std::istream &b){
    return b;
}

std::ostream& IOAble::write(std::ostream &c) const{
    return c;
}

std::istream& IOAble::read(std::istream &d){
    return d;
}

IOAble::~IOAble(){
    
}

istream& operator>>(istream& in, IOAble& obj) {
    return obj.read(in);
}

ostream& operator<<(ostream& out, IOAble& obj) {
    return obj.write(out);
}

}
