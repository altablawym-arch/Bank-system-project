#pragma once
#include <iostream>
#include<string>
#include <cctype>
#include "Person.h"

    class Employee : public Person {
    private:
        double salary;

   public:
       Employee(){}
       Employee(int id, string name, string password, double salary=500 )
           :Person(id, name, password),
           salary(salary) {} 
       int getid() {
           return id;
       }

       double getsalary() {
           return salary;
       }

       void setname(string name) {
           if (name.length() < 3 || name.length() > 20) {
               cout << "Enter a name between 3 and 20 characters " << endl;
           }
           else
               cout << "Login Successfully" << endl;
           
           for (char a : name )
               if (!isalpha(a)) {
                   cout << "Name must contain only letters" << endl;
                   return;
             }

           cout << "name is vaild" << endl;
       }

       string getname() {
           return name;
       }

       void setpass(string pass){
           if (pass.length() < 3 || pass.length() > 20)
               cout << "Enter a name between 3 and 20 characters and numbers without spaces " << endl;
       }


       string getpass() {
           return password;
       }

       void addClient() {

       }
};

 