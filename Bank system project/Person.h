#pragma once
#include<iostream>
#include <string>
#include "Validation.h"
using namespace std;


class Person {                     //هنا كلاس عام عشان الكل يورث منه 
protected:
    int id;
    string name;
    string password;

public:
    Person() { id = 0; }
    Person(int id, string name, string password) : id(id), name(name), password(password) {
        //اضافة الفلاديشن 
    };

    int getid() {
        return id;
    }
    string getname() {
        return name;
    }
    string getpassword() {
        return password;
    }
    bool login(int getid, string getpassword) { //فانكشن عشان نسجل الدخول
        if (id == getid && password == getpassword)
            return true;
        else
            return false;
    }

    virtual void display() { // فانكشن اوفررايد تتعدل في باقي الكلاسيسز 
        cout << " person " << endl;
    }

    void setname(const string& name) {
        if (Validation::vaname(name)) {
            this->name = name;
            cout << " Name is valid.\n";
        }
    }

    void setpassword(const string& password) {
        if (Validation::vapassword(password)) {

            this->password = password;

        }
    }

};

