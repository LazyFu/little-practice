#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b)
{
	return (*(int *)a-*(int *)b);
}

int main()
{
	int times;
	while(scanf("%d",&times)!=EOF)
	{
		
		for(int i=0;i<times;i++)
		{
			int lenth,num;
			
			scanf("%d %d",&lenth,&num);
			int *ants=(int *)malloc(num*sizeof(int));
			for(int j=0;j<num;j++)
			{
				scanf("%d",&ants[j]);
			}
			
			//蚂蚁位置排序
			qsort(ants,num,sizeof(int),cmp);
			//最短时间
			int min=1000;
			for(int j=0;j<num;j++)
			{
				if(ants[j]<=lenth/2&&min>(lenth/2-ants[j]))
				{
					min=lenth/2-ants[j];
				}
				else if(ants[j]>lenth/2&&min>(ants[j]-lenth/2))
				{
					min=ants[j]-lenth/2;
				}
			}
			printf("%d ",lenth/2-min);
			//最远距离，最长时间
			if((lenth-ants[0])>=ants[num-1])
			{
				printf("%d",lenth-ants[0]);
			}
			else
			{
				printf("%d",ants[num-1]);
			}
			printf("\n");
			free(ants);
		}
	}
	return 0;
}