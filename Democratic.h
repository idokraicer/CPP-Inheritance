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

class Democratic : public Politician{
protected:
    Politician *inner;
public:
    Democratic(const string &firstname, const string &lastname, int id, int power, char type);
    void print() const override;
//    void Update(Observable* observable) override;
    string getFirstname() const;
    int getPowerDuringPrimaries() override;
    bool ableToRunForPresident() override;
    virtual ~Democratic() {
        delete inner;
    };
    void Update(Observer* observer) override;
};


#endif //EX5_DEMOCRATIC_H
