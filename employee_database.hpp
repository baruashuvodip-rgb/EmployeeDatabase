#ifndef EMPLOYEE_DATABASE_HPP
#define EMPLOYEE_DATABASE_HPP

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include "employee.hpp"

class EmployeeDatabase {
private:

    vector<Employee> employee;
    std::string filename;

    int findEmployee(int id);

public:

    EmployeeDatabase(std::string filename);

    void loadFromFile();
    void saveToFile();

    void displayEmployee(int id);
    void displayAll();

    void addEmployee();
    void modifyEmployee(int id);
    void deleteEmployee(int id);
};

EmployeeDatabase::EmployeeDatabase(std::string filename) {

    this->filename = filename;

    loadFromFile();
}


// Find employee by ID
int EmployeeDatabase::findEmployee(int id) {

    for (int i = 0; i < employee.size(); i++) {

        if (employee[i].getID() == id) {
            return i;
        }
    }

    return -1;
}


// Load employee data into vector from file
void EmployeeDatabase::loadFromFile() {

    ifstream file(filename);

    if (!file) {
        std::cout<<"Could not open "<<filename<<std::endl;
        return;
    }

    int id;
    std::string name;
    double salary;

    while (file >> id) {

        file.ignore();

        std::getline(file, name);

        file >> salary;

        Employee employee(id, name, salary);

        employee.push_back(employee);
    }

    file.close();
}


// Save employees to file
void EmployeeDatabase::saveToFile() {

    ofstream file(filename);

    if (!file) {
        std::cout<<"Could not open "<<filename<<std::endl;
        return;
    }

    for (const Employee& employee : employee) {

        file<<employee.getID()<<std::endl;
        file<<employee.getName()<<std::endl;
        file<<employee.getSalary()<<std::endl;
    }

    file.close();
}


// Display employee by id
void EmployeeDatabase::displayEmployee(int id) {

    int index = findEmployee(id);

    if (index == -1) {
        std::cout<<"Employee not found.\n";
        return;
    }

    std::cout<<"\nEmployee information:\n";
    employee[index].display();
}

// Add employee function
void EmployeeDatabase::addEmployee() {

    int id;
    std::string name;
    double salary;

    std::cout<<"Enter employee ID: ";
    std::cin>>id;

    if (findEmployee(id) != -1) {
        std::cout<<"An employee with that ID already exists."<<std::endl;

        return;
    }

    std::cout<<"Enter employee name: ";
    std::cin.ignore();

    std::getline(std::cin, name);

    std::cout<<"Enter salary: ";
    std::cin>>salary;

    Employee employee(id, name, salary);

    employee.push_back(employee);
    saveToFile();

    std::cout<<"Employee added successfully.\n";
}


// Modify employee function
void EmployeeDatabase::modifyEmployee(int id) {

    int index = findEmployee(id);

    if (index == -1) {
        std::cout<<"Employee not found.\n";

        return 0;
    }

    std::cout<<"\nCurrent information:\n";

    employee[index].display();

    std::string name;
    double salary;

    std::cout<<"\nEnter new name: ";

    std::cin.ignore();

    std::getline(std::cin, name);

    std::cout<<"Enter new salary: ";
    std::cin>>salary;

    employee[index].setName(name);
    employee[index].setSalary(salary);

    saveToFile();

    std::cout<<"Employee updated successfully.\n";
}


// Delete employee function
void EmployeeDatabase::deleteEmployee(int id) {

    int index = findEmployee(id);

    if (index == -1) {

        std::cout<<"Employee not found.\n";

        return;
    }

    std::cout<<"\nEmployee to delete:\n";
    Employee employee(id, name, salary);
    employee[index].display();

    //confirm delete
    char choice;

    std::cout<<"\nAre you sure? (y/n): ";
    std::cin>>choice;

    if (choice == 'y') {
        employee.erase(employee.begin() + index);

        saveToFile();

        std::cout<<"Employee deleted successfully.\n";
    }
    else {
        std::cout<<"Deletion cancelled.\n";
    }
}

#endif EMPLOYEE_DATABASE_HPP