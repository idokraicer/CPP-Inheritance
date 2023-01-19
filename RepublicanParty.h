//
// Created by idok on 1/8/23.
//

#ifndef EX5_REPUBLICANPARTY_H
#define EX5_REPUBLICANPARTY_H

#include "Party.h"
#include "Republican.h"

class RepublicanParty : public Party { // Republican party class that inherits from Party
public:
    using Party::Party; // using the constructor of the party
    void print() const override; // print the republican party
    friend class PoliticalSys; // friend class of the political system
};


#endif //EX5_REPUBLICANPARTY_H
