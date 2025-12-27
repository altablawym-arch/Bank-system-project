#pragma once

#include "FilesHelper.h"
#include "DataSourceInterface.h"

class FileManager : public DataSourceInterface {
	FilesHelper fh;
public:
	void addClient(Client c) { fh.saveClient(c); }
	void addEmployee(Employee e) { fh.saveEmployee(e); }
	void addAdmin(Admin a) { fh.saveAdmin(a); }

	void getAllClients() { fh.getClients(); }
	void getAllEmployees() { fh.getEmployees(); }
	void getAllAdmins() { fh.getAdmins(); }

	void removeAllClients() { fh.clearFile("client.txt", "LastClientID.txt"); }
	void removeAllEmployees() { fh.clearFile("employee.txt", "LastEmployeeID.txt"); }
	void removeAllAdmins() { fh.clearFile("admin.txt", "LastAdminID.txt"); }


};

