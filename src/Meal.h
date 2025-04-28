#pragma once
#include <string>
#include <vector>
using namespace std;

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