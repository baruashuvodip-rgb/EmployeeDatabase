class person:
    def __init__(self, firstname="J.", lastname="Doe", employeeID="0000", salary=0):
        self.firstname = firstname
        self.lastname = lastname
        self.employeeID = employeeID
        self.salary = salary
    def getName(self):
        self.firstname, self.lastname = input("Please enter your full name: ").split();
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
