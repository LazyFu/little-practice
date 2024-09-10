#include<stdio.h>
#include<math.h>
#include<stdbool.h>

bool isPrime(int n) 
{
	if (n <= 1) 
	{
        return false;
    }
    if (n == 2) 
	{
        return true;
    }
    if (n % 2 == 0) 
	{
        return false;
    }
    int sqrt_n=(int)sqrt(n);
    for (int i = 3; i <= sqrt_n; i += 2) 
	{
        if (n % i == 0) 
		{
            return false;
        }
    }
    return true;
}

int main()
{
	int n,count=0;
	scanf("%d",&n);
	for(int i=2;i<n;i++)
	{
		int candidate=(1<<i)-1;
		if(isPrime(candidate))
		{
			printf("%d\n",candidate);
			count++;
		}
	}
	if(count==0)
	{
		printf("None");
	}
	return 0;
}