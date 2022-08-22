#pragma once
#include "Person.h"
#include "staff.h"

class Manager : public Person
{
	Staff** staff;
	int number_of_staff = 0;
	const int max_number_of_staff = 8;
	static int num_of_managers;
public:
	Manager();
	Manager(string name);
	Manager(const Manager& manager);
	virtual ~Manager();

	Manager* clone() const;
	Manager& operator+=(const Staff& _staff);
	virtual ostream& info(ostream& out) const override;
	virtual void general_info() const override;

	void work(const Customer& customer) const;

	virtual void say() const override;
};

int Manager::num_of_managers = 0;

Manager::Manager() : Person(), staff(nullptr)
{
	priviliges = Priviliges::Manager;
	num_of_managers++;

	staff = new Staff * [max_number_of_staff];
	for (int i = 0; i < max_number_of_staff; i++)
		staff[i] = nullptr;
}

Manager::Manager(string _name) : Person(_name), staff(nullptr)
{
	priviliges = Priviliges::Manager;
	num_of_managers++;

	staff = new Staff * [max_number_of_staff];
	for (int i = 0; i < max_number_of_staff; i++)
		staff[i] = nullptr;
}

Manager::Manager(const Manager& manager) : Manager(manager.name)
{
	number_of_staff = manager.number_of_staff;

	for (int i = 0; i < number_of_staff; i++)
		staff[i] = manager.staff[i]->clone();
}

Manager::~Manager()
{
	if (staff) {
		for (int i = 0; i < max_number_of_staff; i++)
			delete staff[i];
		delete[] staff;
	}

	name = "NO NAME";
	priviliges = Priviliges::NONE;
	number_of_staff = 0;
	num_of_managers--;
}

Manager* Manager::clone() const
{
	return new Manager(*this);
}

Manager& Manager::operator+= (const Staff& _staff)
{
	try {
		if (number_of_staff > max_number_of_staff)
			throw max_number_of_staff;
		else {
			staff[number_of_staff] = _staff.clone();
			number_of_staff++;
		}
	}
	catch (int e) {
		cout << "Maximum number of staff [" << e << "] for Manager: " << name << " is reached" << endl;
	}
}

ostream& Manager::info(ostream& out) const
{
	out << name << " " << "Manager" << endl;
	for (int i = 0; i < number_of_staff; i++)
		staff[i]->info(out);
	return out;
}

void Manager::general_info() const
{
	cout << name << endl;
	cout << "		Staff:" << endl;
	for (int i = 0; i < number_of_staff; i++) {
		cout << "		" << i + 1 << ".";
		staff[i]->general_info();
	}
	cout << endl;
}

void Manager::work(const Customer& customer) const
{
	for (int i = 0; i < number_of_staff; i++)
		staff[i]->work(customer);
}

void Manager::say() const
{
	cout << "Manager: " << name << endl;
}