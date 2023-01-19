//
// Created by idok on 1/6/23.
//

#ifndef EX5_LEADER_H
#define EX5_LEADER_H

#include "Politician.h"


using namespace std;

class Leader : public Politician { // Leader class, inherits from Politician class

public:
    Leader(const string &firstname, const string &lastname,
           int id, int power); // constructor

    void print() const override; // print the politician
    int getPowerDuringPrimaries() override; // get the power of the politician during primaries
    bool ableToRunForPresident() override {return true;} // check if the politician is able to run for president
};


#endif //EX5_LEADER_H
