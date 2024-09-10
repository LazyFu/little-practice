#include<stdio.h>
#include<string.h>
//∂®“Â”≥…‰
char *numbers[]=
{
	"zero","one","two","three","four",
	"five", "six", "seven", "eight", "nine",
    "ten", "eleven", "twelve", "thirteen", "fourteen",
    "fifteen", "sixteen", "seventeen", "eighteen", "nineteen",
};
char *tens[]=
{
    "", "", "twenty", "thirty", "forty",
    "fifty", "sixty", "seventy", "eighty", "ninety"
};
int main()
{
	int h,m;
	while(scanf("%d %d",&h,&m)!=EOF)
	{
		if(m==0)
		{
			if(h<20)
			{
				printf("%s o'clock",numbers[h]);
			}
			else
			{
				printf("%s ",tens[2]);
				if(h%10!=0)
				{
					printf("%s o'clock",numbers[h%10]);
				}
				else
				{
					printf("o'clock");
				}
			}
		}
		else
		{
			if(h<20)
			{
				if(m<20)
				{
					printf("%s %s",numbers[h],numbers[m]);
				}
				else
				{
					printf("%s ",numbers[h]);
					printf("%s ",tens[m/10]);
					if(m%10!=0)
					{
						printf("%s",numbers[m%10]);
					}
				}
			}
			else
			{
				if(m<20)
				{
					printf("%s ",tens[h/10]);
					if(h%10!=0)
					{
						printf("%s ",numbers[h%10]);
					}
					printf("%s",numbers[m]);
				}
				else
				{
					printf("%s ",tens[h/10]);
					if(h%10!=0)
					{
						printf("%s ",numbers[h%10]);
					}
					printf("%s ",tens[m/10]);
					if(m%10!=0)
					{
						printf("%s",numbers[m%10]);
					}
				}
			}
		}
		printf("\n");
	}
	return 0;
}