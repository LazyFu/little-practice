#include<stdio.h>
#include<math.h>
int main()
{
	int i,m,x;
	scanf("%d",&x);
	m=sqrt(1.0*x);
	for(i=2;i<=m;i++)
		if(x%i==0)break;
	if(i>m&&x!=1)
		printf("3");
	else
		printf("4");
		return 0;
}