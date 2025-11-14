#pragma once
#include "Employee.h"

class Admin : public Employee {

public:
    Admin(int id, string name, string password, double salary)
        :Employee(id, name, password, salary) {
    }


    void setsalary(double salary) { // عملت سيت للمرتب عشان الادم يكون اكسس انه يعرف يعدله 
        if (Validation::vaamount(salary)) {

        }
    }
};
