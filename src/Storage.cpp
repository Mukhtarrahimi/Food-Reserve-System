#include "Storage.h"

Storage::Storage() : mealIDCounter(0), diningHallIDCounter(0) {}

Storage& Storage::instance() {
    static Storage instance;
    return instance;
}

void Storage::addMeal(const Meal& meal) {
    allMeals.push_back(meal);
}

void Storage::addDiningHall(const DiningHall& hall) {
    allDiningHalls.push_back(hall);
}
