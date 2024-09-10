#include<stdio.h>
#include<string.h>
/*wrong answer*/

void charToArray(char *n,int *num)
{
	int len=strlen(n);
	for(int i=0;i<len;i++)
	{
		num[i]=n[i]-'0';
	}
}

int main()
{
	char n[60];
	while(scanf("%s",n)!=EOF)
	{
		int judge=1;
		int num[60],len=strlen(n);
		charToArray(n,num);
		int temp[60]={0};
		for(int i=1;i<=len;i++)
		{
			for(int j=len-1;j>=0;j--)
			{
				temp[j]+=num[j]*i;
				if(temp[j]>=10&&j!=0)
				{
					int carry=temp[j]/10;
					temp[j]%=10;
					temp[j-1]+=carry;
				}
				else if(temp[0]>=10)
				{
					judge=0;
					break;
				}
			}
			if(judge==0)
				break;
			else
			{
				for(int j=len-1;j>=0;j++)
				{
					if(temp[j]!=num[j])
					{
						judge=0;
						break;
					}
				}
			}
		}
		if(judge==0)
		{
			printf("%s is not cyclic\n",n);
		}
		else
		{
			printf("%s is cyclic\n",n);
		}
	}
	return 0;
}