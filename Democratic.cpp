//
// Created by idok on 1/6/23.
//

#include "Democratic.h"

Democratic::Democratic(const string& firstname, const string& lastname, int id, int power, char type)
        : Politician(firstname, lastname, id, power) { // constructor
    if(type == 'L'){
        inner = new Leader(firstname, lastname, id, power); // create a new leader
    }
    else if(type == 'S'){
        inner = new Social(firstname, lastname, id, power); // create a new social
    }
}

void Democratic::print() const { // print the democratic politician
    cout << "Democratic ";
    inner->print(); // print the inner politician
}

string Democratic::getFirstname() const { // get the first name of the politician
    return inner->getFirstname();
}

int Democratic::getPowerDuringPrimaries() { // get the power of the politician during primaries
    return inner->getPowerDuringPrimaries(); // get the power of the inner politician
}

bool Democratic::ableToRunForPresident() { // check if the politician is able to run for president
    return inner->ableToRunForPresident();
}

void Democratic::Update(Observer *observer) { // update the politician, the observer is the leader of the party
    inner->Update(observer); // update the inner politician
}