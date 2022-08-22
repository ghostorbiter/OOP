#include <cmath>
#include "Polynomial.h"

//define missing constructor(s)
Polynomial::Polynomial(int _deg, int* _coef) : degree(_deg)
{
	init(_deg + 1, _coef);
}

Polynomial::Polynomial(const Polynomial& p) : degree(p.degree)
{
	init(p.degree + 1, p.tab);
}

Polynomial& Polynomial::operator=(const Polynomial& p)
{
	if (this != &p) {
		degree = p.degree;
		init(p.degree + 1, p.tab);
	}
	return *this;
}

Polynomial::~Polynomial() {}



ostream& operator<<(ostream &out,const Polynomial &w)
{
	//fill missing code
	if (w.degree == 0 && w.tab[0] == 0) out << "Empty Polynomial";

	for (int i = w.degree; i > 0; i--) {
		if (*(w.tab + i) != 0) {
			out << showpos << *(w.tab + i) << "x^";
			out << noshowpos << i;
		}
	}
	if (*(w.tab) != 0)
		out << showpos << *(w.tab);
	return out;
}

Polynomial& Polynomial::operator*=(int n)
{
	for (int i = 0; i < size; i++)
		tab[i] *= n;
	return *this;
}

Polynomial operator+(const Polynomial& arr1, const Polynomial& arr2)
{
	Polynomial pol;
	if (arr1.degree == arr2.degree) {
		pol = arr1;
		for (int i = 0; i < arr2.size; i++)
			pol.tab[i] += arr2.tab[i];
	}
	return pol;
}

Polynomial operator-(const Polynomial& arr1, const Polynomial& arr2)
{
	Polynomial pol;
	if (arr1.degree == arr2.degree) {
		pol = arr1;
		for (int i = 0; i < arr2.size; i++)
			pol.tab[i] -= arr2.tab[i];
	}
	return pol;
}

double Polynomial::operator()(double x) const
{
	//add missing code
	double sum = 0;
	for (int i = degree; i >= 0; i--)
		sum = sum + (*(tab + i) * pow(x, i));
	return sum;
}


Polynomial Polynomial::derivtive() const
{
	//add missing code
	Polynomial pol(degree, tab);
	for (int i = 0; i <= pol.degree; i++)
		*(pol.tab + i) = *(pol.tab + i + 1) * (i + 1);
	*(pol.tab + pol.degree) = 0;
	pol.degree--;
	return pol;
}

double poly_root(const Polynomial &w, double x, int& it)
{
	double eps = 1e-3;    // epsilon value
	int max_it = 100;	  // maximum iteration count
	double new_x = x;
	double prev = x + 2*eps;
	Polynomial pol = w.derivtive();

	for (it = 0; it<max_it; it++)	// actual number of iterations 
	{
		//implement Newton's method
		if (abs(new_x - prev) < eps || abs(pol(new_x)) < eps) {
			return new_x;
		}
		else {
			prev = new_x;
			new_x = (new_x - (w(new_x) / pol(new_x)));
		}
	}
	
	cout << "not convergent" << endl;
	return x;
}
