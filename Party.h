//
// Created by idok on 1/6/23.
//

#ifndef EX5_PARTY_H
#define EX5_PARTY_H


#include "Politician.h"
#include "Observable.h"
#include <vector>

using namespace std;
class Politician;
class Observable;

class Party : public Observable { // Party class, abstract class for all parties (Democratic, Republican)
    // Inherited from Observable class, so it can be observed by the politicians in the party, which are the observers
private:
    string name; // name of the party
    int size; // number of politicians in the party
public:
    Politician* leader; // the leader of the party
    vector<Politician*> politicians; // vector of all the politicians in the party
    explicit Party(const string& name); // constructor
    bool findLeader(); // Notify observers using NotifyObservers()
    Politician* getLeader(); // Notify observers using NotifyObservers()
    void addPolitician(Politician* politician); // AddObserver
    void removePolitician(Politician* politician); // RemoveObserver
    virtual void print() const; // print the party
    void preformPrimaries(); // preform primaries
    int getSize() const; // get the size of the party
    string getName() const {return name;}; // get the name of the party
    bool operator>(const Party& other) const; // operator overloading for comparing parties
    int power() const; // get the power of the party
//    friend ostream& operator<<(ostream& os, const Party& party);
    vector<Politician *> getPoliticians(); // get the politicians in the party
    void NotifyObservers() override; // Notify observers using NotifyObservers()
};


#endif //EX5_PARTY_H
