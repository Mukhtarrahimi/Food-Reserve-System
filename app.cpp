#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

// ------------- Student Class Section -------------
class Student {
private:
    int userId;
    string studentId;
    string name;
    string email;
    float balance;
    bool isActive;
public:
    Student();
    Student(int, const string&, const string&, const string&, float, bool);
    //bool reserve_meal(Meal meal, DiningHall hall);
    //bool cancel_reservation(int reservation_id);

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

// Constructor
Student::Student(){
    userId = 0;
    balance = 0.0;
    isActive = true;
}

Student::Student(int u, const string& s, const string& n, const string& e, float b, bool is)
{
    userId = u;
    studentId = s;
    name = n;
    email = e;
    balance = b;
    isActive = is;
}
// Setters & Getters
void Student::setUserId(int u) {
    if (u <= 0)
        cout << "invalid user id!" << endl;
    else
        userId = u;
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
    if (n.length() >= 3)
        name = n;
    else
        cout << "Error! less 3 characters." << endl;
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
        cout << "low balance!" << endl;
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
         << "Is Active: " << boolalpha << isActive << endl;
}

// ------------- Student Class Section -------------

class Reservation {
private:
    int reservationId;
    Student student;    
   // DiningHall dHall;
    //Meal meal;
  //  ReservationStatus status;
    time_t createdAt;  

public:
     Reservation();
    Reservation(int id, const Student& s, const DiningHall& h, const Meal& m, ReservationStatus st, time_t ct);

};
Reservation::Reservation(){
    reservationId = 0;
    //status =; 
    createdAt = time(0);
}
Reservation(int id, const Student& s, const DiningHall& h, const Meal& m, ReservationStatus st, time_t ct){
    reservationId = id;
    Student = s;
    DiningHall = h;
    Meal = m;
    ReservationStatus = st;
    time_t = ct;
}

int main() {
 
    return 0;
}