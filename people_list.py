import employee 

people = []

morepeople = True

while (morepeople):
    you = employee.person()
    you.getName()
    print("Nice to meet you,",you.firstname,you.lastname,"\b!")
    people.append(you)
    you.getSalary()
    people.append(you)
    print(you.firstname,"'s salary is $",you.salary)
    if (input("Are there more people? (y/n) ") == "n"):
        morepeople = False

print("It was nice meeting you,",people[0].firstname,people[0].lastname,"\b, as well as your",len(people)-1,"friends.")