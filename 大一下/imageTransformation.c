#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int n,m;
	int num=0;
	while(scanf("%d %d",&n,&m)&&n!=0&&m!=0)
	{
		//�����ά����a,n��m�С�
		int **a=(int **)malloc(n*sizeof(int *));
		for(int i=0;i<n;i++)
		{
			a[i]=(int *)malloc(m*sizeof(int));
		}
		int **b=(int **)malloc(n*sizeof(int *));
		for(int i=0;i<n;i++)
		{
			b[i]=(int *)malloc(m*sizeof(int));
		}
		int **c=(int **)malloc(n*sizeof(int *));
		for(int i=0;i<n;i++)
		{
			c[i]=(int *)malloc(m*sizeof(int));
		}
		int **grey=(int **)malloc(n*sizeof(int *));
		for(int i=0;i<n;i++)
		{
			grey[i]=(int *)malloc(m*sizeof(int));
		}
		//��������N*M����
			for(int p=0;p<n;p++)
			{
				for(int q=0;q<m;q++)
				{
					scanf("%d",&a[p][q]);
				}
			}
			for(int p=0;p<n;p++)
			{
				for(int q=0;q<m;q++)
				{
					scanf("%d",&b[p][q]);
				}
			}
			for(int p=0;p<n;p++)
			{
				for(int q=0;q<m;q++)
				{
					scanf("%d",&c[p][q]);
				}
			}
		//���Ҷ�ֵ��
		int result=0;
		for(int p=0;p<n;p++)
			{
				for(int q=0;q<m;q++)
				{
					grey[p][q]=(a[p][q]+b[p][q]+c[p][q])/3;
				}
			}
		//���
		num++;
		printf("Case %d:\n",num);
			for(int p=0;p<n;p++)
			{
				for(int q=0;q<m;q++)
				{
					printf("%d",grey[p][q]);
					if(q!=m-1)
					{
						printf(",");
					}
				}
				printf("\n");
			}
		for(int j=0;j<n;j++)
		{
			free(a[j]);
		}
		free(a);
		for(int j=0;j<n;j++)
		{
			free(b[j]);
		}
		free(b);
		for(int j=0;j<n;j++)
		{
			free(c[j]);
		}
		free(c);
	}
	return 0;
}