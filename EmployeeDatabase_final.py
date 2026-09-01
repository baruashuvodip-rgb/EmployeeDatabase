import employee
import read_database

#Call/read existing database?
people = read_database.read_database()

program_on = True

#Menu for selecting what user wants to do
while(program_on):
    print("Welcome to the Employee Database. What would you like to do?\n")
    print("1. Add new employee\n2. See existing employee information\n3. Exit program")
    menu_choice_main = input("Please enter your choice (1-3): ")
    #add new employee
    if menu_choice_main == "1":
        you = employee.employee()
        #functions for collecting employee information
        you.getID()
        while any(person.employeeID == you.employeeID for person in people):
            print("Employee ID already taken. Please try again.")
            you.getID()
        you.getName()
        you.getSalary()
        people.append(you)
        print(f"Employee {you.firstname} {you.lastname} with ID {you.employeeID} added successfully.\n")
        
    #see existing employee information
    if menu_choice_main == "2":
        id_input = input("Please enter the employee ID of the employee you would like to display: ")
        id_not_found = True
        for person in people:
            if person.employeeID == id_input:
                id_not_found = False
                print(f"Employee ID: {person.employeeID}\nName: {person.firstname} {person.lastname}\nSalary: ${person.salary}")
                #edit?
                menu_choice_edit = input("What would you like to do?\n1. Edit name\n2. Edit salary\n3. Delete employee\n4. Return to main menu\n")
                #change name
                if menu_choice_edit == "1":
                    person.getName()
                    print(f"Employee name updated to: {person.firstname} {person.lastname}")
                #change salary
                elif menu_choice_edit == "2":
                    person.getSalary()
                    print(f"Employee salary updated to: ${person.salary}")
                #delete employee
                elif menu_choice_edit == "3":
                    delete_choice = input("Are you sure you want to delete this employee? (y/n): ")
                    if delete_choice.lower() == "y":
                        people.remove(person)
                        print("Employee deleted successfully.")
                #exit edit menu
                elif menu_choice_edit == "4":
                    break
        if id_not_found:
                print("Employee ID not found. Please try again.\n")
    #exit program
    if menu_choice_main == "3":
        print("Thank you for using the Employee Database. Goodbye!\n")
        program_on = False

#update existing database with new information
with open("Employee_data.txt", "w") as f:
    for item in sorted(people, key=lambda x: x.employeeID):
        f.write(f"{item.employeeID}\n{item.firstname} {item.lastname}\n{item.salary}\n")
