class employee:
    def __init__(self, employeeID="0000", firstname="J.", lastname="Doe", salary=0):
        self.employeeID = employeeID
        self.firstname = firstname
        self.lastname = lastname
        self.salary = salary
    def getName(self):
        self.firstname, self.lastname = input("Please enter full name: ").split();
    def setfirstname(self, firstname):
        self.firstname = firstname
    def setlastname(self, lastname):
        self.lastname = lastname
    def setID(self, employeeID):
        self.employeeID = employeeID
    def getSalary(self):
        self.salary = float(input("Enter salary: "))
    def setSalary(self, salary):
        self.salary = salary
