#include<stdio.h>
#include<math.h>

int main()/*����һ�����ж��ǲ���������������*/
{
	int i,m,n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n<=0)
			printf("�������ݴ���");
		else
		{
		m=sqrt(1.0*n);
		for(i=2;i<=m;i++)
			if(n%i==0)break;
		if(i>m)
			printf("%d������\n",n);
		else
			printf("%d��������\n",n);
		}
	}
	return 0;
}