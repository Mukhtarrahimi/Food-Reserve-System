#include <iostream>
#include "Student.h"
#include "Meal.h"
#include "DiningHall.h"
using namespace std;

int main() {
    Student s1(1, "R123", "Mukhtar Rahimi", "Rahimi110@gmail.com", 100.0, true);
    DiningHall hall1(1, "Main Hall", "Tarbiat Street", 1000);
    Meal meal1(1, "steek", 60.0, MealType::Lunch);

    s1.reserveMeal(meal1, hall1);
    s1.print();
    return 0;
}
