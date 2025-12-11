#pragma once
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include<vector>
#include<string>
using namespace std;
class Parser   {

public:

	static vector<string> split(const string& line) {
		vector<string> result;
		string temp = "";
		for (char ch : line) {
			if (ch != ',') {
				temp += ch;
			}
			else {
				result.push_back(temp);
				temp = "";
			}
		}
		result.push_back(temp);
		return result;
	}



	static Client parseToClient(const string& line)	{
	
		vector <string> part = split(line);

		int id = stoi(part[0]);
		string name = part[1];
		string password = part[2];
		double balance = stod(part[3]);
	
		Client client(id, name, password, balance);
		return client;
	}

	static Employee parseToEmployee(const string& line) {
		vector <string> part = split(line);
		int id = stoi(part[0]);
		string name = part[1];
		string password = part[2];
		double salary = stod(part[3]);

		Employee employee(id, name, password, salary);
		return employee;
	}


	static Admin parseToAdmin(const string& line) {
		vector <string> part = split(line);
		int id = stoi(part[0]);
		string name = part[1];
		string password = part[2];
		double salary = stod(part[3]);

		Admin admin(id, name, password,salary);
		return admin;
	}
};

