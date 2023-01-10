//
// Created by idok on 1/9/23.
//

#include "PoliticalSys.h"

bool compareParties(Party *p1, Party *p2) {
    return p1->getSize() <= p2->getSize();
}

bool PoliticalSys::politicianInVector(vector<Politician *> politicians, Politician *politician) {
    for (auto p: politicians) {
        if (p == politician) return true;
    }
    return false;
}

void PoliticalSys::heapifyBiggestVector(){
    make_heap(_biggestParty.begin(), _biggestParty.end(),
              [](Party *a, Party *b) { return compareParties(a, b); });
}

ostream &operator<<(ostream &os, const PoliticalSys &politicalSys) {
    os << "Parties:" << endl;
    for (auto party: politicalSys._parties) {
        party->print();
    }
    os << "Politicians:" << endl;
    for (auto politician: politicalSys._politicians) {
        politician->print();
    }
    return os;
}

void PoliticalSys::addParty() {
    cout << "---Create Party---" << endl;
    string name;
    do {
        cout << "Name: " << endl;
        cin >> name;
        char type;
        cout << "Republican or Democratic party " << endl;
        cin >> type;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Please enter valid details" << endl;
            continue;
        } else if (checkIfValidParty(name)) {
            cout << "Please enter valid details" << endl;
            continue;
        } else {
            if (type == 'R') {
                addParty(name, type);
                for (auto r: _republicans) {
                    addRepublicanToParty(r);
                }
                break;
            } else if (type == 'D') {
                addParty(name, type);
                for (auto d: _democrats) {
                    addDemocraticToParty(d);
                }
                break;
            } else {
                cout << "Please enter valid details" << endl;
                continue;
            }
        }
    } while (true);
}

void PoliticalSys::addPolitician() {
    string firstname;
    cout << "First name: " << endl;
    cin >> firstname;
    string lastname;
    cout << "Last name: " << endl;
    cin >> lastname;
    int id;
    cout << "ID: " << endl;
    cin >> id;
    int power;
    cout << "Power: " << endl;
    cin >> power;
    char RorD;
    cout << "Republican or Democratic person " << endl;
    cin >> RorD;
    char type;
    cout << "Leader or Social " << endl;
    cin >> type;
    if (cin.fail() || (RorD != 'R' && RorD != 'D') || (type != 'L' && type != 'S')
        || (power < 0) || (id < 0) || (firstname.empty()) || (lastname.empty())) {
        cin.clear();
        cout << "Please enter valid details" << endl
             << "First name: " << endl
             << "Last name: " << endl << lastname << endl
             << "ID: " << endl << id << endl
             << "Power: " << endl << power << endl
             << "Republican or Democratic person " << endl << RorD << endl
             << "Leader or Social " << endl << type << endl;
        return;
    }
    Politician *politician;
    if (RorD == 'R') {
        politician = new Republican(firstname, lastname, id, power, type);
        _republicans.push_back((Republican *) politician);
        addRepublicanToParty(politician);
    } else if (RorD == 'D') {
        politician = new Democratic(firstname, lastname, id, power, type);
        _democrats.push_back((Democratic *) politician);
        addDemocraticToParty(politician);
    }
    _politicians.push_back(politician);
}

void PoliticalSys::addRepublican(Politician *republican) {
    _republicans.push_back(republican);
    _politicians.push_back(republican);
}

void PoliticalSys::addDemocratic(Politician *democratic) {
    _democrats.push_back(democratic);
    _politicians.push_back(democratic);
}

void PoliticalSys::removePolitician() {
    cout << "---Remove Politician---" << endl;
    int ID;
    do {
        cout << "Enter the ID: " << endl;
        cin >> ID;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a valid id" << endl;
            continue;
        }
        if (!checkIfValidID(ID)) {
            cout << "Please enter a valid id" << endl;
            continue;
        }
        break;
    } while (true);
    for (auto politician: _politicians) {
        if (politician->getId() == ID) {
            if (politician->getParty() != nullptr) {
                politician->getParty()->removePolitician(politician);
            }
            _politicians.erase(remove(_politicians.begin(), _politicians.end(), politician), _politicians.end());
            this->heapifyBiggestVector();
            if (this->politicianInVector(_republicans, politician)) {
                _republicans.erase(remove(_republicans.begin(), _republicans.end(), politician), _republicans.end());
            }
            if (this->politicianInVector(_democrats, politician)) {
                _democrats.erase(remove(_democrats.begin(), _democrats.end(), politician), _democrats.end());
            }
            delete politician;
            break;
        }
    }

}

void PoliticalSys::removeParty() {
    cout << "---Remove Party---" << endl;
    string name;
    do {
        cout << "Enter party name: " << endl;
        cin >> name;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a valid name" << endl;
            continue;
        }
        if (!checkIfValidParty(name)) {
            cout << "Please enter a valid name" << endl;
            continue;
        }
        break;
    } while (true);
    for (auto party: _parties) {
        if (party->getName() == name) {
            vector<Politician *> ps = party->getPoliticians();
            char type = politicianInVector(_republicans, ps.front()) ? 'R' : 'D';
            for (auto politician: ps) {
                if (type == 'R') {
                    _republicanParties.erase(remove(_republicanParties.begin(), _republicanParties.end(), party),
                                             _republicanParties.end());
                    addRepublicanToParty(politician);
                } else {
                    _democraticParties.erase(remove(_democraticParties.begin(), _democraticParties.end(), party),
                                             _democraticParties.end());
                    addDemocraticToParty(politician);
                }
            }
            _parties.erase(remove(_parties.begin(), _parties.end(), party), _parties.end());
            this->heapifyBiggestVector();
            delete party;
            break;
        }
    }
}

void PoliticalSys::elections() {
    if (_politicians.size() == 0 || _parties.size() == 0) return;
    // _parties are sorted by time in the system, so if there is a tie, the oldest one will win.
    cout << "----Primaries----" << endl;
    for (auto party: _parties) {
        party->preformPrimaries();
        cout << party->getLeader()->getFirstname() << " is the chairman of " << party->getName() << endl;
    }
    cout << "----Elections----" << endl;
    int maxPower = -1;
    Party *maxPowerParty = nullptr;
    for (auto party: _parties) {
        if (party->power() > maxPower) {
            maxPower = party->power();
            maxPowerParty = party;

        }
        cout << "Party: " << party->getName() << ",Power: " << party->power() << endl;
    }
    cout << "----Elections Results----" << endl;
    cout << maxPowerParty->getName() << " party won the elections and " << maxPowerParty->getLeader()->getFirstname()
         << " is the prime minister" << endl;
}

void PoliticalSys::BiggestParty() {
    cout << "----Biggest Party----" << endl;
    Party *front = _biggestParty.front();
    cout << "[" << front->getName() << "," << front->getSize() << "]" << endl;
}

PoliticalSys::PoliticalSys(char *filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "File not found" << endl;
        return;
    }
    string line;
    getline(file, line);
    while (getline(file, line) && line != "Parties:") {
        string firstname;
        string lastname;
        int id;
        int power;
        char RorD;
        char type;
        istringstream ss(line);
        ss >> firstname >> lastname >> id >> power >> RorD >> type;
        Politician *politician;
        if (RorD == 'R') {
            politician = new Republican(firstname, lastname, id, power, type);
            _republicans.push_back(politician);
        } else if (RorD == 'D') {
            politician = new Democratic(firstname, lastname, id, power, type);
            _democrats.push_back(politician);
        }
        _politicians.push_back(politician);
    }
    while (getline(file, line)) { // Read parties
        string name;
        char RorD;
        istringstream ss(line);
        ss >> name >> RorD;
        addParty(name, RorD);
    }

    for (auto republican: _republicans) {
        addRepublicanToParty(republican);
    }
    for (auto democratic: _democrats) {
        addDemocraticToParty(democratic);
    }

    this->heapifyBiggestVector();
}

void PoliticalSys::printPoliticians() {
    for (auto politician: _politicians) {
        politician->print();
    }
}

void PoliticalSys::printParties() {
    for (auto party: _parties) {
        party->print();
//        cout << *party;
    }
}

void PoliticalSys::addParty(string name, char t) {

    if (t == 'R') {
        RepublicanParty *party = new RepublicanParty(name);
        _parties.push_back(party);
        _biggestParty.push_back(party);
        _republicanParties.push_back(party);
    } else if (t == 'D') {
        DemocraticParty *party = new DemocraticParty(name);
        _parties.push_back(party);
        _biggestParty.push_back(party);
        _democraticParties.push_back(party);
    }

}

PoliticalSys::~PoliticalSys() {
    for (auto politician: _politicians) {
        delete politician;
    }
    for (auto party: _parties) {
        delete party;
    }
    _biggestParty.clear();
    _democrats.clear();
    _democraticParties.clear();
    _parties.clear();
    _politicians.clear();
    _republicans.clear();


}

void PoliticalSys::addRepublicanToParty(Politician *r) {
    if (_republicanParties.empty() || r == nullptr) {
        return;
    }
    Party *party = nullptr;
    Party *prevParty = r->getParty();
    int lowestPMembers = numeric_limits<int>::max();
    for (auto p: _republicanParties) {
        if (p->getSize() < lowestPMembers) {
            lowestPMembers = p->getSize();
            party = p;
        }
    }
    if (prevParty != nullptr) {
        prevParty->removePolitician(r);
        r->setParty(nullptr);
    }
    party->addPolitician(r);
    this->heapifyBiggestVector();
}

void PoliticalSys::addDemocraticToParty(Politician *d) {
    if (_democraticParties.empty() || d == nullptr) {
        return;
    }
    Party *party = nullptr;
    Party *prevParty = d->getParty() ? d->getParty() : nullptr;
    int lowestPMembers = numeric_limits<int>::max();
    for (auto p: _democraticParties) {
        if (p->getSize() < lowestPMembers) {
            lowestPMembers = p->getSize();
            party = p;
        }
    }
    if (prevParty != nullptr) {
        prevParty->removePolitician(d);
        d->setParty(nullptr);
    }
    party->addPolitician(d);
    this->heapifyBiggestVector();
}

void PoliticalSys::printDemocraticParties() {
    for (auto party: _democraticParties) {
        party->print();
    }

}

void PoliticalSys::printRepublicanParties() {
    for (auto party: _republicanParties) {
        party->print();
    }

}

bool PoliticalSys::checkIfValidID(int id) {
    if (id < 0) return false;
    for (auto politician: _politicians) {
        if (politician->getId() == id) {
            return true;
        }
    }
    return false;
}

bool PoliticalSys::checkIfValidParty(string basicString) {
    if (basicString.empty()) return false;
    for (auto party: _parties) {
        if (party->getName() == basicString) {
            return true;
        }
    }
    return false;
}
