//
// Created by idok on 1/6/23.
//

#ifndef EX5_DEMOCRATIC_H
#define EX5_DEMOCRATIC_H


#include "Leader.h"
#include "Social.h"
#include "Politician.h"
#include "Observer.h"
#include "Party.h"
class Party;

class Democratic : public Politician{ // Democratic class, inherits from Politician class
protected:
    Politician *inner; // inner politician
public:
    Democratic(const string &firstname, const string &lastname, int id, int power, char type); // constructor
    void print() const override; // print the democratic politician
    string getFirstname() const; // get the first name of the politician
    int getPowerDuringPrimaries() override; // get the power of the politician during primaries
    bool ableToRunForPresident() override; // check if the politician is able to run for president
    virtual ~Democratic() { // destructor
        delete inner;
    };
    void Update(Observer* observer) override; // update the politician, the observer is the leader of the party
};


#endif //EX5_DEMOCRATIC_H
