#pragma once
#include "Person.h"
#include "Customer.h"

class Staff : public Person
{
	Customer** customers;
	int number_of_customers = 0;
	const int max_number_of_customers = 10;	
	static int num_of_staff;
	float total_money = 0;
public:
	Staff();
	Staff(string name);
	Staff(const Staff& staff);
	virtual ~Staff();

	Staff* clone() const;
	Staff& operator+=(const Customer& customer);
	virtual ostream& info(ostream& out) const override;
	virtual void general_info() const override;

	void work(const Customer& customer);

	virtual void say() const override;
};

int Staff::num_of_staff = 0;

Staff::Staff() : Person(), customers(nullptr)
{
	priviliges = Priviliges::Staff;
	num_of_staff++;

	customers = new Customer * [max_number_of_customers];
	for (int i = 0; i < max_number_of_customers; i++)
		customers[i] = nullptr;
}

Staff::Staff(string _name) : Person(_name), customers(nullptr)
{
	priviliges = Priviliges::Staff;
	num_of_staff++;

	customers = new Customer * [max_number_of_customers];
	for (int i = 0; i < max_number_of_customers; i++)
		customers[i] = nullptr;

}

Staff::Staff(const Staff& staff) : Staff(staff.name)
{
	number_of_customers = staff.number_of_customers;

	for (int i = 0; i < number_of_customers; i++)
		customers[i] = staff.customers[i]->clone();
}

Staff::~Staff()
{
	if (customers) {
		for (int i = 0; i < max_number_of_customers; i++)
			delete customers[i];
		delete[] customers;
	}

	name = "NO NAME";
	priviliges = Priviliges::NONE;
	number_of_customers = 0;
	total_money = 0;
	num_of_staff--;
}

Staff* Staff::clone() const
{
	return new Staff(*this);
}

Staff& Staff::operator+= (const Customer& customer)
{
	try {
		if (number_of_customers > max_number_of_customers)
			throw max_number_of_customers;
		else {
			customers[number_of_customers] = customer.clone();
			number_of_customers++;
		}
	}
	catch (int e) {
		cout << "Maximum number of customers [" << e << "] for Staff: " << name << " is reached" << endl;
	}
}

ostream& Staff::info(ostream& out) const
{
	out << name << " " << "Staff" << endl;
	for (int i = 0; i < number_of_customers; i++)
		customers[i]->info(out);
	return out;
}

void Staff::general_info() const
{
	cout << name << endl; 
	cout << "			Customers:" << endl;
	for (int i = 0; i < number_of_customers; i++) {
		cout << "			" << i + 1 << ".";
		customers[i]->general_info();
	}
	cout << endl;
}

void Staff::work(const Customer& customer) 
{
	for (int i = 0; i < number_of_customers; i++)
		if (*customers[i] == customer) {
			cout << "Staff: " << name << " gives 500$ for 50 days to: " << customer << endl;
			customers[i] = customers[i]->clone(500, 50);

			total_money += 500;
			return;
		}
}

void Staff::say() const
{
	cout << "Staff: " << name << endl;
}