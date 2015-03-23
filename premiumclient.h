#ifndef PREMIUMCLIENT_H
#define PREMIUMCLIENT_H

#include "client.h"
#include <string>

using std::string;

class PremiumClient : public Client{
    int years;
public:
    PremiumClient(string, string, string, int);
    ~PremiumClient();
    virtual string toString() const;
    int getYears() const;
    void setYears(int);
    virtual double getDiscount(double);
    virtual double getTips(double);
};

#endif // PREMIUMCLIENT_H
