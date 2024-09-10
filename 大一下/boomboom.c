#include<stdio.h>
#include<stdlib.h>

int boom1(int field[50][50],int i,int j,int n,int m)//Ê®×Ö¼Ü
{
	int kill=0;
	for(int p=i-m;p<=i+m;p++)
	{
		if(p>=0&&p<n)
		{
			kill+=field[p][j];
		}
	}
	for(int q=j-m;q<=j+m;q++)
	{
		if(q>=0&&q<n)
		{
			kill+=field[i][q];
		}
	}
	kill-=field[i][j];
	return kill;
}

int boom2(int field[50][50],int i,int j,int n,int m)//¶Ô½ÇÏß
{
	int kill=0;
	for(int p=i-m,q=j-m;p<=i+m,q<=j+m;p++,q++)
	{
		if(p>=0&&p<n&&q>=0&&q<n)
		{
			kill+=field[p][q];
		}
	}
	for(int p=i-m,q=j+m;p<=i+m,q>=j-m;p++,q--)
	{
		if(p>=0&&p<n&&q>=0&&q<n)
		{
			kill+=field[p][q];
		}
	}
	kill-=field[i][j];
	return kill;
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int field[50][50]={0};
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&field[i][j]);
		}
	}
	int max=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(boom1(field,i,j,n,m)>max)
			{
				max=boom1(field,i,j,n,m);
				if(boom2(field,i,j,n,m)>max)
				{
					max=boom2(field,i,j,n,m);
				}
			}
		}
	}
	printf("%d\n",max);
	return 0;
}