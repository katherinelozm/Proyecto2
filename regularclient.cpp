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

double RegularClient::getDiscount(double sub){
    return sub * 0.0;
}

double RegularClient::getTips(double sub){
    return sub * 0.10;
}

