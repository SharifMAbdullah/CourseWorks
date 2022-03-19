#include<stdio.h>
#include<math.h>
#define epsilon 1e-9
double f(double x)
{
    return pow(x,3)+4*pow(x,2)-10;
}

int main()
{
    double a=1,b=2;
    int cnt = 0;

    if( f(a)*f(b) >= 0)
            {
            printf("solution doesn't exist");
            return 0;
            }

    double c;
    while(1)
    {

        c = (a *f(b) - b*f(a)) / (f(b)-f(a));
           cnt++;
        if( fabs(f(c)) <= epsilon)
            {
                printf("root = %.9f and iterations = %d",c,cnt);
                break;
            }

        if( f(a)*f(c) < 0)
                b = c;
        else
            a = c;
    }

}