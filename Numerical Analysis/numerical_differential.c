#include <stdio.h>
#include<math.h>
#define N 200
#define f(x) (((x)*(x)*(x))+(4*(x)*(x))-10)
#define df(x) ((3*(x)*(x))+(8*(x)))

const double b = 10, a =0;
double x[N+1];
double f[N+1];
double df[N+1];
double h = (b-a)/N;

double max()
{
double largest = -1;	
	for(int i = 0;i<=N;i++)
	if(fabs(x[i]-f[N-1]) > largest)
		largest = x[i]-f[N-1];
	return fabs(largest);
}

void xValue()
{
	for(int i=1;i<N;i++)
	x[i] = x[i-1] + h;
	
}


void fxValue()
{
	for(int i=1;i<N;i++)
	f[i] = f((x[i]));		
}

void dfxValue()
{
	for(int i=1;i<N;i++)
	df[i] = df((x[i]));		
}

double forward(int x2, int x1)
{
    return ((f[x2] - f[x1]) / (x[x2] - x[x1]));
}

double center(int x2, int x0)
{
    return ((f[x2] - f[x0]) / (x[x2] - x[x0]));
}

double backward(int x1, int x0)
{
    return ((f[x1] - f[x0]) / (x[x1] - x[x0]));
}

int main()
{
	//printf("h value : %lf",h);
	
	x[N] = 10;

	f[0] = f(x[0]);
	f[N] = f(x[N]);

	df[0] = df(x[0]);
	df[N] = df(x[N]);
	
	x[0] = 0;

	
	xValue();
	fxValue();
	dfxValue();
	
	
	
	
	
	printf("\n--------NUMERICAL METHOD-------\n\n");
    	printf("value of x: %lf value of f: %lf value of df: %lf\n", x[0], f[0], forward(1, 0));
    	for (int i=1; i<N; i++)
    	{
        printf("value of x: %lf value of f: %lf value of df: %lf\n", x[i], f[i], center(i-1,i+1));
    	}
    	printf("value of x: %lf value of f: %lf value of df: %lf\n", x[N], f[N], backward(N, N-1));
    	
    	
    	printf("\n--------THEORETICAL METHOD-------\n");
    	for (int i=1; i<N; i++)
    	{
        printf("value of x: %lf value of f: %lf value of df: %lf\n", x[i], f[i], df[i]);
    	}  
    	printf("value of x: %lf value of f: %lf value of df: %lf\n", x[N], f[N], df[N]);
    	
    	printf("%lf",max());
    	  	
}
