#include<stdio.h>
#include<math.h>
int judge(int x)
{	
	int i,m;
	m=sqrt(1.0*x);
	for(i=2;i<=m;i++)
		if(x%i==0)break;
	if(i>m&&x!=1)
		return 1;
	else
		return 0;
}
int back(int x)
{
	int q=0;
	while(x!=0)
	{
		q=q*10+x%10;
		x/=10;
	}
	return q;
}
int main()
{
	int s, t, x,a[];
	scanf("%d",&t);
	for (s = 0; s < t; s++)
	{
		scanf("%d",&x);
	}
	 a[] = x;
	for (s = 0; s < t; s++)
	{
		if (judge(a[]) == 1 && judge(back(a[])) == 1)
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}