#ifndef COORPORATECLIENT_H
#define COORPORATECLIENT_H

#include "client.h"
#include <string>

using std::string;

class CoorporateClient : public Client{
    string company;
public:
    CoorporateClient(string, string, string, string);
    ~CoorporateClient();
    virtual string toString() const;
    string getCompany() const;
    void setCompany(string);
    virtual double getDiscount();
    virtual double getTips();
    string save() const;
};

#endif // COORPORATECLIENT_H
