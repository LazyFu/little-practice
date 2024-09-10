#include<stdio.h>
int main()
{
	int a[10000]={0},i,j,s,n;
	while(scanf("%d",&n)!=EOF)
	{
	int l=0;
	a[0]=1;
	for(i=1;i<=n;i++)
	{
		s=0;
		for(j=0;j<=l;j++)
		{
			s+=a[j]*i;
			a[j]=s%10;
			s=s/10;
		}
		while(s)
		{
			l++;
			a[l]=s%10;
			s=s/10;
		}
	}
	for(i=l;i>=0;i--)
	{
		printf("%d",a[i]);
	}
	printf("\n");
}
	return 0;
}