//
// Created by idok on 1/15/23.
//

#ifndef EX5_ERROR_H
#define EX5_ERROR_H
#include <exception>
#include <string>
#include <cstring>
using namespace std;

class Error : public std::exception {
public:
    virtual const char* what() const noexcept { return output; };
    ~Error() noexcept override { delete[] output;};
protected:
    char* output;
};

class InvalidPoliticianInput : public Error {

public:
    InvalidPoliticianInput(string &firstname, string &lastname, int &id, int &power, char &RorD, char &type) : Error() {
        string o = "Please enter valid details\nFirst name: \n"+ firstname + "\n" +
             "Last name: \n" + lastname + "\n" +
             "ID: \n" + to_string(id) + "\n" +
             "Power: \n" + to_string(power) + "\n" +
             "Republican or Democratic person \n" + RorD + "\n" +
             "Leader or Social \n" + type + "\n";
        delete[] output;
        output = new char[o.length() + 1];
        strcpy(output, o.c_str());
    }
    virtual const char* what() const noexcept {
        return output;
    }
};

class InvalidDetails : public Error {
public:
    InvalidDetails() : Error() {
        string o = "Please enter valid details\n";
        delete[] output;
        output = new char[o.length() + 1];
        strcpy(output, o.c_str());
    }
};

class InvalidID : public Error {
public:
    InvalidID() : Error() {
        string o = "Please enter valid id\n";
        delete[] output;
        output = new char[o.length() + 1];
        strcpy(output, o.c_str());
    }
};

class InvalidName : public Error {
public:
    InvalidName() : Error() {
        string o = "Please enter valid name\n";
        delete[] output;
        output = new char[o.length() + 1];
        strcpy(output, o.c_str());
    }
};


#endif //EX5_ERROR_H
