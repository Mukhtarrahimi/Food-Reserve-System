#pragma once
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