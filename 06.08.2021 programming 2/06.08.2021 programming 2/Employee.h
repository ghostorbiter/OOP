#pragma once

#include <iostream>
#include <string>

using namespace std;

class Employee
{
    friend class Workplace;

    string FirstName;
    string LastName;
    string Position;
    int Salary;
public:
    int get_Salary() const { return Salary; }
    string get_fname() const { return FirstName; }
    string get_lname() const { return LastName; }
    string get_pos() const { return Position; }
    Employee(string fn, string ln, string pos, int sal);
    friend ostream& operator<<(ostream& os, const Employee& s);

};
