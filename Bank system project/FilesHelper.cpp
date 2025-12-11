#include "FilesHelper.h"
#include<fstream>
#include<vector>
#include "Employee.h"
#include"Admin.h"
#include"Client.h"
#include "Person.h"



	void FilesHelper::saveLast(string fileName, int id) {


		ofstream file(fileName);
		if (file.is_open()) {
			file << id;
			file.close();
		}

	}
	int FilesHelper::getLast(string fileName) {
		int lastID;
		ifstream file(fileName);
		if (file.is_open()) {
			if (!(file >> lastID)) {
				lastID = 0;
			}
			file.close();
		}

		lastID++;			  // ?????? ????  id  ????? ????? ??? ???? ???? ??  		

		ofstream WhritNew(fileName);
		if (WhritNew.is_open()) {
			WhritNew << lastID;
			WhritNew.close();
		}
		return lastID;

	}

	void FilesHelper::saveClient(Client c) {

		int newID = getLast("LastClientID.txt");
		ofstream file("client.txt", ios::app);
		if (file.is_open()) {
			file << newID << "," << c.getname() << "," << c.getpassword() << ","
				<< c.getbalance() << "\n\n";
			file.close();
		}
	}

	void FilesHelper::saveEmployee(Employee e) {
		int newID = getLast("LastEmployeeID.txt");
		ofstream file("employee.txt", ios::app);
		if (file.is_open()) {
			file << newID << "," << e.getname() << "," << e.getpassword() << ","
				<< e.getsalary() << "\n\n";
			file.close();

		}
	}


	void FilesHelper::saveAdmin( Admin a) {
		 int newID = getLast("LastAdminID.txt");
		ofstream file("admin.txt", ios::app);

		if (file.is_open()) {
			file << newID << ","
				<< a.getname() << ","<< a.getpassword() << ","
				<< a.getsalary() <<"\n\n";

			file.close();
		}
	}



	void FilesHelper::getClients() {
		vectorClient.clear();  

		ifstream file("client.txt");
		string line;

		while (getline(file, line)) {
			vectorClient.push_back(Parser::parseToClient(line));
		}
	}

	void FilesHelper::getEmployees() {
		vectorEmployee.clear();

		ifstream file("Employee.txt");
		string line;

		while (getline(file, line)) {
			vectorEmployee.push_back(Parser::parseToEmployee(line));
		}
	}


	void FilesHelper::getAdmins() {
		vectorAdmin.clear();

		ifstream file("Admin.txt");
		string line;

		while (getline(file, line)) {
			vectorAdmin.push_back(Parser::parseToAdmin(line));
		}
	}


	void FilesHelper::clearFile(string fileName, string lastIdFile) {
		ofstream file(fileName, ios::trunc);
		file.close();

		saveLast(lastIdFile, 0); 
	}
