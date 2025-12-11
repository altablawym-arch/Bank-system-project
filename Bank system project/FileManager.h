#pragma once
#include<vector>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include <fstream>
#include "FilesHelper.h"
#include "DataSourceInterface.h"

class FileManager : public DataSourceInterface {

public:
  void addClient( Client& c)     {FilesHelper::saveClient(c); }
  void addEmployee(Employee& e)  { FilesHelper::saveEmployee(e); }
  void addAdmin(Admin& a)        { FilesHelper::saveAdmin(a); }

  void getAllClients()           { FilesHelper::getClients(); }
  void getAllEmployees()         { FilesHelper::getEmployees(); }
  void getAllAdmins()             { FilesHelper::getAdmins(); }

  void removeAllClients()      { FilesHelper::clearFile("client.txt", "LastClientID.txt"); }
  void removeAllEmployees()    { FilesHelper::clearFile("employee.txt", "LastEmployeeID.txt"); }
  void removeAllAdmins()       { FilesHelper::clearFile("admin.txt", "LastAdminID.txt"); }


};

