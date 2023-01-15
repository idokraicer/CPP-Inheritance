//
// Created by idok on 1/6/23.
//

#include "Politician.h"
#include "Error.h"


string Politician::getFirstname() const {
    return firstname;
}

string Politician::getLastname() const {
    return lastname;
}

int Politician::getId() const {
    return id;
}

Politician::Politician(const string &firstname, const string &lastname,
                       int id, int power)
                        {
    this->firstname = firstname;
    this->lastname = lastname;
    this->id = id;
    this->power = power;
    this->party = nullptr;
    this->chairman = nullptr;
}

Politician::Politician(Politician &other) {
    this->firstname=other.firstname;
    this->lastname = other.lastname;
    this->id = other.id;
    this->power = other.power;
    this->chairman = other.chairman;

}


void Politician::print() const {

//    cout << "Person:" << this->getFirstname() << " "
//       << this->getLastname() << ", Id:" << this->getId()
//       << ", Power:" << this->power << ", Type:"
//       << 'P' << ", Chairman: " << (this->chairman ?
//                                    this->chairman->getFirstname() :
//                                    "None") << endl;
}

Party *Politician::getParty() const {
    return party;
}

bool Politician::operator==(const Politician &other) const {
    return this->id == other.id;
}

void Politician::setParty(Party *party) {
    this->party = party;
}

void Politician::Update(Observer *observer) {
    this->chairman = dynamic_cast<Politician *>(observer);
}

