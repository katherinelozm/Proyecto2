#include "client.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

Client::Client(string name, string birthday, string gender)
    :name(name), birthday(birthday), gender(gender){

}

Client::~Client(){

}

string Client::toString() const{
    stringstream ss;
    (gender == "Masculine") ? (ss << "Mr. ") : (ss << "Ms. ");
    ss << name << "  ";
    return ss.str();
}

string Client::getName() const{
    return name;
}

string Client::getBirthDay() const{
    return birthday;
}

string Client::getGender() const{
    return gender;
}

double Client::getDiscount(){
    return 0.0;
}

double Client::getTips(){
    return 0.0;
}

void Client::setName(string name){
    this->name = name;
}

void Client::setBirthday(string birthday){
    this->birthday = birthday;
}

void Client::setGender(string gender){
    this->gender = gender;
}

double Client::BDay(double sub) const{
    return sub;
}
