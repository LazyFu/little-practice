#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		//������ж�ά����
		int **queue=(int **)malloc(n*sizeof(int *));
		//����ÿ������������
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
		
		//��ʼ���
		int others,id,index;
		scanf("%d",&others);
		for(int i=0;i<others;i++)
		{
			scanf("%d %d",&id,&index);
			queue[index-1][number[index-1]]=id;
			number[index-1]++;
		}
		//���
		for(int i=0;i<n;i++)
		{
			for(int j=number[i]-1;j>=0;j--)
			{
				printf("%d ",queue[i][j]);
			}
			printf("\n");
		}
		//�ͷ��ڴ�
		for (int i = 0; i < n; i++) 
		{
            free(queue[i]);
        }
        free(queue);
        free(number);
	}
	return 0;
}