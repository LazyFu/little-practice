#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int start;
	int end;
}Interval;

int cmp(const void *a,const void *b)
{
	Interval *intervalA = (Interval *)a;
    Interval *intervalB = (Interval *)b;
    return intervalA->start - intervalB->start;
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		Interval intervals[n];
		for(int i=0;i<n;i++)
		{
			scanf("%d %d",&intervals[i].start,&intervals[i].end);
		}
		
		qsort(intervals,n,sizeof(Interval),cmp);
		
		int index=0;
		
		for(int i=1;i<n;i++)
		{
			if(intervals[index].end>=intervals[i].start)
			{
				if(intervals[index].end<intervals[i].end)
				{
					intervals[index].end=intervals[i].end;
				}
			}
			else
			{
				index++;
				intervals[index]=intervals[i];
			}
		}
		
		for(int i=0;i<=index;i++)
		{
			printf("%d %d\n",intervals[i].start,intervals[i].end);
		}
		printf("\n");
	}
	return 0;
}