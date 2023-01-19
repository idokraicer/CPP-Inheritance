//
// Created by idok on 1/6/23.
//

#include "Republican.h"

Republican::Republican(const string& firstname, const string& lastname, int id, int power, char type)
: Politician(firstname, lastname, id, power) { // constructor of the republican
    if(type == 'L'){ // if the type is L
        inner = new Leader(firstname, lastname, id, power); // create a leader

    }
    else if(type == 'S'){
        inner = new Social(firstname, lastname, id, power); // create a social
    }
}

void Republican::print() const { // print the republican
    cout << "Republican ";
    inner->print(); // print the inner politician
}


string Republican::getPoliticianName() const { // get the name of the republican
    return inner->getFirstname(); // get the name of the inner politician
}

int Republican::getPowerDuringPrimaries() { // get the power of the republican during the primaries
    return inner->getPowerDuringPrimaries(); // get the power of the inner politician
}

bool Republican::ableToRunForPresident() { // check if the republican is able to run for president
    return inner->ableToRunForPresident(); // check if the inner politician is able to run for president
}

void Republican::Update(Observer *observer) { // update the republican, the observer is the leader of the party
    inner->Update(observer); // update the inner politician
}
