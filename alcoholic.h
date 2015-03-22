#ifndef ALCOHOLIC_H
#define ALCOHOLIC_H

#include <string>
#include "drink.h"

using std::string;

class Alcoholic : public Drink{
public:
    Alcoholic(string, double, string);
    ~Alcoholic();
    virtual double tax() const;
};

#endif // ALCOHOLIC_H
