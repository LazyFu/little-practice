#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp(const void *a,const void *b)
{
	char *str1=*(char **)a;
	char *str2=*(char **)b;
	return strcmp(str1,str2);
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		getchar();
		char **str=(char **)malloc(n*sizeof(char*));
		for(int i=0;i<n;i++)
		{
			str[i]=(char *)malloc(100*sizeof(char));
			fgets(str[i],100,stdin);
			
			if(str[i][strlen(str[i])-1]=='\n')
			{
				str[i][strlen(str[i])-1]='\0';
			}
		}
		
		
		qsort(str,n,sizeof(char *),cmp);
		
		

		for(int i=0;i<n;i++)
		{
			printf("%s\n",str[i]);
		}
		
		for(int i=0;i<n;i++)
		{
			free(str[i]);
		}
		free(str);
	}
	return 0;
}