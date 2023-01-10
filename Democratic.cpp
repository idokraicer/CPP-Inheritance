//
// Created by idok on 1/6/23.
//

#include "Democratic.h"

Democratic::Democratic(const string& firstname, const string& lastname, int id, int power, char type)
        : Politician(firstname, lastname, id, power) {
    if(type == 'L'){
        inner = new Leader(firstname, lastname, id, power);
    }
    else if(type == 'S'){
        inner = new Social(firstname, lastname, id, power);
    }
}

void Democratic::print() const {
    cout << "Democratic ";
    inner->print();
}

string Democratic::getFirstname() const {
    return inner->getFirstname();
}

int Democratic::getPowerDuringPrimaries() {
    return inner->getPowerDuringPrimaries();
}

bool Democratic::ableToRunForPresident() {
    return inner->ableToRunForPresident();
}

void Democratic::Update(Observer *observer) {
    inner->Update(observer);
}