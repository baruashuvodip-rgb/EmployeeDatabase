#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "employee.hpp"

using namespace std;

int main() {

    EmployeeDatabase database("Employee_data.txt");

    int choice;
    char editChoice;

    do {

        cout << "\n\n===== Welcome to the Employee Database =====\n";
        cout << "What would you like to do?\n";

        cout << "1. Look up employee\n";
        cout << "2. Add employee\n";
        cout << "3. Delete employee\n";
        cout << "4. Exit\n";

        cout << "\nEnter choice: ";
        cin >> choice;

        int id;

        switch (choice) {
        
        case 1:

            cout << "Enter employee ID: ";
            cin >> id;

            database.displayEmployee(id);

            cout << "press 'e' to edit. press any other key to return to main menu: ";
            cin >> editChoice;

            if (editChoice == 'e') {

                database.modifyEmployee(id);
            }

            break;

        case 2:

            cout << "Enter employee ID: ";
            cin >> id;

            database.addEmployee();

            break;

        case 3:

            cout << "Enter employee ID: ";
            cin >> id;

            database.deleteEmployee(id);

            break;

        case 4:

            cout << "Goodbye!" << endl;

            break;

        default:

            cout << "Invalid choice." << endl;
        }

    } while (choice != 4);

    return 0;
}