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
    virtual double getDiscount(double);
    virtual double getTips(double);
};

#endif // REGULARCLIENT_H
