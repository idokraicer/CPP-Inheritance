//
// Created by idok on 1/8/23.
//

#ifndef EX5_REPUBLICANPARTY_H
#define EX5_REPUBLICANPARTY_H

#include "Party.h"
#include "Republican.h"

class RepublicanParty : public Party {
public:
    using Party::Party;
//    RepublicanParty(string name);
//    friend ostream &operator<<(ostream &os, const RepublicanParty &party);
    void print() const override;
    friend class PoliticalSys;
//    void Update(Observable* observable) override;
};


#endif //EX5_REPUBLICANPARTY_H
