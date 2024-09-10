#include<stdio.h>

void rotate(long long int matrix[][10],int n,long long int k,long long int r[][10]);

int main()/*long long int型输出，输入也要是long long int*/
{
	long long int matrix[10][10],k;
	long long int r[10][10]={0};
	int i,j,n;
	while(scanf("%d\n",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%lld ",&matrix[i][j]);
			}
			scanf("\n");
		
		}
		scanf("%lld",&k);
		rotate(matrix,n,k,r);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(j!=0)
				{
					printf(" ");
				}
					printf("%lld",r[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}

void rotate(long long int matrix[][10],int n,long long int k,long long int r[][10])
{
	int p,q,i,j;
	for(i=0,p=0;i<n,p<n;p++,i++)
	{
		for(j=0,q=0;q<n,j<n;q++,j++)
		{
			switch(k%4)
			{
				case 0:
					r[i][j]=(matrix[p][q]+matrix[n-q-1][p]+matrix[n-p-1][n-q-1]+matrix[q][n-p-1])*(k/4)+matrix[p][q];
					break;
				case 1:
					r[i][j]=(matrix[p][q]+matrix[n-q-1][p]+matrix[n-p-1][n-q-1]+matrix[q][n-p-1])*(k/4)+matrix[n-q-1][p]+matrix[p][q];
					break;
				case 2:
					r[i][j]=(matrix[p][q]+matrix[n-q-1][p]+matrix[n-p-1][n-q-1]+matrix[q][n-p-1])*(k/4)+matrix[p][q]+matrix[n-q-1][p]+matrix[n-p-1][n-q-1];
					break;
				case 3:
					r[i][j]=(matrix[p][q]+matrix[n-q-1][p]+matrix[n-p-1][n-q-1]+matrix[q][n-p-1])*(k/4)+matrix[p][q]+matrix[n-q-1][p]+matrix[n-p-1][n-q-1]+matrix[q][n-p-1];
					break;
			}
		}
	}
}