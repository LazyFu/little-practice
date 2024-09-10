#include<stdio.h>
unsigned int getfactorial(int n)
{
	unsigned int result;
	if(n==0)
		result=1;
	else
		result=n*getfactorial(n-1);
	return result;
}
int main()
{
	int n,i;
	while(scanf("%d",&n)!=EOF)
	{
	unsigned int sum=0;
	for(i=n;i>=0;i--)
	{
		sum+=getfactorial(i);
	}
	printf("%u\n",sum);
	}
	return 0;
}