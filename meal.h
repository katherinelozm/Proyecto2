#ifndef MEAL_H
#define MEAL_H

#include <string>

using std::string;

class Meal{
    string name;
    double price;
    string description;
public:
    Meal(string, double, string);
    ~Meal();
    void setName(string);
    void setPrice(double);
    void setDescription(string);
    string toString() const;
    string getName() const;
    double getPrice() const;
    string getDescription() const;
    virtual double tax() const = 0;
};

#endif // MEAL_H
