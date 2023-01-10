//
// Created by idok on 1/6/23.
//
#ifndef EX5_POLITICIAN_H
#define EX5_POLITICIAN_H


#include <string>
#include <iostream>
#include "Observer.h"
#include "Party.h"

class Party;
using namespace std;

class Politician : public Observer {
private:
    string firstname;
    string lastname;
    Party *party;

    int id;
public:
    string getFirstname() const;
    string getLastname() const;
    int getId() const;
    Politician *chairman;
    int power;
    Politician(Politician& other);
    Politician(const string& firstname, const string& lastname, int id, int power);
    virtual ~Politician() = default;
    virtual void print() const=0;
    virtual int getPowerDuringPrimaries()=0;
    virtual bool ableToRunForPresident()=0;
    Party *getParty() const;
    void setParty(Party *party);
    bool operator==(const Politician& other) const;
    virtual void Update(Observer* observer);
};


#endif //EX5_POLITICIAN_H
