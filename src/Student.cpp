#include "Student.h"
#include <iostream>
#include <ctime>
// Constructor
Student::Student() {
    userId = 0;
    balance = 0.0;
    isActive = true;
}

Student::Student(int u, const string& s, const string& n, const string& e, float b, bool is) {
    userId = u;
    studentId = s;
    name = n;
    email = e;
    balance = b;
    isActive = is;
}
// Distructor
Student::~Student() {
    for (auto res : reservations) {
        delete res;
    }
}

bool Student::reserveMeal(const Meal& meal, const DiningHall& dHall) {
    static int reservationCounter = 1;

    if (balance < meal.getPrice()) {
        lastStatusReservation = "Not enough balance!";
        return false;
    }

    time_t now = time(0);
    tm today = *localtime(&now);

    for (const auto& res : reservations) {
        time_t reservTime = res->getCreatedAt();
        tm reservDate = *localtime(&reservTime);

        if (today.tm_year == reservDate.tm_year &&
            today.tm_yday == reservDate.tm_yday &&
            res->getMeal().getMealType() == meal.getMealType() &&
            res->getStatus() == ReservationStatus::Active) {
            cout << "Already reserved for this meal." << endl;
            return false;
        }
    }

    Reservation* newReservation = new Reservation(
        reservationCounter++, this, dHall, meal, ReservationStatus::Active, now
    );

    reservations.push_back(newReservation);
    balance -= meal.getPrice();
    lastStatusReservation = "Reservation successful!";
    return true;
}

bool Student::cancelReservation(int reservationId) {
    for (auto& res : reservations) {
        if (res->getReservationId() == reservationId) {
            return res->cancel();
        }
    }
    cout << "Not found!" << endl;
    return false;
}

void Student::setReservation(const vector<Reservation*>& newReserv) {
    for (auto res : reservations) {
        delete res;
    }
    reservations.clear();

    for (auto newRes : newReserv) {
        if (newRes != nullptr) {
            reservations.push_back(new Reservation(*newRes));
        }
    }
}

vector<Reservation*> Student::getReservation() const {
    return reservations;
}
// Getter & Setter
void Student::setUserId(int u) {
    if (u > 0)
        userId = u;
    else
        cout << "Invalid user id!" << endl;
}

int Student::getUserId() const {
    return userId;
}

void Student::setStudentId(const string& s) {
    studentId = s;
}

string Student::getStudentId() const {
    return studentId;
}

void Student::setName(const string& n) {
    if (!n.empty() && n.length() >= 3)
        name = n;
    else
        cout << "Error! Name must be at least 3 characters." << endl;
}

string Student::getName() const {
    return name;
}

void Student::setEmail(const string& e) {
    if (e.find('@') != string::npos && e.find('.') != string::npos)
        email = e;
    else
        cout << "Invalid email!" << endl;
}

string Student::getEmail() const {
    return email;
}

void Student::setBalance(float b) {
    if (b >= 0 && b <= 10000)
        balance = b;
    else
        cout << "Invalid balance!" << endl;
}

float Student::getBalance() const {
    return balance;
}

void Student::setIsActive(bool is) {
    isActive = is;
}

bool Student::getIsActive() const {
    return isActive;
}  


void Student::print() const {
    cout << "User ID: " << userId << endl
         << "Student ID: " << studentId << endl
         << "Name: " << name << endl
         << "Email: " << email << endl
         << "Balance: " << balance << endl
         << "Is Active: " << boolalpha << isActive << endl
         << "last Status Reservation: " << lastStatusReservation << endl;

}
