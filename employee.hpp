#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <iostream>
#include <string>

class employee {
public:
    std::int id;
    std::string firstname, lastname;
    std::float salary;

    employee(std::int id = 0, std::string firstname = "J.", std::string lastname = "Doe", std::float salary = 0.0) {
    this->id = id;
    this->firstname = firstname;
    this->lastname = lastname;
    this->salary = salary;
    }
    
    void setID(std::int id) {
        this->id = id;
    }
    void getSalary() {
        std::cout << "Please Enter Salary: ";
        std::cin >> this->salary;
    }
    void getName() {
        std::string fname, lname;
        std::cout << "Please Enter Full Name: ";
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

#endif // EMPLOYEE_HPP