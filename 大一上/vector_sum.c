#include<stdio.h>
#define N 100
void sum(int a[],int b[],int n,int c[])
{
	int i;
	for(i=0;i<n;i++)
		c[i]=a[i]+b[i];
}
int main()
{
	int a[N],i,n,b[N],c[N];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
		scanf("%d",&b[i]);
	sum(a,b,N,c);
	for(i=0;i<n;i++)
		printf("%d \n",c[i]);
	return 0;
}