#include<stdio.h>

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==-1)
		{
			break;
		}
		char week[7][10]={"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
		char *day_of_week=week[n%7];
		n=n+1;
		int year=2000,month=1,day=1;
		for(int i=2000;i<=9999;i++)
		{
			if(i%4==0&&i%100!=0||i%400==0)
			{
				if(n>366)
				{
					n-=366;
				}
				else
				{
					year=i;
					break;
				}
			}
			else
			{
				if(n>365)
				{
					n-=365;
				}
				else
				{
					year=i;
					break;
				}
			}
		}
		int months[12]={31,28,31,30,31,30,31,31,30,31,30,31};
		if(year%4==0&&year%100!=0||year%400==0)
		{
			months[1]=29;
		}
		for(int i=1;i<=12;i++)
		{
			if(n>months[i-1])
			{
				n-=months[i-1];
			}
			else
			{
				day=n;
				month=i;
				break;
			}
		}
		printf("%d-%02d-%02d %s\n",year,month,day,day_of_week);
	}
	return 0;
}