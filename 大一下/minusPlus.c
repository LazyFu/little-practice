#include<stdio.h>
#include<string.h>

void strToArray(char str[],int r[]);

int main()
{
	int i,j;
	char a[201],b[201];
	while(scanf("%s",a)!=EOF)
	{
		scanf("%s",b);
		int num1[201]={0},num2[201]={0};
		strToArray(a,num1);
		strToArray(b,num2);
		int s[201]={0};
		for(i=200;i>=0;i--)
		{
			if(num1[i]>=num2[i])
			{
				s[i]+=num1[i]-num2[i];
			}
			else
			{
				s[i]=num1[i]+10-num2[i];
				num1[i-1]-=1;
			}
		}
		int start=0;
		for(i=0;i<201;i++)
		{
			if(s[i]!=0)
			{
			start=i;
			break;
			}
		}
		if(start==0)
		{
			printf("0\n");
		}
		else
		{
		for(i=start;i<201;i++)
		{
			printf("%d",s[i]);
		}
		printf("\n");
		}
	}
	return 0;
}

void strToArray(char str[],int r[])
{
	int len=strlen(str);
	for(int i=200,j=len-1;j>=0&&i>=0;j--,i--)
	{
		r[i]=str[j]-'0';
	}
}

/*int minus(int a[],int b[],int i,int s[])minus
{
	if(a[i]>=b[i])
	{
		s[i]+=a[i]-b[i];
		return s[i];
	}
	else
	{
		s[i]=a[i]-b[i]+10;
		a[i-1]-=1;
	}
}*/