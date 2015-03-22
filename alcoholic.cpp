#include "alcoholic.h"
#include "drink.h"
#include <string>

using std::string;

Alcoholic::Alcoholic(string name, double price, string description)
    :Drink(name, price, description) {

}

Alcoholic::~Alcoholic(){

}

double Alcoholic::tax() const{
    return price * 0.18;
}
