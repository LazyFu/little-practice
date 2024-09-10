#include<stdio.h>
void fun(int a[100],int b[100],int m,int n)
{
	int c[200];
	int i=0,j=0,k=0;
	while(i<m&&j<n)
	{
		if(a[i]<b[j])
		{
			c[k]=a[i];
			i++;
		}
		else
		{
			c[k]=b[j];
			j++;
		}
		k++;
	}
	while(i<m)
	{
		c[k]=a[i];
		i++;
		k++;
	}
	while(j<n)
	{
		c[k]=b[j];
		j++;
		k++;
	}
	for(i=0;i<k;i++)
	{
		printf("%d ",c[i]);
	}
}
int main()
{
	int i,j,k,a[100],b[100],m,n;
	scanf("%d",&m);
	scanf("%d",&n);
	for(i=0;i<m;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
	}
	fun(a,b,m,n);
	return 0;
}