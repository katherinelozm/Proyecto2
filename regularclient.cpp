#include "regularclient.h"
#include "client.h"

#include <string>
#include <sstream>

using std::string;
using std::stringstream;

RegularClient::RegularClient(string name, string birthday, string gender)
    :Client(name, birthday, gender){

}

RegularClient::~RegularClient(){

}

string RegularClient::toString() const{
    stringstream ss;
    ss << Client::toString();
    return ss.str();
}

double RegularClient::getDiscount(){
    return 0.0;
}

double RegularClient::getTips(){
    return 0.10;
}

string RegularClient::save() const{
    stringstream ss;
    ss << name << " " << birthday << " " << gender;
    return ss.str();
}
