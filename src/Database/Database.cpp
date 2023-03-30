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
Database::Database(const char* host, const char* user, const char* password, const char* database) {
    connection = mysql_init(NULL);
    if (!mysql_real_connect(connection, host, user, password, database, 0, NULL, 0)) {
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

void Database::showFullTable(const string& table)
{
    string query = "SELECT * FROM " + table + "";
    MYSQL_RES* res = exec_query(query.c_str());
    MYSQL_ROW row;
    while ((row = mysql_fetch_row(res))) {
        for (int i = 0; i < mysql_num_fields(res); i++) {
            std::cout << row[i] << "\t";
        }
        std::cout << std::endl;
    }
    mysql_free_result(res);
}