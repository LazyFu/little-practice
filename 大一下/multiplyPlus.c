#include<stdio.h>
#include<string.h>

void charToInt(char *s,int *num)
{
	int len=strlen(s);
	for(int i=0,j=len-1;i<len,j>=0;i++,j--)
	{
		num[i]=s[j]-'0';
	}
}

int main()
{
	char a[101],b[101];
	int num1[101]={0},num2[101]={0};
	while(scanf("%s",a)!=EOF)
	{
		scanf("%s",b);
		int len1=strlen(a),len2=strlen(b);
		int start=0;
		int sum=0;
		int result[201]={0};
		charToInt(a,num1);
		charToInt(b,num2);
		for(int i=0;i<len2;i++)
		{
			for(int j=0;j<len1;j++)
			{
				
				int t=i+j;
				sum=num1[j]*num2[i]+result[t];
				result[t]=sum%10;
				result[t+1]+=sum/10;
			}
		}
		for(int i=0;i<201;i++)
		{
			if(result[i]!=0)
			{
				start=i;
			}
		}
		for(int i=start;i>=0;i--)
		{         
			printf("%d",result[i]);
		}
		printf("\n");
	}
	return 0;
}