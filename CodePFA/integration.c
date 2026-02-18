



#define INTEGRATION_C

#include "integration.h"

bool setQuadFormula(QuadFormula* qf, char* name)
{
	if(strcmp(name , "left")==0)
	{
		strcpy(qf-> name,"left");
		qf-> n=0;
		qf-> wk[0]=1.0;
		qf-> xk[0]=0.0;
		return true;
	}
	else if(strcmp(name, "right")==0)
	{
		strcpy(qf-> name,"right");
		qf-> n=0;
		qf-> wk[0]=1.0;
		qf-> xk[0]=1.0;
		return true;
	}
	else if(strcmp(name, "middle")==0)
	{
		strcpy(qf-> name,"middle");
		qf-> n=0;
		qf-> wk[0]=1.0;
		qf-> xk[0]=0.5;
		return true;
	}
	else if(strcmp(name, "trapezes")==0)
	{
		strcpy(name,"trapezes");
		qf-> n=1;
		qf-> wk[0]=1.0/2.0;
		qf->wk[1]=1.0/2.0;
		qf-> xk[0]=0.0;
		qf-> xk[1] = 1.0;
		return true;
	}
	else if(strcmp(name, "simpson")==0)
	{
		strcpy(qf-> name,"simpson");
		return true;
	}
	else if(strcmp(name, "gauss2")==0)
	{
		strcpy(qf-> name,"gauss2");
		return true;
	}
	else if(strcmp(name, "gauss3")==0)
	{
		strcpy(qf-> name,"gauss3");
		return true;
	}
	else
		return false;
}

/* This function is not required ,but it may useful to debug */
void printQuadFormula(QuadFormula* qf)
{
  printf("Quadratic formula: %s\n", qf->name);
  /* Print everything else that may be useful */
}


/* Approximate the integral of function f from a to b.
   - f is a pointer to a function pointer
   - a and b are the integration bounds
   - Interval [a,b] is split in N subdivisions [ai,bi]
   - Integral of f on each subdivision [ai,bi] is approximated by the quadrature formula qf.
*/
double integrate(double (*f)(double), double a, double b, int N, QuadFormula* qf)
{
	double sum = 0.0;
	double ai = 0.0;
	double bi = 0.0;
	for(int i =0; i<N; i++)
	{
		ai = a + (i*((b-a)/N));
		bi = a + ((i+1)*((b-a)/N));
		printf("test premiere boucle\n");
		for(int j = 0; j<=(qf->n); j++)
		{
			sum += (bi-ai) * (qf->wk[j]) * f(ai + ((qf->xk[j]) * (bi-ai)));
			printf("%lf | %i\n", sum, j);
			printf("test deuxieme boucle\n");
		}
		printf("test fin de boucle\n");
	}
	printf("test fin\n");
	return sum;

}

double integrate_dx(double (*f)(double), double a, double b, double dx, QuadFormula* qf)
{
  return 0.0;
}


