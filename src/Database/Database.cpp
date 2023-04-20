//
// Created by Andy Nguyen on 30/03/2023.
//

#include "Database.h"

/**
 *
 * @param host
 * @param user
 * @param password
 * @param database
 */
Database::Database() {
    connection = mysql_init(NULL);
    if (!mysql_real_connect(connection, "sql.freedb.tech","freedb_vieanhng","83y$EzfEFET6qW8","freedb_quan_ly_khach_san", 0, NULL, 0)) {
        cout << "Error connecting to database: " << mysql_error(connection) << endl;
    }
}

/**
 * Ham huy
 */
Database::~Database() {
    mysql_close(connection);
}

/**
 * Ham chay query sql
 * @param query
 * @return
 */
MYSQL_RES* Database::exec_query(const char* query)
{
    //return true if some error

    if (mysql_query(connection, query)) {
        cout << "Query error: " << mysql_error(connection) << endl;
        exit(1);
    }
    return mysql_use_result(connection);
}

/**
 * Check length of result
 * @param query
 * @return
 */
int Database::checkLength(string query)
{
    int len = 0;
    MYSQL_RES* res = exec_query(query.c_str());
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(res)) != NULL) {
        len++;
    }
    mysql_free_result(res);
    return len;
}


// Ham chay cau lenh sql
void Database::queryToDatabase(const string query,const string msg)
{
    try
    {
        MYSQL_RES* res = exec_query(query.c_str());
        mysql_free_result(res);
        cout << msg;
    }
    catch (const char * msg)
    {
        cout << "Connection error: " << msg << "\n";
    }
}

