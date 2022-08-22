#pragma once
#include "shop.h"

constexpr const int MAX_NUMBER_OF_CLOTHES = 50;

class Cart
{
	Shop* clothes = nullptr;
	int quantity = 0;
	float overall_price = 0;
public:	
	int get_quantity();
	float get_cloth_price(int index);

	~Cart();
	Cart() {}
	Cart& operator+= (Shop& cloth);
	Cart& operator-= (Shop& cloth);

	void filter(float price);
	void filter(Gender gender);
	void filter(Type type);
	void clear();

	void buy(int index);

	friend ostream& operator<< (ostream& out, const Cart &basket);
	Cart& operator= (const Cart& basket);
};
