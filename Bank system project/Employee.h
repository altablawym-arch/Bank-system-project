#pragma once
/*#include <iostream>
#include<string>
#include <cctype>
#include "Person.h"
#include<vector>
#include "FilesHelper.h"*/ 
#include"Client.h"

class Employee : public Person {
private:
    double salary;

public:
    Employee() {}
    Employee(int id, string name, string password, double salary = 500)
        :Person(id, name, password),
        salary(salary) {
    }
    int getid() {
        return id;
    }

    double getsalary() {
        return salary;
    }

    void setsalary(double salary) {
        this->salary = salary;
    }

    string getname() {
        return name;
    }

    void setpassword(string pass) {
        if (Validation::vapassword(pass)) {
            password = pass;
        }

    }

    string getpassword() {
        return password;
    }



    void addClient(Client& client) {
        FilesHelper fh;
        vectorClient.push_back(client);
        fh.saveClient(client);
    }


    void lestClients() {
        for (auto& c : vectorClient) {
            cout << "The ID Is:" << c.getid() << " || "
                << "Teh Name IS: " << c.getname() << " || "
                << "The Balance Is: " << c.getbalance() << " || " << endl;
        }
    }

    Client* searchClient(int id) {
        for (auto& c : vectorClient) {
            if (c.getid() == id) {
                return&c;
            }
        }
        return nullptr;
    }

    void editClient(int id, string name, string password, double balance) {

        Client* c = searchClient(id);
        if (c ) {
            c->setname(name);
            c->setpassword(password);
            c->setbalance(balance);
        }

        ofstream file("client.txt", ios::trunc);
        if (file.is_open()) {
            for (auto& c : vectorClient) {
                file << c.getid() << ","
                    << c.getname() << ","
                    << c.getpassword() << ","
                    << c.getbalance() << "\n";
            }

            file.close();
            cout << "Client updated successfully.\n";

        }

        else {
            cout << "Client not found.\n";
        }




    }

   
};
 vector<Employee> vectorEmployee;