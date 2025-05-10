#include "User.h"
#include <iostream>

using namespace std;

User::User(string userName, string userEmail, string userStudentID) {
    setName(userName);
    setEmail(userEmail);
    setStudentID(userStudentID);
}

string User::getName() const {
    return name;
}

string User::getEmail() const {
    return email;
}

string User::getStudentID() const {
    return studentID;
}

void User::setName(const string& userName) {
    if (userName.empty()) {
        cout << "Error: Name cannot be empty!" << endl;
    } else {
        name = userName;
    }
}

void User::setEmail(const string& userEmail) {
    const regex emailPattern("^[a-zA-Z0-9_+&*-]+(?:\\.[a-zA-Z0-9_+&*-]+)*@(?:[a-zA-Z0-9-]+\\.)+[a-zA-Z]{2,7}$");
    if (regex_match(userEmail, emailPattern)) {
        email = userEmail;
    } else {
        cout << "Error: Invalid email format!" << endl;
    }
}

void User::setStudentID(const string& userStudentID) {
    if (userStudentID.empty()) {
        cout << "Error: Student ID cannot be empty!" << endl;
    } else if (userStudentID.length() != 10) {
        cout << "Error: Student ID must be 10 digits long!" << endl;
    } else {
        for (char c : userStudentID) {
            if (!isdigit(c)) {
                cout << "Error: Student ID must contain only digits!" << endl;
                return;
            }
        }
        studentID = userStudentID;
    }
}

void User::reserveMeal() {
    cout << name << " is reserving a meal." << endl;
}

void User::displayUserInfo() const {
    cout << "Name: " << name << endl;
    cout << "Email: " << email << endl;
    cout << "Student ID: " << studentID << endl;
}
