#include<stdio.h>
#include<string.h>

void strToArray(char str[],int r[]);

int main()
{
	int n,a,b;
	scanf("%d",&n);
	int i,j,k;
		for(k=0;k<n;k++)/*这里不能用i，因为后边i的值会变化，提前结束循环，需要另设变量k*/
		{
			char a[201],b[201];/*按字符输入后转化成数字*/
			scanf("%s",&a);
		scanf("%s",&b);
		int start=0;
		int num1[201]={0},num2[201]={0};
		strToArray(a,num1);
		strToArray(b,num2);
		int s[201]={0};
		for(j=200;j>=0;j--)
		{
			s[j]+=num1[j]+num2[j];
			if(s[j]>=10)
			{
				s[j]-=10;
				s[j-1]+=1;
			}
		}
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
	int len=strlen(str);/*靠近最后一位，避免混淆0*/
	for(int i=200,j=len-1;j>=0&&i>=0;j--,i--)
	{
		r[i]=str[j]-'0';
	}
}