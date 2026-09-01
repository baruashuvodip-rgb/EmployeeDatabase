#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "employee.hpp"

using namespace std;

int main() {

    EmployeeDatabase database("Employee_data.txt");

    int choice;

    do {

        cout << "\n\n===== Employee Database =====\n";

        cout << "1. Look up employee\n";
        cout << "2. Modify employee\n";
        cout << "3. Add employee\n";
        cout << "4. Delete employee\n";
        cout << "5. Display all employees\n";
        cout << "6. Exit\n";

        cout << "\nEnter choice: ";

        cin >> choice;

        int id;

        switch (choice) {

        case 1:

            cout << "Enter employee ID: ";

            cin >> id;

            database.displayEmployee(id);

            break;


        case 2:

            cout << "Enter employee ID: ";

            cin >> id;

            database.modifyEmployee(id);

            break;


        case 3:

            database.addEmployee();

            break;


        case 4:

            cout << "Enter employee ID: ";

            cin >> id;

            database.deleteEmployee(id);

            break;


        case 5:

            database.displayAll();

            break;


        case 6:

            cout << "Goodbye!" << endl;

            break;


        default:

            cout << "Invalid choice." << endl;
        }

    } while (choice != 6);


    return 0;
}