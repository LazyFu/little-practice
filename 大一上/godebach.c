#include<stdio.h>
#include<math.h>

int sushu(int n)
{
 int i,m;
 m=sqrt (1.0*n);
 for(i=2;i<=m;i++)
 if(n%i==0)break;
 if(i>m&&n!=1)
 n=1;
 else
 n=0;
 return n;
}

int main()
{
	int n,i,j;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=1;i<(n/2);i++)
			if(sushu(i)&&sushu(n-i))
			printf("%d+%d",i,(n-i));
			break;
	}
	return 0;
}