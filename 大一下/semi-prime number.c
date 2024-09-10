#include<stdio.h>
#include<stdbool.h>
#include<math.h>

bool judge_prime_number(int s)
{
	if(s<=1)
	{
		return false;
	}
	for(int i=2;i<=sqrt(s);i++)
	{
		if(s%i==0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		bool found=false;
		for(int i=2;i<=n/2;i++)
		{
			int a=i;
			int b=n/a;
			if(n%a==0&&judge_prime_number(a)&&judge_prime_number(b))
			{
				found=true;
				printf("Yes\n");
				break;
			}
		}
		if(!found)
		{
			printf("No\n");
		}
	}
	return 0;
}