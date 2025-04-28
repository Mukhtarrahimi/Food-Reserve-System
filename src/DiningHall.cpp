#include "DiningHall.h"
#include <iostream>
// Constructor
DiningHall::DiningHall() {
    hallId = 0;
    name = "";
    address = "";
    capacity = 0;
}

DiningHall::DiningHall(int hid, string hn, string ad, int cp) {
    hallId = hid;
    name = hn;
    address = ad;
    capacity = cp;
}
// Getter & Setter
void DiningHall::setHallId(int id) {
    hallId = id;
}
int DiningHall::getHallId() const {
    return hallId;
}
void DiningHall::setHallName(const string& n) {
    if (!n.empty() && n.length() >= 3)
        name = n;
    else
        cout << "Error! Hall name must be at least 3 characters." << endl;
}

string DiningHall::getHallName() const {
    return name;
}

void DiningHall::setAddress(const string& ad) {
    address = ad;
}

string DiningHall::getAddress() const {
    return address;
}

void DiningHall::setCapacity(int cp) {
    capacity = cp;
}

int DiningHall::getCapacity() const {
    return capacity;
}
