//
// Created by Andy Nguyen on 30/03/2023.
//

#ifndef CPP_QLKS_DATABASE_H
#define CPP_QLKS_DATABASE_H
#include <iostream>
#include <mysql.h>
#include "vector"
#include "tabulate/table.hpp"

using namespace std;

// Class Database
class Database {
private:
    MYSQL* connection;
public:
    Database();

    ~Database();

    MYSQL_RES* exec_query(const char* query);

    int checkLength(std::string query);

    void showFullTable(const string& table);
    void queryToDatabase(const string query, const string msg = "");
};


#endif //CPP_QLKS_DATABASE_H
