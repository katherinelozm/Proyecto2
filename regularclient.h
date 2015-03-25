#ifndef REGULARCLIENT_H
#define REGULARCLIENT_H

#include <string>
#include "client.h"

using std::string;

class RegularClient : public Client{
public:
    RegularClient(string, string, string);
    ~RegularClient();
    virtual string toString() const;
    virtual double getDiscount();
    virtual double getTips();
    string save() const;
};

#endif // REGULARCLIENT_H
