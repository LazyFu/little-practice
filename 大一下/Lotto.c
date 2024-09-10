#include<stdio.h>
#include<stdlib.h>
//�ȽϺ�������������
int cmp(const void *m,const void *n)
{
	return (*(int *)m-*(int *)n);
}
//�����ǰ���
void printCombination(int *r)
{
	for(int j=0;j<6;j++)
		{
			printf("%d ",r[j]);
		}
	printf("\n");
}
//�ݹ��������
void generateCombination(int *a,int index,int start,int end,int x,int *r)
{
	if(index==x)
	{
		printCombination(r);
		return;
	}
	for(int i=start;i<=end&&end-i+1>=x-index;i++)/*end-i+1>=x-index*/
	{
		r[index]=a[i];
		generateCombination(a,index+1,i+1,end,x,r);
	}

}

int main()
{
	int k,i;
	while (scanf("%d", &k) != EOF)
	{
		int *a = (int*)malloc(k*sizeof(int));
		for (i = 0; i < k; i++)
		{
			scanf("%d", &a[i]);
		}
		qsort(a,k,sizeof(int),cmp);
		int r[6]={0};
		
		generateCombination(a,0,0,k-1,6,r);
		
		free(a);
	}
	return 0;
}