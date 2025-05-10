// #ifndef USER_H
// #define USER_H
#pragma once

#include <string>
#include <regex>

using namespace std;

class User {
protected:
    string name;
    string email;
    string studentID;

public:
    User(string userName, string userEmail, string userStudentID);

    string getName() const;
    string getEmail() const;
    string getStudentID() const;

    void setName(const string& userName);
    void setEmail(const string& userEmail);
    void setStudentID(const string& userStudentID);

    virtual void reserveMeal();

    void displayUserInfo() const;
};

// #endif
