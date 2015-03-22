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

void setName(string name){
    this->name = name;
}

void setPrice(double price){
    this->price = price;
}

void setDescription(string description){
    this->description = description;
}

string toString() const{
    stringstream ss;
    ss << name << " - " << description << "                     L. " << price;
    return ss.str();
}

string getName() const{
    return name;
}

double getPrice() const{
    return price;
}

string getDescription() const{
    return description;
}

double tax() const{
    return price * 0.15;
}
