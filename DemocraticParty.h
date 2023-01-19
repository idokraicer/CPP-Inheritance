//
// Created by idok on 1/8/23.
//

#ifndef EX5_DEMOCRATICPARTY_H
#define EX5_DEMOCRATICPARTY_H


#include "Party.h"
#include "Democratic.h"

class DemocraticParty : public Party { // DemocraticParty class, inherits from Party class
public:
    using Party::Party; // using the constructor of the Party class

    void print() const override; // print the DemocraticParty

    friend class PoliticalSys; // PoliticalSys is a friend class

    virtual ~DemocraticParty(); // destructor
};


#endif //EX5_DEMOCRATICPARTY_H
