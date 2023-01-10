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

class Party : public Observable {
private:
    string name;
    int size;
public:
    Politician* leader;
    vector<Politician*> politicians;
    explicit Party(const string& name);
    bool findLeader(); // Notify observers using NotifyObservers()
    Politician* getLeader(); // Notify observers using NotifyObservers()
    void addPolitician(Politician* politician); // AddObserver
    void removePolitician(Politician* politician); // RemoveObserver
    virtual void print() const;
    void preformPrimaries();
    int getSize() const;
    string getName() const {return name;};
    bool operator>(const Party& other) const;
    int power() const;
    bool containsPolitician(Politician* politician) const;
//    friend ostream& operator<<(ostream& os, const Party& party);
    vector<Politician *> getPoliticians();
    void NotifyObservers() override;
};


#endif //EX5_PARTY_H
