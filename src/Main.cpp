#include <iostream>
#include "Student.h"
#include "Meal.h"
#include "DiningHall.h"
using namespace std;

int main() {
    Student s1(1, "R123", "Mukhtar Rahimi", "Rahimi110@gmail.com", 10.0, true);
    Student s2(2, "H123", "Ali Hussaini", "Hussaini123@gmail.com", 100.0, true);
    Student s3(3, "H123", "Ali Hashimi", "Hashimi123@gmail.com", 500.0, true);
    DiningHall hall1(4, "Main Hall", "Tarbiat Street", 1000);
    Meal meal1(1, "Khoresht", 45.0, MealType::Dinner);
    Meal meal2(3, "kabab", 60.0, MealType::Lunch);

    s1.reserveMeal(meal1, hall1);
    s2.reserveMeal(meal1, hall1);
    s3.reserveMeal(meal2, hall1);
    s1.print();
    s2.print();
    s3.print();
    return 0;
}
