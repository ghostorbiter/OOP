#include <iostream>
#include <string>
#include <algorithm>
#include "Employee.h"
#include "Workplace.h"
using namespace std;

int main()
{
    Employee employeers[] = {
        Employee("Kazimierz", "Wielki", "programmer", 6000),
        Employee("Major", "Major", "sales manager", 5000),
        Employee("Piotr", "Kowalski", "senior programmer", 11000),
        Employee("Jan", "Kowalski", "junior programmer", 3000),
        Employee("Anna", "Smith", "programmer", 7000),
        Employee("James", "Bond", "senior programmer", 13000),
        Employee("Sherlock", "Holmes", "programmer", 4321),
        Employee("Julius", "Caesar", "CEO", 1200000),
        Employee("Karolina", "Lewandowska", "project manager", 15000),
        Employee("Jan", "Dzban", "programmer", 5000),
    };

    cout << "************************ Part 1 (1 pts) ************************" << endl;
    
    Workplace db;
    for ( auto e : employeers )
        db.AddEmployee(e);

    cout << db << endl;
    
    cout << "************************ Part 2 (1 pts) ************************" << endl;
    
    if (db.AddEmployee(employeers[0]))
        cout << "Something is wrong!!!" << endl;
    else
        cout << "Ok - Employeer alredy added!" << endl;
    cout << endl;
    
    cout << "************************ Part 3 (1 pts) ************************" << endl;
    
   /* if (db.AddEmployee())
        cout << "Ok - Employeer added!" << endl;
    else
        cout << "Something is wrong!!!" << endl;
    cout << db << endl;
    cout << endl;*/
    
    cout << "************************ Part 4 (1 pts) ************************" << endl;
    
    db.SortByName();
    cout << db << endl;
    cout << endl;
    
    cout << "************************ Part 5 (1 pts) ************************" << endl;
    
    cout << db.MaxSalary();
    cout << endl;
    
    cout << "************************ Part 6 (1 pts) ************************" << endl;
    
    db.RemoveSalaryAbove(1000000);
    cout << db << endl;
    cout << endl;
    
    cout << "************************ Part 7 (1 pts) ************************" << endl;
    
    db.meanSalary("programmer");
    cout << endl;
    
    cout << "************************ Part 8 (1 pts) ************************" << endl;
    
    map<string, double> proposition = db.salaryEqualization();
    for_each(proposition.begin(), proposition.end(), [](const pair<string, double>& e) {
        cout << "Proposition of salary equalization" << endl;
        cout << e.first << " - " << e.second << endl;
        });
    cout << endl;
    


    return 0;
}
