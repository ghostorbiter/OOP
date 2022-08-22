#pragma once
#include <string>
#include <list>
#include <map>
#include "Employee.h"

using namespace std;


class Workplace
{
private:
    list<Employee> employees;

public:
    bool AddEmployee(Employee e);
    bool AddEmployee();
    void SortByName();
    Employee MaxSalary() const;
    void RemoveSalaryAbove(int lim);
    void meanSalary(string position) const;
    double meanSalary1(string position) const;
    map<string, double> salaryEqualization() const;
    friend ostream& operator<<(ostream& out, const Workplace& w);

};

class SalaryLimit
{
private:
    int salary;
public:
    SalaryLimit(int lim) : salary(lim) {}

    bool operator() (const Employee& e) {
        return  e.get_Salary() > salary;
    }
};