//
//  NameTag.hpp
//  w4p2
//
//  Created by Dhruv  on 2020-10-17.
//

#ifndef NameTag_h
#define NameTag_h

#include <iostream>

namespace sdds{
class NameTag{
    char* c_name = nullptr;
    int c_ext;
    
public:
    void print() const;
    NameTag& read(const char* name, int ext);
    
    //Constructors
    NameTag();
    NameTag(const char* name);
    NameTag(const char* name, int ext);
    
    //Destructor
    ~NameTag();
};
}

#endif
