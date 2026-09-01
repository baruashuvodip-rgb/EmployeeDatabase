#ifndef EMPLOYEE_HPP
#define EMPLOYEE_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


// =====================================================
// Employee CLASS
// =====================================================

class Employee {

private:
    int id;
    string name;
    double salary;

public:

    Employee(int id, string name, double salary);

    int getID() const;
    string getName() const;
    double getSalary() const;

    void setName(string name);
    void setSalary(double salary);

    void display() const;
};


// Constructor
Employee::Employee(int id, string name, double salary) {

    this->id = id;
    this->name = name;
    this->salary = salary;
}


// Getters
int Employee::getID() const {
    return id;
}

string Employee::getName() const {
    return name;
}

double Employee::getSalary() const {
    return salary;
}


// Setters
void Employee::setName(string name) {
    this->name = name;
}

void Employee::setSalary(double salary) {
    this->salary = salary;
}


// Display employee
void Employee::display() const {

    cout << "Employee ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Salary: $" << salary << endl;
}



// =====================================================
// EmployeeDatabase CLASS
// =====================================================

class EmployeeDatabase {

private:

    vector<Employee> employees;
    string filename;

    int findEmployee(int id);

public:

    EmployeeDatabase::EmployeeDatabase(string filename) {

    this->filename = filename;

    loadFromFile();
}

    void loadFromFile();
    void saveToFile();

    void displayEmployee(int id);
    void displayAll();

    void addEmployee();
    void modifyEmployee(int id);
    void deleteEmployee(int id);
};


// Constructor



// Find employee by ID
int EmployeeDatabase::findEmployee(int id) {

    for (int i = 0; i < employees.size(); i++) {

        if (employees[i].getID() == id) {
            return i;
        }
    }

    return -1;
}


// Load employees from file
void EmployeeDatabase::loadFromFile() {

    ifstream file(filename);

    if (!file) {
        cout << "Could not open " << filename << endl;
        return;
    }

    int id;
    string name;
    double salary;

    while (file >> id) {

        file.ignore();
        getline(file, name);
        file >> salary;

        Employee employee(id, name, salary);

        employees.push_back(employee);
    }

    file.close();
}


// Save employees to file
void EmployeeDatabase::saveToFile() {

    ofstream file(filename);

    if (!file) {
        cout << "Could not open " << filename << endl;
        return;
    }

    for (const Employee& employee : employees) {

        file << employee.getID() << endl;
        file << employee.getName() << endl;
        file << employee.getSalary() << endl;
    }

    file.close();
}


// Display one employee
void EmployeeDatabase::displayEmployee(int id) {

    int index = findEmployee(id);

    if (index == -1) {
        cout << "Employee not found." << endl;
        return;
    }

    cout << "\nEmployee information:\n";
    employees[index].display();
}


// Display all employees
void EmployeeDatabase::displayAll() {

    if (employees.empty()) {
        cout << "No employees in database." << endl;
        return;
    }

    cout << "\n===== All Employees =====\n";

    for (const Employee& employee : employees) {

        cout << "\n------------------\n";

        employee.display();
    }
}


// Add employee
void EmployeeDatabase::addEmployee() {

    int id;
    string name;
    double salary;

    cout << "Enter employee ID: ";
    cin >> id;

    if (findEmployee(id) != -1) {

        cout << "An employee with that ID already exists." << endl;

        return;
    }

    cout << "Enter employee name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter salary: ";
    cin >> salary;

    Employee employee(id, name, salary);

    employees.push_back(employee);
    saveToFile();

    cout << "Employee added successfully." << endl;
}


// Modify employee
void EmployeeDatabase::modifyEmployee(int id) {

    int index = findEmployee(id);

    if (index == -1) {

        cout << "Employee not found." << endl;

        return;
    }

    cout << "\nCurrent information:\n";

    employees[index].display();

    string name;
    double salary;

    cout << "\nEnter new name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter new salary: ";
    cin >> salary;

    employees[index].setName(name);

    employees[index].setSalary(salary);

    saveToFile();

    cout << "Employee updated successfully." << endl;
}


// Delete employee
void EmployeeDatabase::deleteEmployee(int id) {

    int index = findEmployee(id);

    if (index == -1) {

        cout << "Employee not found." << endl;

        return;
    }

    cout << "\nEmployee to delete:\n";

    employees[index].display();

    char choice;

    cout << "\nAre you sure? (y/n): ";
    cin >> choice;

    if (choice == 'y') {

        employees.erase(employees.begin() + index);

        saveToFile();

        cout << "Employee deleted successfully." << endl;
    }
    else {

        cout << "Deletion cancelled." << endl;
    }
}

#endif // EMPLOYEE_HPP