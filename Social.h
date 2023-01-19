//
// Created by idok on 1/6/23.
//

#ifndef EX5_SOCIAL_H
#define EX5_SOCIAL_H

using namespace std;

#include "Politician.h"

class Social : public Politician { // Social class that inherits from Politician
    using Politician::Politician; // using the constructor of the politician
public:

    void print() const override; // print the social
    int getPowerDuringPrimaries() override; // get the power of the social during the primaries
    bool ableToRunForPresident() override {return false;} // check if the social is able to run for president
};


#endif //EX5_SOCIAL_H
