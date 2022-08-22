#pragma once
#include <string>
using namespace std;

enum class Gender {
	everygender,
	male,
	female,
	kids
};

enum class Type {
	everytype,
	t_shirt,
	dress,
	jeans,
	shorts,
	skirt,
	shoes
};

class Shop
{
	Gender gender;
	Type cloth_type;
	float price;
	int size;
	string brand_name;
	bool available = true;
public:
	float get_price();
	Gender get_gender();
	Type get_type();
	bool get_availability();

	friend bool operator== (const Shop& shop1, const Shop& shop2);

	Shop();
	Shop(int _size, float _price);
	Shop(int _size, float _price, string _brand_name);
	Shop(int _size, float _price, string _brand_name, Gender _gender, Type _type);

	void check_availability();
	bool& change_availability();

	friend ostream& operator<< (ostream& out, const Shop &cloth);
};