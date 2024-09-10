#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp(const void *a,const void *b)
{
	return strcmp(*(char **)a,*(char **)b);
}

int main()
{
	char country[50][20],s[]="China";
	const char *sort[50];
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
			scanf("%s",&country[i]);
			sort[i]=country[i];
	}
	qsort(sort,n,sizeof(char *),cmp);
	for(i=0;i<n;i++)
	{
		if(strcmp(sort[i],s)==0)
			continue;
		printf("%s\n",sort[i]);
	}
	printf("China\n");
	return 0;
}