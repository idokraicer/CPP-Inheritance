//
// Created by idok on 1/9/23.
//

#ifndef EX5_POLITICALSYS_H
#define EX5_POLITICALSYS_H
#include "Politician.h"
#include "Party.h"
#include "DemocraticParty.h"
#include "RepublicanParty.h"
#include <string>
#include <fstream>
#include <sstream>
#include <limits>
#include <bits/stdc++.h>


class PoliticalSys {
private:
    vector<Party*> _parties;
    vector<Politician*> _politicians;
    vector<Politician*> _democrats;
    vector<Politician*> _republicans;
    vector<RepublicanParty*> _republicanParties;
    vector<DemocraticParty*> _democraticParties;
    vector<Party*> _biggestParty;
public:
    PoliticalSys(char *string1);
    void addParty();
    void addParty(string, char);
    void addPolitician();
    void addRepublican(Politician* republican);
    void addDemocratic(Politician* democratic);
    void addRepublicanParty(RepublicanParty* republicanParty);
    void addDemocraticParty(DemocraticParty* democraticParty);
    void printParties();
    void printPoliticians();
    void printDemocrats();
    void printRepublicans();
    void printRepublicanParties();
    void printDemocraticParties();
    friend ostream& operator<<(ostream& os, const PoliticalSys& politicalSys);
    void addRepublicanToParty(Politician* r);
    void addDemocraticToParty(Politician* d);
    void removePolitician();

    void removeParty();

    void elections();

    void BiggestParty();
    virtual ~PoliticalSys();


    bool checkIfValidID(int id);

    bool politicianInVector(vector<Politician *> politicians, Politician *politician);

    bool checkIfValidParty(string basicString);

    void heapifyBiggestVector();
};


#endif //EX5_POLITICALSYS_H
