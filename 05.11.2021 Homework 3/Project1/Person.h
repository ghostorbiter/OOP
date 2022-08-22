#pragma once
#include <iostream>
#include <string>
using namespace std;

enum class Priviliges {
	NONE,
	Customer,
	Staff,
	Manager,
	Boss
};

class Person
{
protected:
	Priviliges priviliges;
	string name;
	static int num_of_people;

public:
	Person();
	Person(string _name);
	Person(const Person& person);
	virtual ~Person();

	virtual Person* clone() const = 0;
	virtual ostream& info(ostream& out) const = 0;
	virtual void general_info() const = 0;
	friend ostream& operator<<(ostream& out, const Person& per);

	virtual void say() const = 0;
};

int Person::num_of_people = 0;

Person::Person() : priviliges(Priviliges::NONE), name("NO NAME")
{
	num_of_people++;
}

Person::Person(string _name) : priviliges(Priviliges::NONE), name(_name)
{
	num_of_people++;
}

Person::Person(const Person& person) : priviliges(person.priviliges), name(person.name)
{
	num_of_people++;
}

Person::~Person() 
{
	priviliges = Priviliges::NONE;
	name = "NO NAME";
	num_of_people--;
}

ostream& operator<< (ostream& out, const Person& per)
{
	if (per.name != "") {
		per.info(out);
		out << endl;
	}
	return out;
}
