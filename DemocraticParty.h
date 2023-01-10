//
// Created by idok on 1/8/23.
//

#ifndef EX5_DEMOCRATICPARTY_H
#define EX5_DEMOCRATICPARTY_H


#include "Party.h"
#include "Democratic.h"

class DemocraticParty : public Party {
public:
    using Party::Party;

    void print() const override;

    friend class PoliticalSys;

    virtual ~DemocraticParty();
};


#endif //EX5_DEMOCRATICPARTY_H
