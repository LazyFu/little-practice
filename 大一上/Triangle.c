#include<stdio.h>
#include<math.h>
int main()/*输入三角形的三条边，判断能否构成三角形，不能输出-1，能则计算面积*/
{
	int a,b,c;
	double s,p;
	while(scanf("%d %d %d",&a,&b,&c)!=EOF)
	{
		if(a+b<=c||a+c<=b||b+c<=a)
			printf("-1\n");
		else
		{
			p=(a+b+c)/2.0;
			s=sqrt(p*(p-a)*(p-b)*(p-c));
			printf("%.2f\n",s);
		}
	}
	return 0;
}