#pragma once
#include <iostream>
#include <string>
#include "Admin.h"
#include "Employee.h"
using namespace std;

class AdminManager {
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
        for (auto& a : Admin::vectorAdmin) {
            if (a.getid() == id && a.getpassword() == password) {
                return &a;
            }
        }
        return nullptr;
    }

    static bool adminOptions(Admin* admin, Employee e) {

        while (true) {
            printEmployeeMenu();
            int choice;
            cout << "\nEnter choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                admin->listEmployee();
                break;
            case 2:
                admin->addEmployee(e);
                break;
            case 3:
                admin->removeEmployee();   //  متنساش الفانكشن فاضية 
                break;
            case 4:
                admin->editEmployee(e);
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



