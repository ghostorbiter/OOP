#pragma once
#include "Person.h"
#include "Manager.h"

class Boss : public Person
{
	Manager** managers;
	int number_of_managers = 0;
	const int max_number_of_managers = 4;
	static int number_of_bosses;
public:
	Boss();
	Boss(string name);
	Boss(const Boss& boss);
	virtual ~Boss();

	virtual Boss* clone() const;
	Boss& operator+= (const Manager& manager);
	virtual ostream& info(ostream& out) const override;

	void work(const Customer& customer) const;

	virtual void general_info() const override;

	virtual void say() const override;
};

int Boss::number_of_bosses = 0;

Boss::Boss() : Person(), managers(nullptr)
{
	try {
		if (!number_of_bosses) {
			priviliges = Priviliges::Boss;
			number_of_bosses++;

			managers = new Manager * [max_number_of_managers];
			for (int i = 0; i < max_number_of_managers; i++)
				managers[i] = nullptr;
		}
		else
			throw "Maximum limit of bosses is reached";
	}
	catch (const char* e) {
		cout << e << endl;
	}
}

Boss::Boss(string _name) : Person(_name), managers(nullptr)
{
	try {
		if (!number_of_bosses) {
			priviliges = Priviliges::Boss;
			number_of_bosses++;

			managers = new Manager * [max_number_of_managers];
			for (int i = 0; i < max_number_of_managers; i++)
				managers[i] = nullptr;
		}
		else
			throw "Maximum limit of bosses is reached";
	}
	catch (const char* e) {
		cout << e << endl;
	}
}

Boss::Boss(const Boss& boss) : Boss(boss.name)
{
	number_of_managers = boss.number_of_managers;

	for (int i = 0; i < number_of_managers; i++)
		managers[i] = boss.managers[i]->clone();
}

Boss::~Boss()
{
	if (managers) {
		for (int i = 0; i < max_number_of_managers; i++)
			delete managers[i];
		delete[] managers;
	}
	
	name = "NO NAME";
	priviliges = Priviliges::NONE;
	number_of_managers = 0;
	number_of_bosses = 0;
}

Boss* Boss::clone() const
{
	return new Boss(*this);
}

Boss& Boss::operator+= (const Manager& manager)
{
	try {
		if (number_of_managers > max_number_of_managers)
			throw max_number_of_managers;
		else {
			managers[number_of_managers] = manager.clone();
			number_of_managers++;
		}
	}
	catch (int e) {
		cout << "Maximum number of managers [" << e << "] for Boss: " << name << " is reached" << endl;
	}
}

ostream& Boss::info(ostream& out) const
{
	out << name << " " << "Boss" << endl;
	for (int i = 0; i < number_of_managers; i++)
		managers[i]->info(out);
	return out;
}

void Boss::work(const Customer& customer) const
{
	for (int i = 0; i < number_of_managers; i++)
		managers[i]->work(customer);
}

void Boss::general_info() const
{
	cout << "Boss" << endl << name << endl;
	cout << "	Managers:" << endl;
	for (int i = 0; i < number_of_managers; i++) {
		cout << "	" << i + 1 << ".";
		managers[i]->general_info();
	}
	cout << endl;
}

void Boss::say() const
{
	cout << "Boss: " << name << endl;
}