#pragma once

#include <vector>
#include <memory>
#include "Meal.h"
#include "DiningHall.h"

class Storage {
private:
    int mealIDCounter;
    int diningHallIDCounter;
    vector<Meal> allMeals;
    vector<DiningHall> allDiningHalls;

    Storage();

public:
    static Storage& instance();
    void addMeal(const Meal& meal);
    void addDiningHall(const DiningHall& hall);
    // Delete copy constructor and assignment operator
    Storage(const Storage&) = delete;
    void operator=(const Storage&) = delete;
};
