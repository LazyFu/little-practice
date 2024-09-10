#include<stdio.h>

/*int numToStr(int sum,int *s);
{
	for(int i=0;;i++)
	{
		s[i]=sum%10;
		sum/=10;
		if(sum==0)
		{
			break;
		}
	}
	return s;
}*/

int continuity(int n)
{
	if(n/10==0)
	{
		return 0;
	}
	int result=1;
	while(n>0)
	{
		result*=n%10;
		n/=10;
	}
	return continuity(result)+1;
}

int main()
{
	int a,b;
	int max=0;
	while(scanf("%d %d",&a,&b)!=EOF)
	{
		for(int i=a;i<=b;i++)
		{
			if(continuity(i)>max)
			{
				max=continuity(i);
			}
		}
		printf("%d\n",max);
		for(int i=a;i<=b;i++)
		{
			if(continuity(i)==max)
			{
				printf("%d ",i);
			}
		}
		printf("\n");
	}
	return 0;
}