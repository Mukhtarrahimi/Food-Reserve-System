#pragma once
#include <ctime>
//TODO Required class source files
#include "DiningHall.h"
#include "Meal.h"
class Student; // Forward Declaration
using namespace std;

enum class ReservationStatus { Active, Canceled };

class Reservation {
private:
    int reservationId;
    Student* student;
    DiningHall dHall;
    Meal meal;
    ReservationStatus status;
    time_t createdAt;

public:
    Reservation();
    Reservation(int, Student*, const DiningHall&, const Meal&, ReservationStatus, time_t);
    void setReservationId(int);
    int getReservationId() const;
    void setStudent(Student*);
    Student* getStudent() const;
    void setDiningHall(const DiningHall&);
    DiningHall getDiningHall() const;
    void setMeal(const Meal&);
    Meal getMeal() const;
    void setStatus(ReservationStatus);
    ReservationStatus getStatus() const;
    void setCreatedAt(time_t);
    time_t getCreatedAt() const;

    void print() const;
    bool cancel();
};
