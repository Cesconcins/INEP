#ifndef DBCONNECTION_H
#define DBCONNECTION_H

#include <iostream>
#include <fstream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

// Function declarations
sql::Connection* open_connection();
void close_connection(sql::Connection* conn);

#endif
