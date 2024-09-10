#include<stdio.h>

int main()
{
	int k;
	unsigned long long int n;
	scanf("%d",&k);
	for(int i=0;i<k;i++)
	{
		scanf("%lld",&n);
		for(unsigned long long int j=1;;j++)
		{
			if(n>j)
			{
				n-=j;
			}
			else
			{
				if(n>9)
				{
					n-=9;
				}
				else
				{
					printf("%d\n",n);
					break;
				}
			}
		}
	}
	return 0;
}