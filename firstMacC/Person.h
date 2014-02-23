//
//  Person.h
//  firstMacC
//
//  Created by Kevin Coyle on 22/02/2014.
//  Copyright (c) 2014 Kevin Coyle. All rights reserved.
//

#ifndef __firstMacC__Person__
#define __firstMacC__Person__

#include <iostream>
#include <string>
class Person {
private:
    int age;
    std::string name;
public:
    std::string getName() {
        std::cout << this->name;
        return this->name;
    }
    void setName(std::string name) {
        this->name = name;
    }
};
#endif /* defined(__firstMacC__Person__) */
