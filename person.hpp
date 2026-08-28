#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
#include <string>

class person {
public:
    std::string firstname, lastname;

    person(std::string firstname = "J.", std::string lastname = "Doe") {
    this->firstname = firstname;
    this->lastname = lastname;
    }
    
    void getName() {
        std::string fname, lname;
        std::cout << "Hello, what is your full name? ";
        std::cin >> fname >> lname;
        this->firstname = fname;
        this->lastname = lname;
    }
    void setFirstname(std::string firstname) {
        this->firstname = firstname;
    }
    void setLastname(std::string lastname) {
        this->lastname = lastname;
    }

};

#endif // PERSON_HPP