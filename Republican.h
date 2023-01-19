//
// Created by idok on 1/6/23.
//

#ifndef EX5_REPUBLICAN_H
#define EX5_REPUBLICAN_H


#include "Leader.h"
#include "Social.h"
#include "Politician.h"
#include "Observer.h"
#include "Party.h"
class Party;

class Republican : public Politician{ // Republican class that inherits from Politician
protected:
    Politician *inner;
public:
    Republican(const string &firstname, const string &lastname, int id, int power, char type); // constructor of the republican
    void print() const override; // print the republican
    string getPoliticianName() const; // get the name of the republican
    int getPowerDuringPrimaries() override; // get the power of the republican during the primaries
    bool ableToRunForPresident() override; // check if the republican is able to run for president
    virtual ~Republican() { // destructor
        delete inner;
    };
    void Update(Observer* observer) override; // update the republican, the observer is the leader of the party
};


#endif //EX5_REPUBLICAN_H
