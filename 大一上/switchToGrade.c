#include<stdio.h>
int main()
{
	int n;
	while(1)
	{
		scanf("%d",&n);
		if(n==-1)
			break;
		switch(n/10)
		{
			case 10:
			case 9:printf("优\n");break;
			case 8:printf("良\n");break;
			case 7:printf("中\n");break;
			case 6:printf("及格\n");break;
			default:printf("不及格\n");break;
			}
	}
	return 0;
}