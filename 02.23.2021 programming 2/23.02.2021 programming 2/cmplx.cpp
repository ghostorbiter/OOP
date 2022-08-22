#include "cmplx.h"
#include <iostream>
#include <math.h>

void Cmplx::print()
{
	std::cout << Re << " + " << Im << "i" << std::endl;
}

Cmplx::Cmplx(double Rev, double Imv) : Re(Rev), Im(Imv) {}

Cmplx Cmplx::add(Cmplx &other)
{
	Cmplx result(this->Re + other.Re, this->Im + other.Im);
	return result;
}

double Cmplx::abs()
{
	return sqrt(pow(this->Re, 2) + pow(this->Im, 2));
}

void Cmplx::read()
{
	std::cout << std::endl << "Please enter Real and Imaginary part of Complex number: " << std::endl;
	std::cin >> Re >> Im;
}