#include <stdio.h>
#include <math.h>
#define SIZE 3
#define pow(a) (a * a)

typedef struct _CMPLX
{
double Re, Im;
} CMPLX;

void ReadC ( CMPLX *a )
{
	scanf ( "%lf", &a->Re );
	scanf ( "%lf" ,&a->Im );
}

CMPLX AddC ( CMPLX a, CMPLX b )
{
	a.Re += b.Re; 
	a.Im += b.Im;
	return a;
}

double AbsC ( CMPLX a )
{
	return sqrt ( pow(a.Re) + pow(a.Im) );
}

void AddCA ( CMPLX* a, CMPLX* b, CMPLX* c, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		c[i] = AddC(a[i], b[i]);
		//c[i].Re = a[i].Re + b[i].Re;
		//c[i].Im = a[i].Im + b[i].Im;
	}
}

void main ( void )
{
	CMPLX x,y,z;
	CMPLX tab_x[] = {{3,4},{1,3},{5,-2}};
	CMPLX tab_y[] = {{3,4},{1,3},{5,-2}};
	CMPLX tab_z[SIZE];
	double result;
	int i;

	ReadC ( &x );
	ReadC ( &y );
	z = AddC ( x, y );
	result = AbsC ( z );
	printf( "\nResult=%f\n", result );

	AddCA ( tab_x, tab_y, tab_z, SIZE );
	for (i = 0; i < SIZE; i++)
		printf("%lf %lf \n", tab_z[i].Re, tab_z[i].Im);
}
