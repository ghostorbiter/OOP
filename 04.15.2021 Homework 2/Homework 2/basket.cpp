#include <iostream>
#include "basket.h"
#include "account.h"
#include <string>
using namespace std;

int Cart::get_quantity()
{
	return quantity;
}

float Cart::get_cloth_price(int index)
{
	if (index > quantity - 1)
		return 0;
	return clothes[index].get_price();
}

void Cart::clear()
{
	delete[] clothes;
	clothes = nullptr;
	quantity = overall_price = 0;
}

Cart& Cart::operator+= (Shop& cloth)
{
	if (quantity == 0) {
		clothes = new (nothrow) Shop[1];
		clothes[0] = cloth;
		quantity++;
		overall_price += cloth.get_price();
	}
	else if (quantity == MAX_NUMBER_OF_CLOTHES)
		cout << "Limit of clothes reached" << endl;
	else if (quantity > MAX_NUMBER_OF_CLOTHES) {
		this->clear();
		cout << "Limit of clothes overloaded" << endl;
	}
	else {
		Shop* tmp = new (nothrow) Shop[quantity + 1];
		for (int i = 0; i < quantity; i++)
			tmp[i] = clothes[i];


		delete[] clothes;
		clothes = nullptr;
		quantity++;

		clothes = new (nothrow) Shop[quantity];
		for (int i = 0; i < quantity - 1; i++)
			clothes[i] = tmp[i];
		clothes[quantity - 1] = cloth;
		overall_price += cloth.get_price();
		delete[] tmp;
	}
	return *this;
}

Cart& Cart::operator-= (Shop& cloth)
{
	int check = -1;
	if (quantity == 0)
		cout << "Cart is empty" << endl;
	else if (quantity > MAX_NUMBER_OF_CLOTHES) {
		this->clear();
		cout << "Limit of clothes overloaded" << endl;
	}
	else {
		for (int i = 0; i < quantity; i++) {
			if (clothes[i] == cloth) {
				check = i;
				break;
			}
		}

		if (check == -1) {
			cout << "No matches found" << endl;
		}
		else {
			float _price = cloth.get_price();
			Shop* tmp = new (nothrow) Shop[quantity - 1];
			for (int i = 0; i < check; i++){
				//cout << clothes[i];
				tmp[i] = clothes[i];
			}
			for (int i = check + 1, q = check; i < quantity; i++, q++) {
				//cout << clothes[i];
				tmp[q] = clothes[i];
			}

			delete[] clothes;
			clothes = nullptr;
			quantity--;

			clothes = new (nothrow) Shop[quantity];
			for (int i = 0; i < quantity; i++) {
				//cout << clothes[i];
				clothes[i] = tmp[i];
			}
			delete[] tmp;
			overall_price -= _price;
		}
	}
	return *this;
}

void Cart::filter(float price)
{
	for (int i = 0; i < quantity; i++) {
		if (clothes[i].get_price() > price)
			cout << clothes[i];
	}
}

void Cart::filter(Gender gender)
{
	for (int i = 0; i < quantity; i++) {
		if (clothes[i].get_gender() == gender)
			cout << clothes[i];
	}
}

void Cart::filter(Type type)
{
	for (int i = 0; i < quantity; i++) {
		if (clothes[i].get_type() == type)
			cout << clothes[i];
	}
}

ostream& operator<< (ostream& out, const Cart &basket)
{
	if (basket.clothes == nullptr)
		out << "Cart is empty" << endl;
	for (int i = 0; i < basket.quantity; i++)
		out << basket.clothes[i];
	out << endl << basket.overall_price << endl;
	return out;
}

Cart& Cart::operator= (const Cart& basket)
{
	if (this == &basket)
		return *this;
	delete[] clothes;
	clothes = nullptr;
	quantity = overall_price = 0;
	if (basket.clothes) {
		quantity = basket.quantity;
		overall_price = basket.overall_price;
		clothes = new (nothrow) Shop[quantity];
		for (int i = 0; i < quantity; i++)
			clothes[i] = basket.clothes[i];
	}
	return *this;
}

void Cart::buy(int index)
{
	if (clothes == nullptr)
		return;
	if (index > quantity - 1)
		return;
	if (!clothes[index].get_availability()) {
		cout << "Currently not available" << endl;
		return;
	}
	*this -= clothes[index];
}

Cart::~Cart()
{
	delete[] clothes;
	quantity = overall_price = 0;
}