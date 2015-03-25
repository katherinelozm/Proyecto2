#include "drink.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

Drink::Drink(string name, double price, string description)
    :name(name), price(price), description(description) {

}

Drink::~Drink(){

}

void Drink::setName(string name){
    this->name = name;
}

void Drink::setPrice(double price){
    this->price = price;
}

void Drink::setDescription(string description){
    this->description = description;
}

string Drink::toString() const{
    stringstream ss;
    if (description == ""){
        ss << name << "                                $ " << price;
    } else {
        ss << name << " - " << description << "                     $ " << price;
    }
    return ss.str();
}

string Drink::getName() const{
    return name;
}

double Drink::getPrice() const{
    return price;
}

string Drink::getDescription() const{
    return description;
}

double Drink::tax() const{
    return price * 0.15;
}
