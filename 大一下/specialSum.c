#include<stdio.h>
#include<math.h>
//#include<limits.h>
//#include<float.h>
int main()
{
//	printf("%d\n",INT_MAX);1
//	printf("%ld\n",LONG_MAX);2
//	printf("%lld\n",LLONG_MAX);3
//	printf("%f\n",DBL_MAX);
//	2147483647	1
//	2147483647	2
//	9223372036854775807	3
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			int sum=0;
			for(int j=1;j<=a;j++)
			{
				sum+=pow(j,b);
			}
			sum%=10000;
			printf("%d\n",sum);
		}
	}
	return 0;
}