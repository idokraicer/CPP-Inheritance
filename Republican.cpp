//
// Created by idok on 1/6/23.
//

#include "Republican.h"

Republican::Republican(const string& firstname, const string& lastname, int id, int power, char type)
: Politician(firstname, lastname, id, power) {
    if(type == 'L'){
        inner = new Leader(firstname, lastname, id, power);

    }
    else if(type == 'S'){
        inner = new Social(firstname, lastname, id, power);
    }
}

void Republican::print() const {
    cout << "Republican ";
    inner->print();
}


string Republican::getPoliticianName() const {
    return inner->getFirstname();
}

int Republican::getPowerDuringPrimaries() {
    return inner->getPowerDuringPrimaries();
}

bool Republican::ableToRunForPresident() {
    return inner->ableToRunForPresident();
}

void Republican::Update(Observer *observer) {
    inner->Update(observer);
}
