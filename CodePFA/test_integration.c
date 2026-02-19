/******************************************************/
/* Program to run and test the integration functions. */
/* Creation date: 31 July, 2025                       */
/******************************************************/

#include <math.h>
#include "integration.h"
#include <stdio.h>

/* Code here everything you need to test the integration methods and show your numericzal results */

double f(double t)
{
	return t;
}

int main()
{

	QuadFormula qf;
	double I1, I2, I3, I4;
	setQuadFormula(&qf, "left");
	printQuadFormula(&qf);
	printf("n: %i  wk: %lf  xk: %lf\n", qf.n, qf.wk[0], qf.xk[0]);
	I1 = integrate(f, 0, 1, 10, &qf);
	printf("I1 = %lf\n", I1);
	setQuadFormula(&qf, "right");
	printQuadFormula(&qf);
	printf("n: %i  wk: %lf  xk: %lf\n", qf.n, qf.wk[0], qf.xk[0]);
	I2 = integrate(f, 0, 1, 10, &qf);
	printf("I2 = %lf\n", I2);
	setQuadFormula(&qf, "middle");
	printQuadFormula(&qf);
	printf("n: %i  wk: %lf  xk: %lf\n", qf.n, qf.wk[0], qf.xk[0]);
	I3 = integrate(f, 0, 1, 10, &qf);
	printf("I3 = %lf\n", I3);
	setQuadFormula(&qf, "trapezes");
	printQuadFormula(&qf);
	printf("n: %i  w0: %lf  x0: %lf  w1: %lf  x1: %lf\n", qf.n, qf.wk[0], qf.xk[0], qf.wk[1], qf.xk[1]);
	I4 = integrate(f, 0, 1, 10, &qf);
	printf("I4 = %lf\n", I4);
}
