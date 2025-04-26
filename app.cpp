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
        cout << "invalid user id!\n";
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
int main() {
 
    return 0;
}