#include<stdio.h>
int main()
{
	int l,m;/*l代表马路长度，m代表区域数目*/
	int i,j,first,last;
	int road[10001]={0};/*有树标记为0，移除后为1*/
	while(scanf("%d %d",&l,&m)!=EOF)
	{
	int count=0;
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&first,&last);
		for(j=first;j<=last;j++)
		{
			road[j]=1;
		}
	}
	for(i=0;i<=l;i++)
	{
		if(road[i]==0)
		{
			count++;
		}
	
	}
	printf("%d\n",count);
}
	return 0;
}