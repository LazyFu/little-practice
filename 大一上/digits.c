#include <stdio.h>
#include <math.h>
int digits(int n) 
{
    if (n <= 1) 
	{
        return 1;
    }
    double digits = 0.0;
    for(int i = 2; i <= n; i++) 
	{
        digits += log10(i);
    }
    return (int)(floor(digits) + 1);
}

int main() 
{
    int n,T;
    scanf("%d",&T);
    for(;T>0;T--)
    {
    scanf("%d",&n);
    int s = digits(n);
    printf("%d\n",s);
	}
    return 0;
}