#include<stdio.h>
int main()
{
	int count,n;
	while(scanf("%d",&n)!=EOF)
	{
		count=0;
		do
		{
			if(n%2==0)
			{
			n=n/2;
			}
			else
			{
			n=(n*3+1)/2;
			}
			count++;
		}while(n!=1);
		printf("%d\n",count);
	}
	return 0;
}