#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
/*online judge P1131*/
char* reverseString(char* substr)/*反转字符串*/
{
	char c;
	int len=strlen(substr);
	for(int i=0;i<len/2;i++)
	{
		c=substr[i];
		substr[i]=substr[len-1-i];
		substr[len-1-i]=c;
	}
	return substr;
}

int isSubstring(char* str,char* substr)/*strstr函数判断字串是否在母串中*/
{
    return strstr(str,substr)!=NULL;
}

bool isValid(char* str,char* substr)/*是未反转的字串或是反转的字串*/
{
	return isSubstring(str,substr)||isSubstring(str,reverseString(substr));
}

int longestSubstring(char** strings,int n)/*找到最短的字符串，并确定是哪一串*/
{
	int min_len=strlen(strings[0]);
	int s=0;
	for(int i=1;i<n;i++)
	{
		int len=strlen(strings[i]);
		if(len<min_len)
		{
			s=i;
			min_len=len;
		}
	}
	//长度从大到小寻找可能合适的字串
	for(int len=min_len;len>=1;len--)
	{
		//第s个字符串按len划分成小串，与其他比较
		for(int i=0;i<min_len+1-len;i++)
		{	
			char substring[101];
			//每len个字符提取出来，依次比较
			strncpy(substring,strings[s]+i,len);
			substring[len]='\0';
			
			//和其他字符串对比
			int valid=1;
			for(int j=0;j<n;j++)
			{
				if(!isValid(strings[j],substring))
				{
					valid=0;
					break;
				}
			}
			if(valid)
			{
				return len;
			}
		}
	}
	return 0;
}

int main()
{
	int t,n,i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		char** strings=(char**)malloc(n*sizeof(char*));
		for(i=0;i<n;i++)
		{
			strings[i]=(char*)malloc(101*sizeof(char));
			scanf("%s",strings[i]);
		}
		int longest=longestSubstring(strings,n);
		printf("%d\n",longest);
		for(j=0;j<n;j++)
		{
			free(strings[j]);
		}
		free(strings);
	}
	return 0;
}
