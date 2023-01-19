//
// Created by idok on 1/15/23.
//

#ifndef EX5_ERROR_H
#define EX5_ERROR_H

#include <exception>
#include <string>
#include <cstring>

using namespace std;

class Error : public std::exception { // Error class, used for throwing errors
public:
    virtual const char *what() const noexcept { return output; }; // what function, returns the error message

    ~Error() noexcept override { delete[] output; }; // destructor
protected:
    char *output; // the error message
};


class InvalidDetails : public Error { // InvalidDetails class, used for throwing error when the details of a politician are invalid
public:
    InvalidDetails() : Error() { // constructor
        string o = "Please enter valid details\n"; // the error message
        delete[] output;
        output = new char[o.length() + 1];
        strcpy(output, o.c_str()); // copy the error message to the output
    }
};

class InvalidID : public Error { // InvalidID class, used for throwing error when the ID is invalid
public:
    InvalidID() : Error() { // constructor
        string o = "Please enter valid id\n"; // the error message
        delete[] output;
        output = new char[o.length() + 1];
        strcpy(output, o.c_str()); // copy the error message to the output
    }
};

class InvalidName : public Error { // InvalidName class, used for throwing error if name is invalid
public:
    InvalidName() : Error() { // constructor
        string o = "Please enter valid name\n";
        delete[] output;
        output = new char[o.length() + 1];
        strcpy(output, o.c_str());
    }
};


#endif //EX5_ERROR_H
