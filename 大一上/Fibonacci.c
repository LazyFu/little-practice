#include<stdio.h>
int Fibonacci(int n)
{
	int a=0,b=1,temp;
	if(n==1||n==2)
		return 1;
	for(int i=2;i<=n;i++)
	{
		temp=a+b;
		a=b;
		b=temp;
	}
	return b;
}

int main()/*输出Fibonacci数列的第n项*/
{
	int n;
	scanf("%d",&n);
	int result=Fibonacci(n);
	printf("%d",result)	;
	return 0;
}