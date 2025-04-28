#include <iostream>
#include <string>
using namespace std;

class DiningHall {
private:
    int hallId;
    string name;
    string address;
    int capacity;
public:
    DiningHall();
    DiningHall(int, string, string, int);
    void setHallId(int);
    int getHallId() const;
    void setHallName(const string&);
    string getHallName() const;
    void setAddress(const string&);
    string getAddress() const;
    void setCapacity(int);
    int getCapacity() const;
};
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
