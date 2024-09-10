#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void reverse(char numStr[])
{
	int n=strlen(numStr);
	int len=n;
	for(int i=len-1;i>=0;i--)
	{
		if(numStr[i]=='0')
			len--;
		else 
			break;
	}
	if(numStr[0]=='-')
		for(int i=1;i<=len/2;i++)
		{
			char temp=numStr[i];
			numStr[i]=numStr[len-i];
			numStr[len-i]=temp;
		}
	else
		for(int i=0;i<len/2;i++)
		{
			char temp=numStr[i];
			numStr[i]=numStr[len-i-1];
			numStr[len-i-1]=temp;
		}
	numStr[len]='\0';
	printf("%s\n",numStr);
}

int main()
{
	char numStr[100];
	while(scanf("%s",&numStr)!=EOF)
	{
		reverse(numStr);
	}
	return 0;
}