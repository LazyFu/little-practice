#include<stdio.h>
int main()
{
	int hats[101]={0};
	
	int n,k;
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&hats[i]);
	}
	
	scanf("%d",&k);
	for(int i=0;i<k;i++)
	{
		int kids[101]={0};
		int award=1,quit=0;
		for(int j=0;j<n;j++)
		{
			scanf("%d",&kids[j]);
			if(kids[j]!=0)
			{
				if(kids[j]!=hats[j])
				{
					award=0;
				}
			}
			else
			{
				quit++;
			}
		}
		if(quit==n||award==0)
		{
			printf("Ai Ya\n");
		}
		else if(quit!=n)
		{
			printf("Da Jiang!!!\n");
		}
	}
	return 0;
}