#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define epsilon 1e-9 
double f(double x)
{
return x*x*x + 4*x*x  - 10;
}

double df(double x)
{
return 3*x*x + 8*x;
}

int main()
{
	double a=1,c;
	int cnt=0;
	while(1)
	{
		cnt++;
		c = a - (f(a)/df(a));
		
        if( fabs(f(c)) <= epsilon)
            {
                printf("\%d,%.9f",cnt,c);
                break;
            }
        
        else    
        a = c;
	}
	
}
