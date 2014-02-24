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
#include "Database.h"
using namespace std;
class Person {
private:
    int age;
    std::string name;
public:
    std::string getName() {
        std::cout << this->name;
        return this->name;
    }
    void setName(Database db) {
        string name;
        cout << "Enter your name: ";
        cin >> name;
        this->name = name;
        db.insertRecord(name);
    }
};
#endif /* defined(__firstMacC__Person__) */
