#include <iostream>
#include <string>
#include <vector>
#include "employee.hpp"
#include <fstream>
#include <sstream>

// Function to read lines from a file into a vector
std::vector<std::string> readFile(const std::string &filename) {
    std::vector<std::string> data;
    std::ifstream file(filename);

    if (!file.is_open()) {
        throw std::runtime_error("Error: Could not open file for reading: " + filename);
    }

    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) { // Skip empty lines
            data.push_back(line);
        }
    }

    file.close();
    return data;
}

// Function to write vector contents to a file
void writeToFile(const std::string &filename, const std::vector<std::string> &data) {
    std::ofstream file(filename);

    if (!file.is_open()) {
        throw std::runtime_error("Error: Could not open file for writing: " + filename);
    }

    for (const auto &line : data) {
        file << line << "\n";
    }

    file.close();
}

int main() {
    try {
        // Example: Read from "input.txt" into vector
        std::vector<employee> people = {};
        people = readFile("Employee_data.txt");

        // Display read data
        std::cout << "Data read from file:\n";
        for (const auto &line : people) {
            std::cout << line << "\n";
        }

        // Example: Write vector data to "output.txt"
        writeToFile("output.txt", people);

        std::cout << "\nData successfully written to output.txt\n";
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << "\n";
        return 1;
    }

    return 0;
}

//int main(){
//people = read_database.read_database()

//bool program_on = True;
//std::vector<employee> people = {};
//Call/read existing database?
//Menu for selecting what user wants to do
//while(program_on){
//    std::cout<<"Welcome to the Employee Database. What would you like to do?\n";
//    std::cout<<"1. Add new employee\n2. See existing employee information\n3. Exit program\n";
//    std::cin>>menu_choice_main;
//    //add new employee
//    if menu_choice_main == "1":
//        you = employee.employee();
//        //functions for collecting employee information
//        you.getID();
//        while any(person.employeeID == you.employeeID for person in people):
//            std::cout<<"Employee ID already taken. Please try again.\n";
//            you.getID();
//        you.getName();
//        you.getSalary();
//        people.append(you);
//        std::cout<<"Employee "<<you.firstname<<" "<<you.lastname<<" with ID "<<you.employeeID<<" added successfully.\n";
        
//    //see existing employee information
//    if menu_choice_main == "2":
//        std::cout<<"Please enter the employee ID of the employee you would like to display: ";
//        std::cin>>id_input;
//        bool id_not_found = True;
//        for person in people:
//            if person.employeeID == id_input:
//                id_not_found = False;
//                std::cout<<"Employee ID: "<<person.employeeID<<"\nName: "<<person.firstname<<" "<<person.lastname<<"\nSalary: $"<<person.salary<<"\n";
//                //edit?
//                std::cout<<"What would you like to do?\n1. Edit name\n2. Edit salary\n3. Delete employee\n4. Return to main menu\n";
//                std::cin>>menu_choice_edit;
//                //change name
//                if menu_choice_edit == "1":
//                    person.getName();
//                    std::cout<<"Employee name updated to: "<<person.firstname<<" "<<person.lastname<<"\n";
//                elif menu_choice_edit == "2":
//                    person.getSalary();
//                    std::cout<<"Employee salary updated to: $"<<person.salary<<"\n";
//                //delete employee
//                elif menu_choice_edit == "3":
//                    std::cout<<"Are you sure you want to delete this employee? (y/n): ";
//                    std::string delete_choice;
//                    std::cin>>delete_choice;
//                    if delete_choice.lower() == "y":
//                        people.remove(person)
//                        std::cout<<"Employee deleted successfully.\n";
//                //exit edit menu
//                elif menu_choice_edit == "4":
//                    break
//        if id_not_found:
//                std::cout<<"Employee ID not found. Please try again.\n";
//    //exit program
//    if menu_choice_main == "3":
//        std::cout<<"Thank you for using the Employee Database. Goodbye!\n";
//        program_on = False;

//update existing database with new information
//with open("Employee_data.txt", "w") as f:
//    for item in sorted(people, key=lambda x: x.employeeID):
//        f.write(f"{item.employeeID}\n{item.firstname} {item.lastname}\n{item.salary}\n");
//return 0;
//}