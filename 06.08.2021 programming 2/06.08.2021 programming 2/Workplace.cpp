#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <set>
#include "Workplace.h"
using namespace std;

bool Workplace::AddEmployee(Employee e)
{
	/*for (auto it = employees.begin(); it != employees.end(); it++) {
		if (it->FirstName == e.FirstName && it->LastName == e.LastName)
			return false;
	}

	employees.push_back(e);
	return true;*/

	auto pred = [e](const Employee& emp) {
		if (emp.FirstName == e.FirstName && emp.LastName == e.LastName)
			return true;
		return false;
	};

	if (find_if(employees.begin(), employees.end(), pred) == employees.end()) {
		employees.push_back(e);
		return true;
	}
	return false;
}

bool Workplace::AddEmployee()
{
	string fname, lname, pos;
	int sal;
	cout << "Enter First Name, Last Name, Position and Salary" << endl;
	cin >> fname >> lname >> pos >> sal;
	Employee emp(fname, lname, pos, sal);
	if (AddEmployee(emp)) {
		return true;
	}
	return false;
}

ostream& operator<<(ostream& out, const Workplace& w)
{
	auto print = [&out](const Employee& e) {
		out << e;
	};

	for_each(w.employees.begin(), w.employees.end(), print);
	return out;
}

void Workplace::SortByName()
{
	auto cmp = [&](const Employee& s1, const Employee& s2) {
		if (s1.get_lname() == s2.get_lname())
			return s1.get_fname() < s2.get_fname();
		return s1.get_lname() < s2.get_lname();
	};

	employees.sort(cmp);
}

Employee Workplace::MaxSalary() const
{
	auto cmp = [](const Employee& e1, const Employee& e2) {
		return e1.get_Salary() < e2.get_Salary();
	};
	auto maxel = max_element(employees.begin(), employees.end(), cmp);
	return *maxel;
}

void Workplace::RemoveSalaryAbove(int lim)
{
	SalaryLimit sal(lim);
	employees.remove_if(sal);
}

void Workplace::meanSalary(string _position) const
{
	list<Employee> wp;
	auto cp = [_position](const Employee& emp) {
		return (emp.get_pos() == _position);
	};

	//copy_if(employees.begin(), employees.end(), wp, cp);
	copy_if(employees.begin(), employees.end(), inserter(wp, wp.begin()), cp);
	auto print = [](const Employee& e) {
		cout << e;
	};

	for_each(wp.begin(), wp.end(), print);
	auto mean = [](int sum, const Employee& e1) {
		return sum + e1.get_Salary();
	};

	double sem = accumulate(wp.begin(), wp.end(), 0, mean);
	cout << "Mean " << _position << " salary: " << sem / wp.size() << endl;
}

double Workplace::meanSalary1(string _position) const
{
	list<Employee> wp;
	auto cp = [_position](const Employee& emp) {
		return (emp.get_pos() == _position);
	};

	//copy_if(employees.begin(), employees.end(), wp, cp);
	copy_if(employees.begin(), employees.end(), inserter(wp, wp.begin()), cp);
	auto mean = [](int sum, const Employee& e1) {
		return sum + e1.get_Salary();
	};

	double sem = accumulate(wp.begin(), wp.end(), 0, mean);
	return sem / wp.size();
}

map<string, double> Workplace::salaryEqualization() const
{
	map<string, double> mp;
	auto cmp = [&](const Employee& emp) {
		return make_pair(emp.get_pos(), meanSalary1(emp.get_pos()));
	};

	transform(employees.begin(), employees.end(), inserter(mp, mp.begin()), cmp);
	//for_each(mp.begin(), mp.end(), [](const pair<string, double>& s) {cout << s.first << endl;});
	return mp;
}

//Workplace::