#include "meal.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

Meal::Meal(string name, double price, string description)
    :name(name), price(price), description(description) {

}

Meal::~Meal(){

}

void Meal::setName(string name){
    this->name = name;
}

void Meal::setPrice(double price){
    this->price = price;
}

void Meal::setDescription(string description){
    this->description = description;
}

string Meal::toString() const{
    stringstream ss;
    ss << name << " - " << description << "             $ " << price;
    return ss.str();
}

string Meal::getName() const{
    return name;
}

double Meal::getPrice() const{
    return price;
}

string Meal::getDescription() const{
    return description;
}

double Meal::tax() const{
    return price * 0.15;
}
