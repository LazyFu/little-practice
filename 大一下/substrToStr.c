#include<stdio.h>
#include<string.h>
int main()
{
	char str[20],substr[4];
	while(scanf("%s %s",str,substr)!=EOF)
	{
		int len=strlen(str);
		char maxChar=str[0];
		int start=0;
		for(int i=1;i<len;i++)
		{
			if(str[i]>maxChar)
			{
				maxChar=str[i];
				start=i;
			}
		}
		for(int j=len;j>start;j--)
		{
			str[j+2]=str[j-1];
		}
		for(int k=0;k<3;k++)
		{
			str[start+1+k]=substr[k];
		}
		str[len+3]='\0';
		printf("%s\n",str);
	}
	return 0;
}