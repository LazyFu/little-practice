#include<stdio.h>

int survive(int m,int k);

int main()
{
	int m;
	while(scanf("%d",&m)!=EOF)
	{
		if(m==1)
		{
			printf("2\n");
			continue;
		}
		int k=1+m;
		while(!survive(m,k))
		{
			k++;
		}
		printf("%d\n",k+1);
	}
	return 0;
}

int survive(int m,int k)
{
	int start=0;
	for(int i=m*2;i>m;i--)
	{
		start=(start+k)%i;
		if(start<m)
			return 0;
	}
	return 1;
}