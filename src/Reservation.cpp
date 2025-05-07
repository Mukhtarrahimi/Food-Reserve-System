#include "Reservation.h"
#include "Student.h"
#include <iostream>
// Constructor

Reservation::Reservation() {
    reservationId = 0;
    student = nullptr;
    status = ReservationStatus::Active;
    createdAt = time(0);
}
Reservation::Reservation(int id, Student* s, const DiningHall& h, const Meal& m, ReservationStatus st, time_t ct) {
    reservationId = id;
    student = s;
    dHall = h;
    meal = m;
    status = st;
    createdAt = ct;
}
// Getter & Setter
void Reservation::setReservationId(int id) {
    if (id > 0)
        reservationId = id;
    else
        cout << "Error! invalid id." << endl;
}

int Reservation::getReservationId() const {
    return reservationId;
}

void Reservation::setStudent(Student* s) {
    student = s;
}

Student* Reservation::getStudent() const {
    return student;
}

void Reservation::setDiningHall(const DiningHall& h) {
    dHall = h;
}

DiningHall Reservation::getDiningHall() const {
    return dHall;
}

void Reservation::setMeal(const Meal& m) {
    meal = m;
}

Meal Reservation::getMeal() const {
    return meal;
}

void Reservation::setStatus(ReservationStatus st) {
    status = st;
}

ReservationStatus Reservation::getStatus() const {
    return status;
}

void Reservation::setCreatedAt(time_t ct) {
    createdAt = ct;
}

time_t Reservation::getCreatedAt() const {
    return createdAt;
}

void Reservation::print() const {
    cout << "Reservation id: " << reservationId << endl;
    cout << "Student name: " << (student ? student->getName() : "Unknown") << endl;
    cout << "Dining hall: " << dHall.getHallName() << endl;
    cout << "Meal: " << meal.getMealName() << endl;
    cout << "Status: " << (status == ReservationStatus::Active ? "Active" : "Canceled") << endl;
    cout << "Created At: " << ctime(&createdAt);
}

bool Reservation::cancel() {
    if (status == ReservationStatus::Canceled) {
        cout << "Reservation is already cancelled." << endl;
        return false;
    }
    status = ReservationStatus::Canceled;
    cout << "Reservation cancelled successfully." << endl;
    return true;
}
   