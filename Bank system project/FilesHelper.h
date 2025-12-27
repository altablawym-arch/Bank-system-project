#pragma once
#include "Parser.h"

class FilesHelper {

public:



	void saveLast(string fileName, int id) {


		ofstream file(fileName);
		if (file.is_open()) {
			file << id << endl;
			file.close();
		}

	}
	int getLast(string fileName) {
		int lastID;
		ifstream file(fileName);
		if (file.is_open()) {
			if (!(file >> lastID)) {
				lastID = 0;
			}
			file.close();
		}

		lastID++;

		ofstream WhritNew(fileName);
		if (WhritNew.is_open()) {
			WhritNew << lastID;
			WhritNew.close();
		}
		return lastID;

	}

	void saveClient(Client c) {

		int newID = getLast("LastClientID.txt");
		ofstream file("client.txt", ios::app);
		if (file.is_open()) {
			file << newID << "," << c.getname() << "," << c.getpassword() << ","
				<< c.getbalance() << "\n\n";
			file.close();
		}
	}

	void saveEmployee(Employee e) {
		int newID = getLast("LastEmployeeID.txt");
		ofstream file("employee.txt", ios::app);
		if (file.is_open()) {
			file << newID << "," << e.getname() << "," << e.getpassword() << ","
				<< e.getsalary() << "\n\n";
			file.close();

		}
	}


	void saveAdmin(Admin a) {
		int newID = getLast("LastAdminID.txt");
		ofstream file("admin.txt", ios::app);

		if (file.is_open()) {
			file << newID << ","
				<< a.getname() << "," << a.getpassword() << ","
				<< a.getsalary() << "\n\n";

			file.close();
		}
	}



	void getClients() {
		vectorClient.clear();

		ifstream file("client.txt");
		string line;


		while (getline(file, line)) {
			vectorClient.push_back(Parser::parseToClient(line));
		}
	}

	void getEmployees() {
		vectorEmployee.clear();						 

		ifstream file("Employee.txt");
		string line;

		while (getline(file, line)) {
			vectorEmployee.push_back(Parser::parseToEmployee(line));
		}
	}


	void getAdmins() {
		vectorAdmin.clear();

		ifstream file("Admin.txt");
		string line;

		while (getline(file, line)) {


			vectorAdmin.push_back(Parser::parseToAdmin(line));
		}
	}


	void clearFile(string fileName, string lastIdFile) {
		ofstream file(fileName, ios::trunc);
		file.close();

		saveLast(lastIdFile, 0);
	}


};
