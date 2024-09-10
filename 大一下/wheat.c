#include<stdio.h>
#include<string.h>

void plus(int *temp,int *result)
{
	for(int i=500-1;i>=0;i--)
	{
		result[i]+=temp[i];
		if(result[i]>=10)
		{
			int carry=result[i]/10;
			result[i]%=10;
			if(i)
			{
				result[i-1]+=carry;
			}
		}
	}
}

void multiply(int *temp,int next)
{
	int nextt[500]={0};
	for(int i=500-1;i>=0;i--)
	{
		nextt[i]+=temp[i]*2;
		if(nextt[i]>=10)
		{
			int carry=nextt[i]/10;
			nextt[i]%=10;
			if(i)
			{
				nextt[i-1]+=carry;
			}
		}
	}
	memcpy(temp,nextt,500*sizeof(int));
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int temp[500]={0},result[500]={0};
		temp[500-1]=1;
		int next=2;
		for(int i=0;i<n;i++)
		{
			plus(temp,result);
			multiply(temp,next);
		}
		for(int k=0;k<500;k++)
		{
			printf("%d",result[k]);
		}
		printf("\n");
	}
	return 0;
}