#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,k;

	while(scanf("%d %d",&n,&k)!=EOF)
	{
		int *a=(int *)malloc(n*sizeof(int));
		for(int p=0;p<n;p++)
		{
			a[p]=-1;//-1为关灯，作为灯的初始状态
		}
		for(int i=1;i<=k;i++)
		{
			for(int j=0;j<n;j++)
			{
				if((j+1)%i==0)
				{
					a[j]=-a[j];
				}
			}
		}
		int first=1;
		for(int q=0;q<n;q++)
		{
			if(a[q]==-1)
			{
				if(!first)
				{
					printf(" ");
				}
				printf("%d",q+1);
				first=0;
			}
		}
		printf("\n");
		free(a);
	}
	return 0;
}