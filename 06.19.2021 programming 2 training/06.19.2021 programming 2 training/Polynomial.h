#pragma once
#include <iostream>
#include "Array.h"
using namespace std;

class Polynomial : private Array //add private inheritance
{
protected:

	int degree;

public:

	Polynomial(int _deg=0, int *_coef=nullptr);
	Polynomial(const Polynomial& p);
	Polynomial& operator=(const Polynomial &p);
	~Polynomial();

	friend ostream& operator<<(ostream& out, const Polynomial& w);

	//declare and define in Polynomial.cpp
	Polynomial& operator*=(int n);
	friend Polynomial operator+(const Polynomial& arr1, const Polynomial& arr2);
	friend Polynomial operator-(const Polynomial& arr1, const Polynomial& arr2);

	Polynomial derivtive() const;
	double operator()(double x) const;
};

double poly_root(const Polynomial& w, double x, int& it);
//{
//	double new_x = x;
//	Polynomial pol = w.derivtive();
//	for (int i = 0; i < it; i++) {
//		if (abs(w.derivtive()(new_x)) < 0.0001)
//			return new_x;
//		else {
//			new_x = new_x - (w(new_x) / pol(new_x));
//		}
//	}
//	return x;
//}
