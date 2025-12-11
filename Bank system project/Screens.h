#pragma once
#include <iostream>
#include <string>
#include "Admin.h"
#include "Employee.h"
using namespace std;
class Screens {
public:
    static void bankName() {
        cout << "===============================\n";
        cout << "       Tablawy BANK SYSTEM\n";
        cout << "===============================\n";
    }

    static void welcome() {
        bankName();
        cout << "Welcome to the Banking System!\n";
    }

    static void loginOptions() {
        cout << "1. Login as Admin" << endl;
        cout << "2. Login as Employee" << endl;
        cout << "3. Exit" << endl;
    }

    static int loginAs() {
        int c;
        cout << "Choose option: ";
        cin >> c;
        return c;
    }

    static void invalid(int c) {
        cout << "Invalid option (" << c << ")" << endl;
    }

    static void logout() {
        cout << "Logged out successfully!" << endl;
    }

    static void loginScreen(int c) {
        int id;
        string pass;

        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Password: ";
        cin >> pass;

        if (c == 1) {
            Admin* a = AdminManager::login(id, pass);
            if (a) {
                cout << "Admin logged in successfully!" << endl;
                AdminManager::AdminOptions(a);
            }
            else cout << "Wrong data!" << endl;

        }
        else if (c == 2) {
            cout << "Employee login not implemented yet!" << endl;
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

