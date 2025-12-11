#include <iostream>
#include <string>
#include "Client.h"
#include "Person.h"
#include "FilesHelper.h"
#include "Employee.h"
#include"Validation.h"

using namespace std;

class ClientManager : public Person {
public:
   
    static void printClientMenu() {
        cout << "----- Client Menu -----\n\n";
        cout << "1. View Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Change Password\n";
        cout << "5. Logout\n";
        cout << "-----------------------\n";
    }

    static void updatePassword(Person* person) {
        string newPassword;
        cout << "Enter new password: ";
        cin >> newPassword;
        person->setpassword(newPassword);
        cout << "Password updated successfully.\n";
        
        ofstream file("client.txt", ios::trunc);
        if (file.is_open()) {
            for (auto& c : vectorClient) {
                file << c.getid() << "," << c.getname() << ","
                    << c.getpassword() << "," << c.getbalance() << "\n";
            }
            file.close();
        }
    }                          

    static Client* login(int id, string password) {
        FilesHelper::getClients(); 
        for (auto& c : vectorClient) {
            if (c.getid() == id && c.getpassword() == password) {
                cout << "Login successful. Welcome, " << c.getname() << "\n";
                return &c;
            }
        }
        cout << "Invalid ID or password.\n";
        return nullptr;
    }

    static bool clientOptions(Client* client) {
        if (!client) return false;
        int choice;
        printClientMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            client->checkBalance();
            break;
        case 2: {
            double amount;
            cout << "Enter amount to deposit: ";
            cin >> amount;
            client->deposit(amount);
            break;
        }
        case 3: {
            double amount;
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            client->withdraw(amount);
            break;
        }
        case 4: {
            int targetId;
            double amount;
            cout << "Enter target client ID: ";
            cin >> targetId;
            cout << "Enter amount to transfer: ";
            cin >> amount;

            Client* target = nullptr;
            for (auto& c : vectorClient) {
                if (c.getid() == targetId) {
                    target = &c;
                    break;
                }
            }
            if (target) client->transferTo(amount, *target);
            else cout << "Target client not found.\n";
            break;
        }
        case 5:
            updatePassword(client);
            break;
        case 6:
            cout << "Logging out...\n";
            return false;
        default:
            cout << "Invalid choice.\n";
        }
        return true;
    }
};