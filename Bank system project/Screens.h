#pragma once
#include <iostream>
//#include <string>
//#include "Admin.h"
//#include "Employee.h"
#include"ClientManger.h"
// add adminmangaer add empmangaer
using namespace std;
class Screens {
public:

    void bankName() {
        cout << "===============================\n";
        cout << "       Rute BANK SYSTEM\n";
        cout << "===============================\n";
    }

    void welcome() {
        bankName();
        cout << "Welcome to the Banking System!\n";
    }

    void loginOptions() {
        cout << "1. Login as Client\n";
        cout << "2. Login as Employee\n";
        cout << "3. Login as Admin\n";
        cout << "4. Exit\n";
    }

    int loginAs() {
        int c;
        cout << "Choose option: ";
        cin >> c;
        return c;
    }

    void invalid(int c) {
        cout << "Invalid option (" << c << ")" << endl;
    }

    void logout() {
        cout << "Logged out successfully!" << endl;
    }

    void loginScreen(int c) {
        int id;
        string password;

        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Password: ";
        cin >> password;

        if (c == 1) {
            Client* client = ClientManager::login(id, password);
            if (client) {
                while (ClientManager::clientOptions(client));
            }
            else {
                cout << "Wrong ID or password .\n";
            }
        }
        else if (c == 2) {
            Employee* emp = EmployeeManager::login(id, password);
            if (emp) {
                while (EmployeeManager::employeeOptions(emp));
            }
            else {
                cout << "Wrong ID or password\n";
            }
        }
        else if (c == 3) {
            Admin* admin = AdminManager::login(id, password);
            if (admin) {
                while (AdminManager::adminOptions(admin));
            }
            else {
                cout << "Wrong ID or password\n";
            }
        }
    }


    static void runApp() {
        while (true) {
            welcome();
            loginOptions();

            int c = loginAs();
            if (c == 3) return;
            if (c < 1 || c > 3) {
                invalid(c);
                continue;
            }

            loginScreen(c);
        }
    }

};