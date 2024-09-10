#include<stdio.h>

/*int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int a=7,b=11,c;
		int result=0;
		if(n==0)
		{
			result=a;
		}
		for(int i=2;i<=n;i++)
		{
			c=a+b;
			a=b;
			b=c;
		}
		result=b;
		if(result%3==0)
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
	}
	return 0;
}*/
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if((n+2)%4==0)
		{
			printf("yes\n");
			
		}
		else
		{
			printf("no\n");
		}
	}
	return 0;
}