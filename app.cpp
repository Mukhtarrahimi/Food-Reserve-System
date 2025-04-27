#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

class Reservation;
class Meal;
class DiningHall;

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
    bool reserve_meal(Meal meal, DiningHall hall);
    bool cancel_reservation(int reservation_id);

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
// setters & getters
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
        cout << "Low balance!" << endl;
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

// ------------- Reservation Class Section -------------

enum class ReservationStatus { ACTIVE, CANCELLED };
class Reservation {
private:
    int reservationId;
    Student student;    
    DiningHall dHall;
    Meal meal;
    ReservationStatus status;
    time_t createdAt;  

public:
    Reservation();
    Reservation(int, const Student& , const DiningHall& , const Meal& , ReservationStatus , time_t );
    // getter & setter 
    void setReservationId(int id);
    int getReservationId() const;
    void setStudent(const Student& );
    Student getStudent() const;
    void setDiningHall(const DiningHall&);
    DiningHall getDiningHall() const;
    void setMeal(const Meal& );
    Meal getMeal() const;
    void setStatus(ReservationStatus);
    ReservationStatus getStatus() const;
    void setCreatedAt(time_t);
    time_t getCreatedAt() const;

    void print() const;
    bool cancel();
};

// constructor
Reservation::Reservation(){
    reservationId = 0;
    status = ReservationStatus::ACTIVE;
    createdAt = time(0);
}
Reservation::Reservation(int id, const Student& s, const DiningHall& h, const Meal& m, ReservationStatus st, time_t ct){
    reservationId = id;
    student = s;
    dHall = h;
    meal = m;
    status = st;
    createdAt = ct;
}
// getter & setter 
void Reservation::setReservationId(int id) {
    if(id > 0)
        reservationId = id; 
    else
        cout << "Error! invalid id." << endl;
}
int Reservation::getReservationId() const {
    return reservationId; 
}
void Reservation::setStudent(const Student& s) {
     student = s;
}
Student Reservation::getStudent() const { 
    return student; 
}
void Reservation::setDiningHall(const DiningHall& h){
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
    std::cout << "Reservation id: " << reservationId << endl;
    std::cout << "Student name: " << student.getName() << endl;
    std::cout << "Dining hall: " << dHall.getName() << endl;
    std::cout << "Meal: " << meal.getName() << endl;
    if (status == ReservationStatus::ACTIVE) {
    std::cout << "status: active" << std::endl;
    } else {
    std::cout << "status: cancelled" << std::endl;
    }
    std::cout << "Created At: " << ctime(&createdAt);
}

bool Reservation::cancel() {
    if (status == ReservationStatus::CANCELLED) {
        cout << "Reservation is already cancelled." << endl;
        return false;
    }
    status = ReservationStatus::CANCELLED;
    cout << "Reservation cancelled successfully." << endl;
    return true;
}

// ------------- Meal Class Section -------------
enum class MealType {
    Breakfast,
    Lunch,
    Dinner,
};

class Meal {
private:
    int mealId;
    string mealName;
    float price;
    MealType mealType;
    vector<string> sideItems;

public:
    Meal();
    Meal(int, string, float, MealType);

    void setMealId(int);
    int getMealId() const;
    void setMealName(const string&);
    string getMealName() const;
    void setPrice(float);
    float getPrice() const;
    void setMealType(MealType);
    MealType getMealType() const;
    void setSideItems(const vector<string>&);
    void addSideItem(const string&);
    void updatePrice(float);
    vector<string> getSideItems() const;
    void print() const;
};

Meal::Meal() {
    mealId = 0;
    mealName = "";
    price = 0.0;
    mealType = MealType::Breakfast;
}

Meal::Meal(int id, string n, float p, MealType t) {
    mealId = id;
    mealName = n;
    price = p;
    mealType = t;
}

void Meal::setMealId(int id) {
    if (id > 0)
        mealId = id;
    else
        cout << "Invalid meal id." << endl;
}

int Meal::getMealId() const {
    return mealId;
}

void Meal::setMealName(const string& n) {
    mealName = n;
}

string Meal::getMealName() const {
    return mealName;
}

void Meal::setPrice(float p) {
    price = p;
}

float Meal::getPrice() const {
    return price;
}

void Meal::setMealType(MealType mt) {
    mealType = mt;
}

MealType Meal::getMealType() const {
    return mealType;
}

void Meal::setSideItems(const vector<string>& item) {
    sideItems = item;
}
void Meal::addSideItem(const string& item){
    sideItems.push_back(item);
}
void Meal::updatePrice(float newPrice){
    price = newPrice;
}
vector<string> Meal::getSideItems() const {
    return sideItems;
}

void Meal::print() const {
    cout << "Id: " << mealId << endl;
    cout << "Name: " << mealName << endl;
    cout << "Price: " << price << endl;
    cout << "Type: ";
    switch (mealType) {
        case MealType::Breakfast: cout << "Breakfast"; break;
        case MealType::Lunch: cout << "Lunch"; break;
        case MealType::Dinner: cout << "Dinner"; break;
    }

    for (size_t i = 0; i < sideItems.size(); ++i) {
        cout << sideItems[i];
        if (i != sideItems.size() - 1)
            cout << ", ";
    }

    cout << endl;
}

// ------------- DiningHall Class Section -------------
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

// Constructors
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

// Setter & Getter
void DiningHall::setHallId(int id) {
    hallId = id;
}

int DiningHall::getHallId() const {
    return hallId;
}

void DiningHall::setHallName(const string& n) {
    name = n;
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

int main() {
 
    return 0;
}