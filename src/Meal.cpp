#include <iostream>
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
    if (!n.empty() && n.length() >= 3)
        mealName = n;
    else
        cout << "Error! Meal name must be at least 3 characters." << endl;
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

void Meal::addSideItem(const string& item) {
    sideItems.push_back(item);
}

void Meal::updatePrice(float newPrice) {
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
