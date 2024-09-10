#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//多个数字能组成的最大数，每两个数连接进行比较
//比如7，13，4，246组成7424613
int compare(const void *a,const void *b)
{
	char ab[41],ba[41];
	strcpy(ab,*(const char **)a);
	//strcat把字符串接到原字符串后边，需要有足够空间
	strcat(ab,*(const char **)b);
	strcpy(ba,*(const char **)b);
	strcat(ba,*(const char **)a);
	return strcmp(ba,ab);
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		char **num=(char **)malloc(n*sizeof(char*));
		for(int i=0;i<n;i++)
		{
			//定义二维数组num
			num[i]=(char *)malloc(21*sizeof(char));
			//输入num
			scanf("%s",num[i]);
		}
		//qosrt排序，可以直接对字符数组排序
		qsort(num,n,sizeof(char *),compare);
		
		for(int i=0;i<n;i++)
		{
			printf("%s",num[i]);
		}
		printf("\n");
		//释放内存
		for(int i=0;i<n;i++)
		{
			free(num[i]);
		}
		free(num);
	}
	return 0;
}
//qsort定义在<stdlib.h>
//str三个定义在<string.h>