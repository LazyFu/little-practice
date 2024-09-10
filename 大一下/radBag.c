#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{
	int money;
	int receive;
	int number;
}RedBag;

// 比较函数，用于 qsort
int compareMoney(const void *a, const void *b) 
{
    RedBag *redbagA = (RedBag *)a;
    RedBag *redbagB = (RedBag *)b;
    if (redbagA->money != redbagB->money) 
	{
        return redbagB->money - redbagA->money; // 从大到小排序
    } else if (redbagA->receive != redbagB->receive) 
	{
        return redbagB->receive - redbagA->receive; // 按 receive 从大到小排序
    } else 
	{
        return redbagA->number - redbagB->number; // 按 number 从小到大排序
    }
}

int main()
{
	int n,send,temp,num;//总人数，发送个数，发送金额，编号
	scanf("%d",&n);
	RedBag *redbag=(RedBag *)malloc(n*sizeof(RedBag));//attention!
	for (int i = 0; i < n; i++) 
	{
    	redbag[i].money = 0;
   		redbag[i].receive = 0;
   		redbag[i].number = i + 1;
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",&send);
		for(int j=0;j<send;j++)
		{
			scanf("%d %d",&num,&temp);
			redbag[num-1].receive++;//计数个数
			redbag[i].money-=temp;//发红包
			redbag[num-1].money+=temp;//收红包
		}
	}
	//输出
	//排序
	qsort(redbag,n,sizeof(RedBag),compareMoney);
	for(int i=0;i<n;i++)
	{
		printf("%d %.2f\n",redbag[i].number,redbag[i].money*0.01);
	}
	free(redbag);
	return 0;
}