//
// Created by idok on 1/6/23.
//

#include "Politician.h"
#include "Error.h"


string Politician::getFirstname() const { // get the first name of the politician
    return firstname;
}

string Politician::getLastname() const { // get the last name of the politician
    return lastname;
}

int Politician::getId() const { // get the id of the politician
    return id;
}

Politician::Politician(const string &firstname, const string &lastname,
                       int id, int power) // constructor of the politician
                        {
    this->firstname = firstname;
    this->lastname = lastname;
    this->id = id;
    this->power = power;
    this->party = nullptr;
    this->chairman = nullptr;
}

Politician::Politician(Politician &other) { // copy constructor
    this->firstname=other.firstname;
    this->lastname = other.lastname;
    this->id = other.id;
    this->power = other.power;
    this->chairman = other.chairman;

}



Party *Politician::getParty() const { // get the party of the politician
    return party;
}

bool Politician::operator==(const Politician &other) const { // operator overloading for comparing politicians
    return this->id == other.id; // two politicians are equal if they have the same id
}

void Politician::setParty(Party *party) { // set the party of the politician
    this->party = party;
}

void Politician::Update(Observer *observer) { // update the politician, the observer is the leader of the party
    this->chairman = dynamic_cast<Politician *>(observer); // set the chairman to the observer that was sent
}

