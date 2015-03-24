#include "bill.h"
#include <string>
#include <vector>
#include <sstream>
#include "meal.h"
#include "drink.h"

using std::string;
using std::vector;
using std::stringstream;

Bill::Bill(string text, int number, string client_name, vector<Meal*> meals, vector<Drink*> drinks, double sub, double tax15, double tax18, double tips, double total)
    :text(text), number(number), client_name(client_name), meals(meals), drinks(drinks), sub(sub), tax15(tax15), tax18(tax18), tips(tips), total(total) {

}

Bill::~Bill(){

}

string Bill::toString() const{
    stringstream ss;
    ss << text << "\n" << "Bill Number: " << number << "\n" << "Client: " << client_name << "\n\n";
    for (unsigned long i = 0; i < meals.size(); i++)
        ss << meals[i]->toString() << "\n";
    for (unsigned long i = 0; i < drinks.size(); i++)
        ss << drinks[i]->toString() << "\n";
    ss << "\n" << "\n" << "Subtotal:  $ " << sub << "\n";
    ss << "15% Tax:   $ " << tax15 << "\n";
    ss << "18% Tax:   $ " << tax18 << "\n";
    ss << "Tips:      $ " << tips << "\n";
    ss << "Total:     $ " << total << "\n";
    return ss.str();
}

string Bill::getText() const{
    return text;
}

int Bill::getNumber() const{
    return number;
}

string Bill::getClientName() const{
    return client_name;
}

vector<Meal*> Bill::getMeals() const{
    return meals;
}

vector<Drink*> Bill::getDrinks() const{
    return drinks;
}

double Bill::getSub() const{
    return sub;
}

double Bill::getTax15() const{
    return tax15;
}

double Bill::getTax18() const{
    return tax18;
}

double Bill::getTips() const{
    return tips;
}

double Bill::getTotal() const{
    return total;
}

void Bill::setText(string text){
    this->text = text;
}

void Bill::setNumber(int number){
    this->number = number;
}

void Bill::setClientName(string client_name){
    this->client_name = client_name;
}

void Bill::setMeals(vector<Meal*> meals){
    this->meals = meals;
}

void Bill::setDrinks(vector<Drink*> drinks){
    this->drinks = drinks;
}

void Bill::setSub(double sub){
    this->sub = sub;
}

void Bill::setTax15(double tax15){
    this->tax15 = tax15;
}

void Bill::setTax18(double tax18){
    this->tax18 = tax18;
}

void Bill::setTips(double tips){
    this->tips = tips;
}

void Bill::setTotal(double total){
    this->total = total;
}
