import employee
def read_database():
    with open("Employee_data.txt", "r") as f:
        lines = [line.strip() for line in f if line.strip()]

    employee_data = [lines[i:i+3] for i in range(0, len(lines), 3)]
    return [employee.employee(employeeID=data[0], firstname=data[1].split()[0], lastname=data[1].split()[1], salary=float(data[2])) for data in employee_data]
print(read_database())