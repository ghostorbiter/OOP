#include <iostream>
using namespace std;
#include "card.h"
#include "pattern.h"

void card::init(int _m, element el, element* tab) {
	if (_m <=0) {
		m = 0;
		return;
	}

	m = _m;
	int size = m * m;

	t = new (nothrow) element[size];
	if (!t) {
		m = 0;
		return;
	}
	if (tab) {
		for (int i = 0; i < size; i++)
			t[i] = tab[i];
	}
	else {
		for (int i = 0; i < size; i++)
			t[i] = el;
	}
}

card::card(int m, element el) {	// dark green
	init(m, el);
}

card::card(const card& k) {
	init(k.m, element(0), k.t);
}

card& card::operator=(const card& c) {
	if (&(*this) != &c) {
		delete[] t;
		this->init(c.m, c.t[0], c.t);
	}
	return *this;
}

int card::size() const {
	return m;
}

element card:: operator()(int i, int j) const {	// provides an array element with localization (i, j)
	return t[i * m + j];
}

element& card:: operator()(int i, int j) {
	return t[i * m + j];
}

card& card:: operator+=(const pattern& g) {
	g.paint(*this);
	return *this;
}

void card::egg(element el) { //everything except the egg is painted over with the background color (black by default)
	int sx, sy, r;
	sx = sy = m / 2;
	r = min(sx, sy) - 1;
	
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			if ((i - sx) * (i - sx) + (j - sy) * (j - sy) > r * r) {
				t[i*m+j] = el;
			}
}

ostream& operator<<(ostream& out, const card& k) {
	for (int i = 0; i < k.m; i++) {
		for (int j = 0; j < k.m; j++)
			out << k(i, j);
		out << endl;
	}
	return out;
}