#include "cmplx.h"
#include <iostream>
#include <algorithm>
using namespace std;

bool myfunction(Cmplx lhs, Cmplx rhs) { return (lhs.abs() < rhs.abs()); }

int main()
{
	Cmplx a(3,4);
	Cmplx b(5,6);
	Cmplx c = a.add(b);
	a.print();
	b.print();
	c.print();
	a.abs();
	std::cout << a.abs()<<" "<<b.abs()<<" "<<c.abs()<<std::endl;
	Cmplx e(0,0);
	e.read();
	e.print();
	
	Cmplx numbers[]{ {6,3}, {3,4}, {5,6} };
	int len = sizeof(numbers) / sizeof(numbers[0]);
	std::sort(numbers, numbers + len, myfunction);
	for (int i = 0; i < len; i++)
	{
		numbers[i].print();
	}
	return 0;
}