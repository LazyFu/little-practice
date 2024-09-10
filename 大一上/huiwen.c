#include<stdio.h>
int main()/*判断一个正整数是否为回文数*/
{
	int n,m,k;
	while(scanf("%d",&n)!=EOF)
	{
	m=0;
	k=n;
	while(k!=0)
	{
		m=m*10+k%10;
		k=k/10;
	}
	if(m==n)
	{
	
		printf("yes\n");}
	else
	{
			printf("no\n");}
	}
	return 0;
}