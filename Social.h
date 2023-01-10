//
// Created by idok on 1/6/23.
//

#ifndef EX5_SOCIAL_H
#define EX5_SOCIAL_H

using namespace std;

#include "Politician.h"

class Social : public Politician {
    using Politician::Politician;
public:
//    friend ostream& operator<<(ostream& os, const Social& social);

    void print() const override;
    int getPowerDuringPrimaries() override;
    bool ableToRunForPresident() override {return false;}
};


#endif //EX5_SOCIAL_H
