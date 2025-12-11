#pragma once
#include "Employee.h"
#include<vector>
#include "FilesHelper.h"

class Admin : public Employee {

public:
    Admin(int id, string name, string password, double salary)
        :Employee(id, name, password, salary) {
    }


    void setsalary(double salary) {  
        if (Validation::vaamount(salary)) {

        }
    }


    void addEmployee(Employee& employee) {
        vectorEmployee.push_back(employee);
        FilesHelper::saveEmployee(employee);
    }

    Employee* searchEmployee(int id) {
        for (auto& e : vectorEmployee) {
            if (e.getid() == id) {
                return&e;
            }
        }
        return nullptr;
    }


    void editEmployee(int id, string name, string password, double salary) {
        Employee* e = searchEmployee(id);
        if (e != nullptr) {
            e->setname(name);
            e->setpassword(password);
            e->setsalary(salary);
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
};


extern vector<Admin> vectorAdmin;

