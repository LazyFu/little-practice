#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
/*online judge P1131*/
char* reverseString(char* substr)/*��ת�ַ���*/
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

int isSubstring(char* str,char* substr)/*strstr�����ж��ִ��Ƿ���ĸ����*/
{
    return strstr(str,substr)!=NULL;
}

bool isValid(char* str,char* substr)/*��δ��ת���ִ����Ƿ�ת���ִ�*/
{
	return isSubstring(str,substr)||isSubstring(str,reverseString(substr));
}

int longestSubstring(char** strings,int n)/*�ҵ���̵��ַ�������ȷ������һ��*/
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
	//���ȴӴ�СѰ�ҿ��ܺ��ʵ��ִ�
	for(int len=min_len;len>=1;len--)
	{
		//��s���ַ�����len���ֳ�С�����������Ƚ�
		for(int i=0;i<min_len+1-len;i++)
		{	
			char substring[101];
			//ÿlen���ַ���ȡ���������αȽ�
			strncpy(substring,strings[s]+i,len);
			substring[len]='\0';
			
			//�������ַ����Ա�
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
