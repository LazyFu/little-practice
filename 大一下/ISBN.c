#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
	char s[14];
	int i,m,T;
	scanf("%d\n",&T);
	for(m=0;m<T;m++)
	{
		int num[9]={0},t=0;
		scanf("%s",s);
		for(i=0;i<11;i++)
		{
			if(isdigit(s[i]))
			{
				num[t]=s[i]-'0';
				t++;
			}
		}
		int count=0;
		for(i=0;i<9;i++)
		{
			count+=(i+1)*num[i];
		}
		if(count%11==(s[12]-'0'))
			printf("Right\n");
		else if(count%11==10&&s[12]=='X')
			printf("Right\n");
		else
		{
			s[12]=(count%11)+'0';
			printf("%s\n",s);
		}
	}
	return 0;
}