#ifndef DRINK_H
#define DRINK_H

#include <string>

using std::string;

class Drink{
protected:
    string name;
    double price;
    string description;
public:
    Drink(string, double, string);
    ~Drink();
    void setName(string);
    void setPrice(double);
    void setDescription(string);
    string toString() const;
    string getName() const;
    double getPrice() const;
    string getDescription() const;
    virtual double tax() const = 0;
};

#endif // DRINK_H
