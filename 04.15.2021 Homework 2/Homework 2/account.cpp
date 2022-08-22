#include <iostream>
#include "account.h"
#include "basket.h"
#include <string>
using namespace std;

void add_mail_to_list(const string _mail)
{
	if (counter == MAX_NUMBER_OF_MAILS) {
		cout << "Max number of mails is reached" << endl;
		return;
	}

	if (_mail == "")
		return;

	if (check(_mail)) {
		cout << _mail << " is already registered" << endl;
		return;
	}

	string* tmp = new (nothrow) string[counter + 1];
	for (int i = 0; i < counter; i++) {
		tmp[i] = all_mails[i];
	}

	delete[] all_mails;
	all_mails = nullptr;
	counter++;
	all_mails = new (nothrow) string[counter];

	for (int i = 0; i < counter-1; i++) {
		all_mails[i] = tmp[i];
	}
	all_mails[counter - 1] = _mail;
	delete[] tmp;
}

bool check(const string _mail)
{
	for (int i = 0; i < counter; i++) {
		if (all_mails[i] == _mail)
			return true;
	}
	return false;
}

Account::Account() : name(""), mail("") {}
Account::Account(string _name, string _mail)
{
	if (check(_mail)) {
		cout << _mail << " is already registered" << endl;
	}
	else {
		name = _name;
		mail = _mail;
		add_mail_to_list(_mail);
	}
}

Account::Account(string _name, string _mail, int _credit_card)
{
	if (check(_mail)) {
		cout << _mail << " is already registered" << endl;
	}
	else {
		name = _name;
		mail = _mail;
		credit_card_number = _credit_card;
		add_mail_to_list(_mail);
	}
}

void Account::Add_Cash(float _cash)
{
	if (credit_card_number == 0) {
		cout << "There is no credit card" << endl;
		return;
	}
	cout << "Successful transaction" << endl;
	cash += _cash;
}

void Account::Add_credit_card(int _credit_card)
{
	if (mail == "") {
		cout << "You are not registered" << endl;
		return;
	}
	credit_card_number = _credit_card;
}

void Account::Change_name(string _new_name)
{
	if (mail == "")
		return;
	name = _new_name;
}

void Account::Change_mail(string _new_mail)
{
	if (check(_new_mail)) {
		cout << _new_mail << " is already registered" << endl;
	}
	if (mail == "") {
		mail = _new_mail;
		add_mail_to_list(_new_mail);
	}
	else {
		for (int i = 0; i < counter; i++) {
			if (all_mails[i] == mail) {
				all_mails[i] = _new_mail;
				break;
			}
		}
		mail = _new_mail;
	}
}

void Account::buy(int index)
{
	if (mail == "") {
		cout << "Please register first" << endl;
		return;
	}

	if (my_cart.get_quantity() == 0) {
		cout << "Cart is empty" << endl;
		return;
	}

	if (index > my_cart.get_quantity() - 1) {
		cout << "Index cannot be greater than the amount of clothes in cart" << endl;
		return;
	}

	if (cash < my_cart.get_cloth_price(index)) {
		cout << "You do not have enough money" << endl;
		return;
	}

	cout << "Successful purchase. Thank you!" << endl;
	my_cart.buy(index);
}

ostream& operator<< (ostream& out, const Account acc)
{
	if (acc.mail == "")
		out << "Standart user" << endl;
	else
		out << acc.name << " " << acc.mail << endl;
	return out;
}

//istream& operator>> (istream& in, Account acc);