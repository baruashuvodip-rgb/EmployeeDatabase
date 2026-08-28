#include <iostream>
#include <string>
#include <vector>
#include "person.hpp"

int main() {

    bool morepeople = true;
    std::vector<person> people;

    while (morepeople) {
        person you;
        you.getName();
        people.push_back(you);
        std::cout << "Nice to meet you, " << you.firstname << " " << you.lastname << "!\n";

        char test;
        std::cout << "Are there any more people? (y/n): ";
        std::cin >> test;

        if (test=='n') {
            morepeople = false;
        }
    }
     std::cout<<"Well, it was nice meeting you, "<<people[0].firstname <<", as well as your "<<people.size()-1<<" friends.\n";
     return 0;
}