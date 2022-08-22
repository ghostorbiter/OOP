#pragma once
#include <string>
#include "basket.h"
using namespace std;

constexpr const int MAX_NUMBER_OF_MAILS = 50;
static string* all_mails;
static int counter = 0;

void add_mail_to_list(const string _mail);
bool check(const string _mail);

class Account
{
	float cash = 0;
	string name;
	string mail;
	int credit_card_number = 0;

	public:
		Cart my_cart;

		Account();
		Account(string _name, string _mail);
		Account(string _name, string _mail, int _credit_card);

		void Add_Cash(float _cash);
		void Add_credit_card(int _credit_card);

		void Change_name(string _new_name);
		void Change_mail(string _new_mail);

		void buy(int index);

		friend ostream& operator<< (ostream& out, const Account acc);
		//friend istream& operator>> (istream& in, Account acc);	
};
