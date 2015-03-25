#ifndef BILL_H
#define BILL_H

#include <string>
#include <vector>
#include "meal.h"
#include "drink.h"

using std::string;
using std::vector;

class Bill{
    string text;
    int number;
    string client_name;
    vector<Meal*> meals;
    vector<Drink*> drinks;
    double sub;
    double tax15;
    double tax18;
    double discount;
    double tips;
    double total;
public:
    Bill(string, int, string, vector<Meal*>, vector<Drink*>, double, double, double, double, double, double);
    ~Bill();
    string toString() const;
    string getText() const;
    int getNumber() const;
    string getClientName() const;
    vector<Meal*> getMeals() const;
    vector<Drink*> getDrinks() const;
    double getSub() const;
    double getTax15() const;
    double getTax18() const;
    double getDiscount() const;
    double getTips() const;
    double getTotal() const;
    void setText(string);
    void setNumber(int);
    void setClientName(string);
    void setMeals(vector<Meal*>);
    void setDrinks(vector<Drink*>);
    void setSub(double);
    void setTax15(double);
    void setTax18(double);
    void setDiscount(double);
    void setTips(double);
    void setTotal(double);
    string save_toString() const;
};

#endif // BILL_H
