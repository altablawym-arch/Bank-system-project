#pragma once
#include <iostream>
#include <string>
#include "Admin.h"
#include "Employee.h"
using namespace std;

class AdminManager: public Person {
public:
    static void printEmployeeMenu() {
        cout << "\n===== Employee Menu =====" << endl;
        cout << "1. Show all employees" << endl;
        cout << "2. Add employee" << endl;
        cout << "3. Remove employee" << endl;
        cout << "4. Update employee" << endl;
        cout << "5. Logout" << endl;
    }

    static Admin* login(int id, string password) {
        for (auto& a : Admin::admins) {
            if (a.getid() == id && a.getpassword() == password) {
                return &a;
            }
        }
        return nullptr;
    }

    static bool AdminOptions(Admin* admin) {
        while (true) {
            printEmployeeMenu();
            int choice;
            cout << "\nEnter choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                admin->listEmployees();
                break;
            case 2:
                admin->addEmployee();
                break;
            case 3:
                admin->removeEmployee();
                break;
            case 4:
                admin->updateEmployee();
                break;
            case 5:
                return false;
            default:
                cout << "Invalid choice!" << endl;
            }
        }
        return true;
    }
};



