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
			case 9:printf("��\n");break;
			case 8:printf("��\n");break;
			case 7:printf("��\n");break;
			case 6:printf("����\n");break;
			default:printf("������\n");break;
			}
	}
	return 0;
}