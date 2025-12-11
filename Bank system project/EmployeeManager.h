
#pragma once
#include <iostream>
#include <string>
#include "Employee.h"
#include "FilesHelper.h"
#include "Validation.h"

    using namespace std;

    class EmployeeManager {
    public:

        
        static void printEmployeeMenu() {
            cout << "==== Employee Menu ====\n";
            cout << "1. Add New Client\n";
            cout << "2. List All Clients\n";
            cout << "3. Search For Client\n";
            cout << "4. Edit Client Info\n";
            cout << "5. Logout\n";
        }

       
        static void newClient(Employee* employee) {
            string name, password;
            double balance;

            cout << "Enter client name: ";
            cin >> name;
            cout << "Enter client password: ";
            cin >> password;
            cout << "Enter initial balance: ";
            cin >> balance;

            Client c(0, name, password, balance); 
            employee->addClient(c);
            cout << "Client added successfully.\n";
        }

        
        static void listAllClients(Employee* employee) {
            employee->lestClients();
        }

        
        static void searchForClient(Employee* employee) {
            int id;
            cout << "Enter client ID to search: ";
            cin >> id;
            Client* c = employee->searchClient(id);
            if (c) {
                cout << "Client found:\n";
                c->display();
            }
            else {
                cout << "Client not found.\n";
            }
        }

        
        static void editClientInfo(Employee* employee) {
            int id;
            string name, password;
            double balance;

            cout << "Enter client ID to edit: ";
            cin >> id;
            cout << "Enter new name: ";
            cin >> name;
            cout << "Enter new password: ";
            cin >> password;
            cout << "Enter new balance: ";
            cin >> balance;

            employee->editClient(id, name, password, balance);
        }

        
        static Employee* login(int id, string password) {
            FilesHelper::getEmployees(); 
            for (auto& e : vectorEmployee) {
                if (e.getid() == id && e.getpassword() == password) {
                    cout << "Login successful. Welcome, " << e.getname() << "!\n";
                    return &e;
                }
            }
            cout << "Invalid ID or password.\n";
            return nullptr;
        }

        
        static bool employeeOptions(Employee* employee) {
            if (!employee) return false;

            int choice;
            printEmployeeMenu();
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                newClient(employee);
                break;
            case 2:
                listAllClients(employee);
                break;
            case 3:
                searchForClient(employee);
                break;
            case 4:
                editClientInfo(employee);
                break;
            case 5:
                cout << "Logging out...\n";
                return false;
            default:
                cout << "Invalid choice.\n";
            }
            return true;
        }
    };



