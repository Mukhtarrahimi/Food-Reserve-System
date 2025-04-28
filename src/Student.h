#pragma once
#include <vector>
#include <string>
//TODO Required class source files
#include "Reservation.h"
using namespace std;
class Student {
private:
    int userId;
    string studentId;
    string name;
    string email;
    float balance;
    bool isActive;
    vector<Reservation*> reservations;

public:
    Student();
    Student(int, const string&, const string&, const string&, float, bool);
    bool reserveMeal(const Meal&, const DiningHall&);
    bool cancelReservation(int);

    void setReservation(const vector<Reservation*>&);
    vector<Reservation*> getReservation() const;

    void setUserId(int);
    int getUserId() const;

    void setStudentId(const string&);
    string getStudentId() const;

    void setName(const string&);
    string getName() const;

    void setEmail(const string&);
    string getEmail() const;

    void setBalance(float);
    float getBalance() const;

    void setIsActive(bool);
    bool getIsActive() const;

    void print() const;
};