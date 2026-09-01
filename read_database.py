#simple function for reading employee information from text file and saving it as employee object list.

import employee

def read_database():
    with open("Employee_data.txt", "r") as f:
        lines = [line.strip() for line in f if line.strip()]  #splitting names into firstname and lastname. 
        #maybe unnecessary, didn't use firstname and lastname independently anywhere
        #didn't want to rewrite the name entry function, though that would've been easier anyway.

    employee_data = [lines[i:i+3] for i in range(0, len(lines), 3)]
    return [employee.employee(employeeID=data[0], firstname=data[1].split()[0], lastname=data[1].split()[1], salary=float(data[2])) for data in employee_data]
    #reading data in batches of 3 lines, creating employee objects from each batch, and returning a list of those objects