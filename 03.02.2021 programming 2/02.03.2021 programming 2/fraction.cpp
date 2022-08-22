#include <iostream>
using namespace std;
#include "fraction.h"

void Fraction::write() const {	
	if (nominator == 0) {
		cout << "0" << endl;
	}
	else if (denominator == 1) {
		cout << nominator << endl;
	}
	else {
		cout << nominator << "/" << denominator << endl;
	}
}

void Fraction::read() {
	cout << "Please enter nominator and denominator" << endl;
	cin >> this->nominator >> this->denominator;
	if (denominator == 0) {
		cout << "denominator cannot be equal to 0" << endl;
		nominator = 0;
		denominator = 0;
		return; 
	}
}

int gcd(int a, int b) {
	int r;
	if (b < 0) {
		cout << "Negative denominator b" << endl;
		return 0;
	}
	if (a == b) {
		return a;
	}
	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

void Fraction::shorten() {
	int r = gcd(nominator, denominator);
	if (r == 0) {
		return;
	}
	nominator /= r;
	denominator /= r;
}

Fraction add(Fraction a, Fraction b) {
	Fraction fr;
	int r = gcd(a.denominator, b.denominator);
	int copy = a.denominator;
	copy /= r;
	copy *= b.denominator;
	fr.nominator = a.nominator*(copy/a.denominator) + b.nominator*(copy/b.denominator);
	fr.denominator = copy;
	fr.shorten();
	return fr;
}


//ostream& operator<<(ostream& out, Fraction u);
//istream& operator>>(istream& in, Fraction& u);