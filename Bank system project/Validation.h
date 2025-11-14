#pragma once
#include <string>
#include <iostream>
using namespace std;
class Validation
{
public:
    static bool vaname(const string& name) {
        if (name.length() < 3 || name.length() > 20) {
            cout << " name must be between 3 and 20 characters.\n";
            return false;
        }
        for (char a : name) {
            if (!isalpha(a)) { // اضافة المسافة 

                cout << " name must contain only letters.\n";
                return false;
            }
        }
        return true;
    }

    static bool vapassword(const string& password) {
        if (password.length() < 3 || password.length() > 20) {
            cout << "name must be between 3 and 20 characters.\n";
            return false;
        }
        for (char space : password) {
            if (isspace(space)) {
                cout << " password must not  spaces.\n";
                return false;
            }
        }
        return true;
    }

    static bool vaamount(double amount) {
        if (amount <= 0) {
            cout << " AMount must be greater than zero.\n";
            return false;
        }
        return true;
    }

    // 2 فانشكن اقصين 



};

