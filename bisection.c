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
    printf("Itr,Root\n");
    while(1)
    {
        cnt++;
        c= (a+b)/2;
        printf("%d,%.9f\n",cnt,c);
        if( fabs(f(c)) <= epsilon)
            {
                printf("\%d,%.9f",cnt,c);
                break;
            }
            
        if( f(a)*f(c) < 0)
                b = c;
        else   
            a = c;            
    }

}

