//
//  Database.h
//  firstMacC
//
//  Created by Kevin Coyle on 23/02/2014.
//  Copyright (c) 2014 Kevin Coyle. All rights reserved.
//

#ifndef __firstMacC__Database__
#define __firstMacC__Database__

#include <iostream>
#include <sqlite3.h>
#include <string>
using namespace std;
class Database {
public:
    char * dbname = "/Users/kevincoyle/development/firstCmac/firstMacC/firstMacC/app.db";
    char * sql = "SELECT * FROM people";
    sqlite3 *database;
    sqlite3_stmt *stmt;
    int getCols() {
        int result = sqlite3_open(this->dbname, &database);
        result = sqlite3_prepare_v2(database, sql, strlen(sql)+1, &stmt, NULL);
        if (result != SQLITE_OK) {
            cout << sqlite3_errmsg(database);
            sqlite3_close(database) ;
            return 2;
        }
        cout << "ID\t" << "Name" << endl;
        do {
            result = sqlite3_step (stmt) ;
            if (result == SQLITE_ROW) { /* can read data */
                char * id  = (char *)malloc(100);
                char * name  = (char *)malloc(100);
                strcpy(id, (char *)sqlite3_column_text(stmt,0)) ;
                strcpy(name, (char *)sqlite3_column_text(stmt,1)) ;
                cout << id << "\t" << name << endl;
            }
        } while (result == SQLITE_ROW) ;
        sqlite3_close(database);
        return 0;
    }
    int insertRecord(string dataName) {
        int result;
            string insertSQL = "INSERT INTO people (name) VALUES ('" + dataName + "');";
            //insert into venues (idvenue,venue) values (0,'Alpha');
            int insertResult = sqlite3_prepare(database, insertSQL.c_str(), insertSQL.size(), &stmt, NULL);
            if (insertResult != SQLITE_OK) {
                cout << sqlite3_errmsg(database) << endl;
                cout << "INSERT ERROR" << endl;
                return 1;
            }
            result = sqlite3_step (stmt);
        return 0;
    }
};
#endif /* defined(__firstMacC__Database__) */
