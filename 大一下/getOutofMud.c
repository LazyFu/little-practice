#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,m;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		int i,j;
		int **a=(int **)malloc(n*sizeof(int *));
		for(i=0;i<n;i++)
		{
			a[i]=(int *)malloc(m*sizeof(int));
		}
		
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(a[i][j]==1)
				{
					if(i!=0||j!=0)
					{
						printf(">");
					}
					printf("(%d,%d)",i+1,j+1);
				}
			}
		}
		printf("\n");
		for(i=0;i<n;i++)
		{
			free(a[i]);
		}
		free(a);
	}
	return 0;
}