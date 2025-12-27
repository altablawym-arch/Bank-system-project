#pragma once
#include<vector>
#include "Person.h"

class Client : public Person {
private:
    double balance;

public:
    Client() {
        balance = 1500.0;
    }
    Client(int id, string name, string password, double balance)
        :Person(id, name, password), balance(balance) {
    }
    double getbalance() {
        return balance;
    }
    void  setbalance(double balance) {
        this->balance = balance;
    }

    void deposit(double amount) { 
        if (Validation::vaamount(amount)) {
            balance += amount;
            cout << "the new balace is: " << balance << endl;
        }
    }


    void withdraw(double amount) { 
        if (!Validation::vaamount(amount)) return;
        if (amount < balance) {
            balance -= amount;
            cout << "the new balanc is: " << balance << endl;

        }
        else {
            cout << "the balance not enghe " << endl;
        }
    }


    void transferTo(double amount, Client& anther) { 
        int enterid;
        if (!Validation::vaamount(amount)) return;
        if (amount < balance && amount >0) {
            balance -= amount;
            anther.balance += amount;
        }
        else {
            cout << "the balance not enghe " << endl;
        }
    }


    void checkBalance() {  
        cout << "the balance is: " << getbalance() << endl;
    }


    void display()override {  
        cout << "the name is: " << getname() << "\nthe id is: " << getid() <<
            "\nthe balance is: " << getbalance() << endl;
    }


     
};

  static vector<Client> vectorClient;
   