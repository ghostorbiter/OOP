#pragma once
#include "Person.h"

class Customer : public Person
{
	float balance = 0;
	int days = 0; //days to pay to bank
	static int num_of_customers;
public:
	Customer();
	Customer(string name);
	Customer(const Customer& customer);
	Customer(const Customer& customer, float cash, int day);
	virtual ~Customer();

	Customer* clone() const;
	Customer* clone(float cash, int day) const;
	virtual ostream& info(ostream& out) const override;
	virtual void general_info() const override;
	friend bool operator== (const Customer& customer1, const Customer& customer2);

	virtual void say() const override;
};

int Customer::num_of_customers = 0;

Customer::Customer() : Person()
{
	priviliges = Priviliges::Customer;
	num_of_customers++;
}

Customer::Customer(string _name) : Person(_name)
{
	priviliges = Priviliges::Customer;
	num_of_customers++;
}

Customer::Customer(const Customer& customer) : Customer(customer.name)
{
	balance = customer.balance;
}

Customer::Customer(const Customer& customer, float cash, int day) : Customer(customer)
{
	balance = cash;
	days = day;
}

Customer::~Customer()
{
	balance = 0;
	name = "NO NAME";
	days = 0;
	priviliges = Priviliges::NONE;
	num_of_customers--;
}

Customer* Customer::clone() const
{
	return new Customer(*this);
}

Customer* Customer::clone(float cash, int day) const
{
	return new Customer(*this, cash, day);
}

ostream& Customer::info(ostream& out) const
{
	out << name << " " << "Customer" << endl;
	return out;
}

void Customer::general_info() const
{
	cout << name << endl;
}

bool operator== (const Customer& customer1, const Customer& customer2)
{
	return customer1.name == customer2.name;
}

void Customer::say() const
{
	cout << "Customer: " << name << endl;
}