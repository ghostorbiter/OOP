#pragma once
#include<iostream>
#include<vector>
using namespace std;

class Array
{
protected:

	int size;
	int* tab;
	void init(int _size, int* _coef);

public:

	Array(int _size = 0, int* _coef = nullptr);
	Array(const Array& a);
	~Array();
	Array& operator=(const Array& a);

	//declare and define in Array.cpp
	Array& operator*=(int n);
	friend Array operator+(const Array& arr1, const Array& arr2);
	friend Array operator-(const Array& arr1, const Array& arr2);

	friend ostream& operator<<(ostream& out, Array& a);
};
