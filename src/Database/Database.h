//
// Created by Andy Nguyen on 30/03/2023.
//

#ifndef CPP_QLKS_DATABASE_H
#define CPP_QLKS_DATABASE_H
#include <iostream>
#include <mysql.h>
#include "vector"

using namespace std;

class Database {
private:
    MYSQL* connection;
public:
    Database();

    ~Database();

    MYSQL_RES* exec_query(const char* query);

    int checkLength(std::string query);

    void showFullTable(const string& table);
    void queryToDatabase(const string query, const std::string msg);
    void readFromDatabase(const string query);
};


#endif //CPP_QLKS_DATABASE_H
