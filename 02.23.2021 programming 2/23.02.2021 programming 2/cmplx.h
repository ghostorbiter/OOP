#ifndef __CMPLX_H__
#define __CMPLX_H__

struct Cmplx {
	double Re, Im;
	void print();
	Cmplx(double Rev, double Imv);
	Cmplx add(Cmplx& other);
	double abs();
	void read();
};

#endif
