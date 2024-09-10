#include<stdio.h>
void fun(int n)
{
	int i;
	unsigned int s=0.0,a=1.0,b=2.0,sign=1;
		for(i=0;i<n;i++)
	{
		s=(unsigned int)b/a;
		b=a+b;
		a=b-a;
	}
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		unsigned int s=0.0,a=1.0,b=2.0,sign=1.0;
	fun(n-1);
	if(n%2==0)
		sign=-sign;
	printf("%u/%u\n",sign*b,a);
	}
	return 0;
}