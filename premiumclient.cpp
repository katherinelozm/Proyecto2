#include "premiumclient.h"
#include "client.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

PremiumClient::PremiumClient(string name, string birthday, string gender, int years)
     :Client(name, birthday, gender), years(years){

}

PremiumClient::~PremiumClient(){

}

string PremiumClient::toString() const{
    stringstream ss;
    ss << Client::toString();
    return ss.str();
}

int PremiumClient::getYears() const{
    return years;
}

void PremiumClient::setYears(int years){
    this->years = years;
}

double PremiumClient::getDiscount(){
    if (years < 5){
        return 5*years/100;
    } else {
        return 0.25;
    }
}

double PremiumClient::getTips(){
    return 0.10;
}

string PremiumClient::save() const{
    stringstream ss;
    ss << name << " " << birthday << " " << gender << " " << years;
    return ss.str();
}
