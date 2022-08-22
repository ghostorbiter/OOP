#include "Array.h"

void Array::init(int _size, int* _coef) {
	//fill missing code
	size = _size;
	tab = new int[size];

	if (_coef) {
		for (int i = 0; i < _size; i++)
			tab[i] = _coef[i];
	}
	else {
		for (int i = 0; i < _size; i++)
			tab[i] = 0;
	}
}


//fill missing constructors, destructor, operator= (if needed)
Array::Array(int _size, int* _coef)
{
	init(_size, _coef);
}

Array::Array(const Array& a)
{
	init(a.size, a.tab);
}

Array::~Array()
{
	delete[] tab;
}

Array& Array::operator=(const Array& a)
{
	if (this != &a) {
		init(a.size, a.tab);
	}
	return *this;
}

//fill missing operator+ operator- operator*
Array& Array::operator*=(int n)
{
	for (int i = 0; i < size; i++)
		tab[i] *= n;
	return *this;
}

Array operator+(const Array& arr1, const Array& arr2)
{
	Array arr;
	if (arr1.size == arr2.size) {
		arr = arr1;
		for (int i = 0; i < arr.size; i++)
			arr.tab[i] += arr2.tab[i];
	}
	return arr;
}

Array operator-(const Array& arr1, const Array& arr2)
{
	Array arr;
	if (arr1.size == arr2.size) {
		arr = arr1;
		for (int i = 0; i < arr.size; i++)
			arr.tab[i] -= arr2.tab[i];
	}
	return arr;
}

ostream& operator<<(ostream& out, Array& a)
{
	if (a.size < 1) out << "Empty Array";

	for (int i = 0; i < a.size; i++)
		out << showpos << *(a.tab + i) << "  ";
	return out;
}
