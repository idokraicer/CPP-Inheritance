//
// Created by idok on 1/6/23.
//

#ifndef EX5_LEADER_H
#define EX5_LEADER_H

#include "Politician.h"


using namespace std;

class Leader : public Politician {

public:
//    using Politician::Politician;
    Leader(const string &firstname, const string &lastname,
           int id, int power);
//    virtual ~Leader() = default;

    void print() const override;
    int getPowerDuringPrimaries() override;
    bool ableToRunForPresident() override {return true;}
//    friend ostream& operator<<(ostream& os, const Leader& leader);
};


#endif //EX5_LEADER_H
