#pragma once
#include "Employee.h"
//#include "FilesHelper.h"
//
//#include <vector>
//#include <string>
//#include <iostream>
//#include <fstream>
//#include <algorithm>

class Admin : public Employee {

public:
    Admin(int id, string name, string password, double salary)
        :Employee(id, name, password, salary) {
    }


    void setsalary(double salary) {  
        if (Validation::vaamount(salary)) {
            Employee::setsalary(salary);
        }
    }


    void addEmployee(Employee& employee) {

        vectorEmployee.push_back(employee);
        FilesHelper::saveEmployee(employee);
    }

    Employee* searchEmployee(int id) {

        for (auto& e : vectorEmployee) {
            if (e.getid() == id) {
                return &e;
            }
        }
        return nullptr;
    }


    void editEmployee(Employee& data) {
        Employee* e = searchEmployee(data.getid());
        if (e != nullptr) {
            e->setname(data.getname());
            e->setpassword(data.getpassword());
            e->setsalary(data.getsalary());
        }

        ofstream file("employee.txt", ios::trunc);
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

    void listEmployee() {
        for (auto& c : vectorEmployee) {
            cout << "The ID Is:" << c.getid() << " || "
                << "Teh Name IS: " << c.getname() << " || "
                << "The Balance Is: " << c.getsalary() << " || " << endl;
        }
    }

    void removeEmployee() {
        


};


    static vector<Admin> vectorAdmin;



