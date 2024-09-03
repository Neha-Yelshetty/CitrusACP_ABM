#ifndef SQLCONNECTION_HPP
#define SQLCONNECTION_HPP
#include <iostream>
#include <string>
#include <stdlib.h>
#include <mysql/jdbc.h>
#include <jdbc/mysql_connection.h>
#include <jdbc/mysql_driver.h>
#include <jdbc/cppconn/driver.h>
#include <jdbc/cppconn/exception.h>
#include <jdbc/cppconn/resultset.h>
#include <jdbc/cppconn/statement.h>
using namespace std;

// This class is used to keep the information of all the grovers

class sqlconnection;

class sqlconnection {

    public:

    sqlconnection();

    void insertdataindatabase();

};

#endif