#ifndef CLIENT_H
#define CLIENT_H

#include <string>

using std::string;

class Client{
protected:
    string name;
    string birthday;
    string gender;
public:
    Client(string, string, string);
    ~Client();
    virtual string toString() const;
    string getName() const;
    string getBirthDay() const;
    string getGender() const;
    virtual double getDiscount(double) = 0;
    virtual double getTips(double) = 0;
    void setName(string);
    void setBirthday(string);
    void setGender(string);
    double BDay(double) const;
};

#endif // CLIENT_H
