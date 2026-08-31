import employee
import read_database
people = read_database.read_database()
#Call/read existing database?
#Menu for selecting what user wants to do
print("Welcome to the Employee Database. Please select an option from the menu below:\n")
print("1. Add new employee information\n2. Display existing employee information\n3. Delete employee information\n4. Exit program")
menu_choice_1 = input("Please enter your choice (1-4): ")
#add new employee
if menu_choice_1 == "1":
    you = employee.employee()
    #functions for collecting employee information
    you.setID(len(people)+1)
    you.getName()
    you.getSalary()
        
#display existing employee
if menu_choice_1 == "2":
    #functions for displaying employee information
    
    #delete employee
        #functions for deleting employee information
#exit program
if menu_choice_1 == "4":
    print("Thank you for using the Employee Database. Goodbye!")
    exit()
else:
    print("Invalid input, please try again")


