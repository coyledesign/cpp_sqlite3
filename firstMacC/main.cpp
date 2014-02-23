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
    char * dbname = "app2.db";
    char * sql = "SELECT * FROM people";
    int result = sqlite3_open(dbname, &database);
    if (result != SQLITE_OK) {
        cout << sqlite3_errcode(database);
        sqlite3_close(database) ;
        return 1;
    }
    result = sqlite3_prepare_v2(database, sql, strlen(sql)+1, &stmt, NULL);
    if (result != SQLITE_OK) {
        sqlite3_close(database) ;
        return 2;
    }
    int cols = sqlite3_column_count(stmt);
    result = 0;
    while(true)
    {
        result = sqlite3_step(stmt);
        
        if(result == SQLITE_ROW)
        {

            for(int col = 0; col < cols; col++)
            {
                string s = (char*)sqlite3_column_text(stmt, col);
                //do something with it
                cout << "Hi" << s;
            }
        }
        else
        {
            break;   
        }
    }
    
    sqlite3_finalize(stmt);
    
    
    printf("Opened db %s OK\n\r",dbname) ;
    return 0;
}