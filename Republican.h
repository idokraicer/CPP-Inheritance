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

class Republican : public Politician{
protected:
    Politician *inner;
public:
    Republican(const string &firstname, const string &lastname, int id, int power, char type);
    void print() const override;
//    friend ostream &operator<<(ostream &os, const Republican &republican);
    string getPoliticianName() const;
    int getPowerDuringPrimaries() override;
    bool ableToRunForPresident() override;
    virtual ~Republican() {
        delete inner;
    };
    void Update(Observer* observer) override;
};


#endif //EX5_REPUBLICAN_H
