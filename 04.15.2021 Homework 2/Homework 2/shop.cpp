#include <iostream>
#include "shop.h"
#include "basket.h"
#include <string>
using namespace std;

string all_type[7] = { "everytype", "t_shirt", "dress", "jeans", "shorts", "skirt", "shoes" };
string all_gender[4] = { "everygender", "male", "female", "kids" };

float Shop::get_price()
{
	return price;
}

Gender Shop::get_gender()
{
	return gender;
}

Type Shop::get_type()
{
	return cloth_type;
}

bool Shop::get_availability()
{
	return available;
}

bool operator==(const Shop& shop1, const Shop& shop2)
{
	if (shop1.size == shop2.size && shop1.price == shop2.price && shop1.brand_name == shop2.brand_name && shop1.cloth_type == shop2.cloth_type && shop1.gender == shop2.gender)
		return true;
	return false;
}

Shop::Shop()
{
	price = 0;
	size = 0;
	available = false;
	gender = Gender::everygender;
	cloth_type = Type::everytype;
	brand_name = "default brand";
}

Shop::Shop(int _size, float _price)
{
	size = _size;
	price = _price;
	gender = Gender::everygender;
	cloth_type = Type::everytype;
	brand_name = "default brand";
}

Shop::Shop(int _size, float _price, string _brand_name)
{
	size = _size;
	price = _price;
	gender = Gender::everygender;
	cloth_type = Type::everytype;
	brand_name = _brand_name;
}

Shop::Shop(int _size, float _price, string _brand_name, Gender _gender, Type _type)
{
	size = _size;
	price = _price;
	gender = _gender;
	cloth_type = _type;
	brand_name = _brand_name;
}

void Shop::check_availability()
{
	if (available == true)
		cout << "Cloth is available" << endl;
	else
		cout << "Cloth is currently not available" << endl;
}

bool& Shop::change_availability()
{
	return available;
}

ostream& operator<< (ostream& out, const Shop &cloth)
{
	out << cloth.brand_name << " " << all_gender[(int)cloth.gender] << " " << all_type[(int)cloth.cloth_type] << " " << cloth.size << " " << cloth.price << "$" << endl;
	return out;
}