#include<stdio.h>
int leap(int n)
{
	if(n%4==0&&n%400!=0||n%400==0)
		n=1;
	else
		n=0;
		return n;
}
int main()
{
	int year,month;
	while(scanf("%d %d",&year,&month)!=EOF)
	{
		if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
			printf("31\n");
		else if(month==4||month==6||month==9||month==11)
			printf("30\n");
		else if(leap(year)==1)
			printf("29\n");
		else if(leap(year)==0)
			printf("28\n");
	}
	return 0;
}