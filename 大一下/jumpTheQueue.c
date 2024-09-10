#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		//定义队列二维数组
		int **queue=(int **)malloc(n*sizeof(int *));
		//定义每队列人数数组
		int *number=(int *)malloc(n*sizeof(int));
		for(int i=0;i<n;i++)
		{
			queue[i]=(int *)malloc(2000*sizeof(int));
		}
		for(int i=0;i<n;i++)
		{
			scanf("%d",&number[i]);
		}
		for(int i=0;i<n;i++)
		{
			for(int j=number[i]-1;j>=0;j--)
			{
				scanf("%d",&queue[i][j]);
			}
		}
		
		//开始插队
		int others,id,index;
		scanf("%d",&others);
		for(int i=0;i<others;i++)
		{
			scanf("%d %d",&id,&index);
			queue[index-1][number[index-1]]=id;
			number[index-1]++;
		}
		//输出
		for(int i=0;i<n;i++)
		{
			for(int j=number[i]-1;j>=0;j--)
			{
				printf("%d ",queue[i][j]);
			}
			printf("\n");
		}
		//释放内存
		for (int i = 0; i < n; i++) 
		{
            free(queue[i]);
        }
        free(queue);
        free(number);
	}
	return 0;
}