

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include "Employee.h"
#include "Admin.h"
#include "Client.h"
using namespace std;


int main()
{
    vector<Client>clients;
    clients.push_back(Client(111, "mohamed", "m10", 6000));
    clients.push_back(Client(222, "marwa", "m70", 7000));
    vector< Employee>employees;
    employees.push_back(Employee(777, "fady", "f10", 10000));
    vector<Admin>admins;
    admins.push_back(Admin(999, "zizo", "z10", 15000));

    cout << "**** wellcome to rute bank **** " << endl;

    while (true) {
        int choice;
        cout << "===== Main Menu =====\n";
        cout << "1. Login as Client\n";
        cout << "2. Login as Employee\n";
        cout << "3. Login as Admin\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "enter your ID .\n";

            int id;
            string pass;
            cin >> id;
            cout << "enter your password ." << endl;
            cin >> pass;
            bool logtemp = false;

            Client* currentClient = nullptr;  // حفظ العميل اللي سجل دخول 
            for (Client& a : clients) {


                if (a.login(id, pass)) {
                    cout << "login succssefull" << endl;
                    a.display();
                    logtemp = true;
                    currentClient = &a;
                    break;
                }
            }



            if (currentClient) {
                bool x = true;
                while (x == true) {
                    int clientchoice;
                    cout << "\nClient Menu:\n";
                    cout << "1. Deposit\n";
                    cout << "2. Withdraw\n";
                    cout << "3. Check Balance\n";
                    cout << "4. Logout\n";
                    cout << "Enter your choice: ";
                    cin >> clientchoice;




                    switch (clientchoice) {
                    case 1: {


                        double amount;
                        cout << "Enter amount to deposit: ";
                        cin >> amount;


                        currentClient->deposit(amount);
                        cout << "\nthe update account\n" << endl;
                        currentClient->display();





                    }
                          break;


                    case 4: {
                        x = false; break;
                    }














                    }

                }






                if (logtemp == false) {
                    cout << "Login failed. Wrong ID or password.\n" << endl;
                }
            }
        }





              break;
        case 2: {


            cout << "enter your ID .\n";

            int id;
            string pass;
            cin >> id;
            cout << "enter your password ." << endl;
            cin >> pass;
            bool logtemp1 = false;
            for (Employee a : employees) {
                if (a.login(id, pass)) {
                    cout << "login succssefull" << endl;
                    a.display();
                    logtemp1 = true;
                }
            }
            if (logtemp1 == false) {
                cout << "Login failed. Wrong ID or password.\n" << endl;
            }
        }




              break;
        case 3: {
            cout << "enter your ID .\n";

            int id;
            string pass;
            cin >> id;
            cout << "enter your password ." << endl;
            cin >> pass;
            bool logtemp = false;
            for (Admin a : admins) {
                if (a.login(id, pass)) {
                    cout << "login succssefull" << endl;
                    a.display();
                    logtemp = true;
                }
            }

            if (logtemp == false) {
                cout << "Login failed. Wrong ID or password.\n" << endl;
            }

        }

              break;
        case 4: {
            cout << "Exiting program.\n";
            return 0;

        }


              break;
        default:
            cout << "Invalid choice. Try again.\n";
        }

        cout << "\n___________________________________\n";
    }






}

