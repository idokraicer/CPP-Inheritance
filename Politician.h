//
// Created by idok on 1/6/23.
//
#ifndef EX5_POLITICIAN_H
#define EX5_POLITICIAN_H


#include <string>
#include <iostream>
#include "Observer.h"
#include "Party.h"

class Party;
using namespace std;

class Politician : public Observer { // Abstract Politician class
private:
    string firstname;
    string lastname;
    Party *party; // the party of the politician

    int id;
public:
    string getFirstname() const; // get the first name of the politician
    string getLastname() const; // get the last name of the politician
    int getId() const; // get the id of the politician
    Politician *chairman; // the chairman of the party
    int power; // the power of the politician
    Politician(Politician& other); // copy constructor
    Politician(const string& firstname, const string& lastname, int id, int power); // constructor of the politician
    virtual ~Politician() = default; // destructor
    virtual void print() const=0; // print the politician
    virtual int getPowerDuringPrimaries()=0; // get the power of the politician during the primaries
    virtual bool ableToRunForPresident()=0; // check if the politician is able to run for president
    Party *getParty() const; // get the party of the politician
    void setParty(Party *party); // set the party of the politician
    bool operator==(const Politician& other) const; // operator overloading for comparing politicians
    virtual void Update(Observer* observer); // update the politician, the observer is the leader of the party
};


#endif //EX5_POLITICIAN_H
