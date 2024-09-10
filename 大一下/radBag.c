#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{
	int money;
	int receive;
	int number;
}RedBag;

// �ȽϺ��������� qsort
int compareMoney(const void *a, const void *b) 
{
    RedBag *redbagA = (RedBag *)a;
    RedBag *redbagB = (RedBag *)b;
    if (redbagA->money != redbagB->money) 
	{
        return redbagB->money - redbagA->money; // �Ӵ�С����
    } else if (redbagA->receive != redbagB->receive) 
	{
        return redbagB->receive - redbagA->receive; // �� receive �Ӵ�С����
    } else 
	{
        return redbagA->number - redbagB->number; // �� number ��С��������
    }
}

int main()
{
	int n,send,temp,num;//�����������͸��������ͽ����
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
			redbag[num-1].receive++;//��������
			redbag[i].money-=temp;//�����
			redbag[num-1].money+=temp;//�պ��
		}
	}
	//���
	//����
	qsort(redbag,n,sizeof(RedBag),compareMoney);
	for(int i=0;i<n;i++)
	{
		printf("%d %.2f\n",redbag[i].number,redbag[i].money*0.01);
	}
	free(redbag);
	return 0;
}