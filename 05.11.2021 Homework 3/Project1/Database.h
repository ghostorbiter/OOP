#pragma once
#include "Person.h"

class Database
{
	int num_of_people = 0;
	const int max_num_of_people = 20;
	Person** people;
public:
	Database();
	~Database();

	friend ostream& operator<< (ostream & out, const Database& database);
	void add(const Person& person);

	void say_all_managers();
	void say_all_staff();
	void say_all_customers();
};

Database::Database() : people(nullptr)
{
	people = new Person * [max_num_of_people];
	for (int i = 0; i < 20; i++)
		people[i] = nullptr;
}

Database::~Database()
{
	if (people) {
		for (int i = 0; i < max_num_of_people; i++)
			delete people[i];
		delete[] people;
	}
	num_of_people = 0;
}

void Database::add(const Person &person)
{
	try {
		if (num_of_people > max_num_of_people)
			throw max_num_of_people;
		else {
			people[num_of_people] = person.clone();
			num_of_people++;
		}
	}
	catch (int a) {
		cout << "Maximum number of people [" << a << "] in database is reached" << endl;
	}
}

ostream& operator<< (ostream& out, const Database& database)
{
	if (database.num_of_people == 0)
		out << "Database is empty" << endl;
	else {
		for (int i = 0; i < database.num_of_people; i++)
			database.people[i]->info(out);
	}
	return out;
}

void Database::say_all_managers()
{
	Manager* s = nullptr;
	for (int i = 0; i < max_num_of_people; i++)
		if (s = dynamic_cast<Manager*>(people[i])) 
			people[i]->say();
}

void Database::say_all_staff()
{
	Staff* s = nullptr;
	for (int i = 0; i < max_num_of_people; i++)
		if (s = dynamic_cast<Staff*>(people[i]))
			people[i]->say();
}

void Database::say_all_customers()
{
	Customer* s = nullptr;
	for (int i = 0; i < max_num_of_people; i++)
		if (s = dynamic_cast<Customer*>(people[i]))
			people[i]->say();
}