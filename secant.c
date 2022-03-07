#include<stdio.h>
#include<math.h>
#define f(x) ( (x) * (x) *(x) + (4*(x)*(x)) - 10)
#define epsilon 1e-9

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

        c = (f(b) *a - f(a)*b) / (f(b)-f(a));
           cnt++;
        if( fabs(f(c)) <= epsilon)
            {
                printf("root = %.9f and iterations = %d\n",c,cnt);
                break;
            }

	a = b;
        b = c;
    }

}
