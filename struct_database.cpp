#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Employee {
    int id;
    string name;
    double salary;
};

// Read employees from the file
vector<Employee> loadEmployees(const string& filename) {
    vector<Employee> employees;
    ifstream file(filename);

    if (!file) {
        cout << "Could not open " << filename << endl;
        return employees;
    }

    Employee emp;

    while (file >> emp.id) {
        file.ignore();
        getline(file, emp.name);
        file >> emp.salary;

        employees.push_back(emp);
    }

    file.close();
    return employees;
}

// Save employees back to the file
void saveEmployees(const string& filename,
                   const vector<Employee>& employees) {
    ofstream file(filename);

    for (const Employee& emp : employees) {
        file << emp.id << endl;
        file << emp.name << endl;
        file << emp.salary << endl;
    }

    file.close();
}

// Display one employee
void displayEmployee(const Employee& emp) {
    cout << "\nEmployee ID: " << emp.id << endl;
    cout << "Name: " << emp.name << endl;
    cout << "Salary: $" << emp.salary << endl;
}

// Find employee by ID
int findEmployee(const vector<Employee>& employees, int id) {
    for (int i = 0; i < employees.size(); i++) {
        if (employees[i].id == id) {
            return i;
        }
    }

    return -1;
}

int main() {

    const string filename = "Employee_data.txt";

    vector<Employee> employees = loadEmployees(filename);

    int choice;

    do {
        cout << "\n===== Employee Management System =====\n";
        cout << "1. View employee\n";
        cout << "2. Modify employee\n";
        cout << "3. Add employee\n";
        cout << "4. Delete employee\n";
        cout << "5. Display all employees\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice) {

        // --------------------------------
        // VIEW EMPLOYEE
        // --------------------------------
        case 1: {
            int id;

            cout << "Enter employee ID: ";
            cin >> id;

            int index = findEmployee(employees, id);

            if (index == -1) {
                cout << "Employee not found.\n";
            }
            else {
                displayEmployee(employees[index]);
            }

            break;
        }

        // --------------------------------
        // MODIFY EMPLOYEE
        // --------------------------------
        case 2: {
            int id;

            cout << "Enter employee ID to modify: ";
            cin >> id;

            int index = findEmployee(employees, id);

            if (index == -1) {
                cout << "Employee not found.\n";
            }
            else {
                cout << "\nCurrent information:\n";
                displayEmployee(employees[index]);

                cout << "\nEnter new name: ";
                cin.ignore();
                getline(cin, employees[index].name);

                cout << "Enter new salary: ";
                cin >> employees[index].salary;

                saveEmployees(filename, employees);

                cout << "Employee information updated.\n";
            }

            break;
        }

        // --------------------------------
        // ADD EMPLOYEE
        // --------------------------------
        case 3: {
            Employee emp;

            cout << "Enter employee ID: ";
            cin >> emp.id;

            // Check if ID already exists
            if (findEmployee(employees, emp.id) != -1) {
                cout << "An employee with that ID already exists.\n";
                break;
            }

            cout << "Enter employee name: ";
            cin.ignore();
            getline(cin, emp.name);

            cout << "Enter salary: ";
            cin >> emp.salary;

            employees.push_back(emp);

            saveEmployees(filename, employees);

            cout << "Employee added successfully.\n";

            break;
        }

        // --------------------------------
        // DELETE EMPLOYEE
        // --------------------------------
        case 4: {
            int id;

            cout << "Enter employee ID to delete: ";
            cin >> id;

            int index = findEmployee(employees, id);

            if (index == -1) {
                cout << "Employee not found.\n";
            }
            else {
                cout << "\nEmployee to be deleted:\n";
                displayEmployee(employees[index]);

                char confirm;
                cout << "Are you sure? (y/n): ";
                cin >> confirm;

                if (confirm == 'y' || confirm == 'Y') {
                    employees.erase(employees.begin() + index);

                    saveEmployees(filename, employees);

                    cout << "Employee deleted.\n";
                }
                else {
                    cout << "Deletion cancelled.\n";
                }
            }

            break;
        }

        // --------------------------------
        // DISPLAY ALL
        // --------------------------------
        case 5: {
            cout << "\n===== All Employees =====\n";

            if (employees.empty()) {
                cout << "No employees found.\n";
            }
            else {
                for (const Employee& emp : employees) {
                    displayEmployee(emp);
                }
            }

            break;
        }

        // --------------------------------
        // EXIT
        // --------------------------------
        case 6:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    return 0;
}