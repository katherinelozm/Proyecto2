#include "coorporateclient.h"
#include "client.h"
#include <string>
#include <sstream>

using std::string;
using std::stringstream;

CoorporateClient::CoorporateClient(string name, string birthday, string gender, string company)
    :Client(name, birthday, gender), company(company) {

}

CoorporateClient::~CoorporateClient(){

}

string CoorporateClient::toString() const{
    stringstream ss;
    ss << Client::toString() << company;
    return ss.str();
}

string CoorporateClient::getCompany() const{
    return company;
}

void CoorporateClient::setCompany(string company){
    this->company = company;
}

double CoorporateClient::getDiscount(double sub){
    return sub * 0.05;
}

double CoorporateClient::getTips(double sub){
    return sub * 0.15;
}

string CoorporateClient::save() const{
    stringstream ss;
    ss << name << " " << birthday << " " << gender << " " << company;
    return ss.str();
}
