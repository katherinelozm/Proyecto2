#ifndef NONALCOHOLIC_H
#define NONALCOHOLIC_H

#include <string>
#include "drink.h"

using std::string;

class NonAlcoholic : public Drink{
public:
    NonAlcoholic(string, double, string);
    ~NonAlcoholic();
    virtual double tax() const;
};

#endif // NONALCOHOLIC_H
