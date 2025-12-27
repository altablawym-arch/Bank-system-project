#include<string>
#include<fstream>
#include "Admin.h"
#include <sstream>


class Parser {

public:


 static	vector<string> split(string line) {
		vector<string> result;
		stringstream ss(line);
		string temp;
		while (getline(ss, temp, ',')) {

			result.push_back(temp);
		}

		return result;
	}



	static Client parseToClient(string line) {

		vector <string> part = split(line);

		int id = stoi(part[0]);
		string name = part[1];
		string password = part[2];
		double balance = stod(part[3]);

		Client client(id, name, password, balance);
		return client;
	}



  	static Employee parseToEmployee(string line) {
		vector <string> part = split(line);
		int id = stoi(part[0]);
		string name = part[1];
		string password = part[2];
		double salary = stod(part[3]);

		Employee employee(id, name, password, salary);
		return employee;
	}


    static	Admin parseToAdmin(string line) {
		vector <string> part = split(line);
		int id = stoi(part[0]);
		string name = part[1];
		string password = part[2];
		double salary = stod(part[3]);

		Admin admin(id, name, password, salary);
		return admin;
	}

};

