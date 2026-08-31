import employee
import read_database
people = read_database.read_database()

program_on = True
#Call/read existing database?
#Menu for selecting what user wants to do
while(program_on):
    print("Welcome to the Employee Database. Please select an option from the menu below:\n")
    print("1. Add new employee\n2. Edit existing employee information\n3. Delete employee information\n4. Exit program")
    menu_choice_main = input("Please enter your choice (1-4): ")
    #add new employee
    if menu_choice_main == "1":
        you = employee.employee()
        #functions for collecting employee information
        you.setID(len(people)+1)
        you.getName()
        you.getSalary()
        people.append(you)
        
    #display existing employee
    if menu_choice_main == "2":
        #functions for displaying employee information
        id_input = input("Please enter the employee ID of the employee you would like to display: ")
        for person in people:
            if person.employeeID == id_input:
                print(f"Employee ID: {person.employeeID}\nName: {person.firstname} {person.lastname}\nSalary: ${person.salary}")
                #edit?
                menu_choice_edit = input("What would you like to do?\n1. Edit name\n2. Edit salary\n3. Return to main menu\n")
                if menu_choice_edit == "1":
                    person.getName()
                    print(f"Employee name updated to: {person.firstname} {person.lastname}")
                elif menu_choice_edit == "2":
                    person.getSalary()
                    print(f"Employee salary updated to: ${person.salary}")
                elif menu_choice_edit == "3":
                    break

    #delete employee
    if menu_choice_main == "3":
        #functions for deleting employee information
        id_input = input("Please enter the employee ID of the employee you would like to delete: ")
        for i, person in enumerate(people):
            if person.employeeID == id_input:
                del people[i]
                print("Employee deleted successfully.")
                break
    #exit program
    if menu_choice_main == "4":
        print("Thank you for using the Employee Database. Goodbye!")
        program_on = False
#testing add function
with open("Employee_data.txt", "w") as f:
    for item in people:
        f.write(f"{item.employeeID}\n{item.firstname} {item.lastname}\n{item.salary}\n")

