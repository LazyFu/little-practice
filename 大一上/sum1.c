#include<stdio.h>
float sum(int n)
{
	int i,sign=1,a=1,b=2;
	float s=0.0;
	for(i=0;i<n;i++)
{
	s+=(float)sign*b/a;
	b=a+b;
	a=b-a;
	sign=-sign;
}
	return s;
}
int main()
{
	int n;
	float s;
	while(scanf("%d",&n)!=EOF)
	{
	s=sum(n);
	printf("%.4f\n",s);
	}
	return 0;
}