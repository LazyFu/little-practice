#include<stdio.h>

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
		int times;
		int counta=0,countb=0;
		scanf("%d",&times);
		int a1,a2,b1,b2;
		for(int i=0;i<times;i++)
		{
			scanf("%d %d %d %d",&a1,&a2,&b1,&b2);
			if(a1+b1==a2&&a1+b1!=b2)
			{
				counta++;
			}
			else if(a1+b1==b2&&a1+b1!=a2)
			{
				countb++;
			}
			if(counta>n)
			{
				printf("A\n%d\n",countb);
				break;
			}
			else if(countb>m)
			{
				printf("B\n%d\n",counta);
				break;
			}
		}
	return 0;
}