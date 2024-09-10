#include<stdio.h>
int main()
{
	int t,a,b,c;
	scanf("%d",&t);
	for(;t>0;t--)
	{
		scanf("%d %d %d",&a,&b,&c);
		if(a+b<=c||a+c<=b||b+c<=a)
			printf("Not Triangle\n");
		else if(a==b&&b==c)
			printf("Regular Triangle\n");
		else if(a==b&&b!=c||b==c&&c!=a||a==c&&c!=b)
			printf("Isosceles Triangle\n");
		else
			printf("Triangle\n");
	}
	return 0;
}