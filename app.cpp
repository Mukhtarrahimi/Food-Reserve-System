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
int main() {
 
    return 0;
}