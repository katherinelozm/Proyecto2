#include "nonalcoholic.h"
#include "drink.h"
#include <string>

using std::string;

NonAlcoholic::NonAlcoholic(string name, double price, string description)
    :Drink(name, price, description) {

}

NonAlcoholic::~NonAlcoholic(){

}

double NonAlcoholic::tax() const{
    return price * 0.15;
}
