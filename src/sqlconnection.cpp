#include "../headers/sqlconnection.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include <mysql/jdbc.h>
#include <jdbc/mysql_connection.h>
#include <jdbc/mysql_driver.h>
#include <jdbc/cppconn/driver.h>
#include <jdbc/cppconn/exception.h>
#include <jdbc/cppconn/resultset.h>
#include <jdbc/cppconn/statement.h>

using namespace std;
using namespace sql;

sqlconnection::sqlconnection() { 
}

void sqlconnection ::insertdataindatabase() {
  sql::Driver *driver;
  sql::Connection *con;
  sql::Statement *stmt;
  sql::ResultSet *res;

  try{
    driver = get_driver_instance();
    cout<<"Before the call"<<endl;
    con = driver->connect("tcp://172.20.25.35:3306","citrus_user","sacstate2023");
    cout<<"Before the schema"<<endl;
    con->setSchema("Citrus");
    stmt = con->createStatement();
    res = stmt->executeQuery("SELECT 'Hello World!' AS _message");
    while (res->next()) {
        cout << "My SQL replies: ";
        cout << res->getString("_message") << endl;
        cout << "MYSQL says it again: ";
        cout << res->getString(1) << endl;
    }
    delete res;
    delete stmt;
    delete con; 
  }catch(const std::exception& e)
  {
    std::cerr << "An exception occurred: " << e.what() << std::endl;
  }
}