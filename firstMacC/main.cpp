//
//  main.cpp
//  firstMacC
//
//  Created by Kevin Coyle on 22/02/2014.
//  Copyright (c) 2014 Kevin Coyle. All rights reserved.
//

#include <iostream>
#include <string>
#include <sqlite3.h>
#include "Person.h"
using namespace std;


int main(int argc, const char * argv[])
{
    sqlite3 *database;
    sqlite3_stmt *stmt;
    char * dbname = "/Users/kevincoyle/development/firstCmac/firstMacC/firstMacC/app.db";
    char * sql = "SELECT * FROM people";
    int result = sqlite3_open(dbname, &database);
    if (result != SQLITE_OK) {
        cout << sqlite3_errcode(database);
        sqlite3_close(database) ;
        return 1;
    }
    Database db;
    db.getCols();
    Person person;
    string name;
    person.setName(name, db);
    printf("Opened db %s OK\n\r",dbname) ;
    return 0;
}