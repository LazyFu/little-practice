#include<stdio.h>
#include<math.h>

int main()/*输入一个数判断是不是素数（质数）*/
{
	int i,m,n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n<=0)
			printf("输入数据错误！");
		else
		{
		m=sqrt(1.0*n);
		for(i=2;i<=m;i++)
			if(n%i==0)break;
		if(i>m)
			printf("%d是素数\n",n);
		else
			printf("%d不是素数\n",n);
		}
	}
	return 0;
}