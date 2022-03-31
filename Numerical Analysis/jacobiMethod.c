#include <stdio.h>
#include<math.h>
#define epsilon 1.0e-9
#define N 100

#define f1(x,y,z) ((85-3*(y)+2*(z))/15)
#define f2(x,y,z) ((51-2*(x)-z)/10)
#define f3(x,y,z) ((5-(x)+2*(y))/8)

double max(double a,double b)
{
    if(a>b) return a;
    else return b;
}

int main()
{
    double xo1=0,xo2=0,xo3=0;
    double x_error,y_error,z_error;
    double xn1,xn2,xn3;
    int cnt = 0;
    
    while(1)
    {
       
        
        xn1 = f1(xo1,xo2,xo3);
        xn2 = f2(xo1,xo2,xo3);
        xn3 = f3(xo1,xo2,xo3);
        
        x_error = fabs(xo1-xn1);
        y_error = fabs(xo2-xn2);
        z_error = fabs(xo3-xn3);
        
        if(x_error<epsilon && y_error<epsilon && z_error<epsilon)        {
            printf("%d iterations, x, y ,z = %lf, %lf, %lf",cnt,xn1,xn2,xn3);
            return 0;
        }
        
        else
        {
        xo1  = xn1;
        xo2  = xn2;
        xo3  = xn3;
        }
     cnt++;
    }
    return 0;
}

