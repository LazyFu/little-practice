#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int id;
	struct Node* next;
};

struct Node* insertNode(struct Node* head,int id)
{
	struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
	newNode->id=id;
	newNode->next=head;
	return newNode;
}

void printList(struct Node* head)
{
	struct Node* current=head;
	while(current!=NULL)
	{
		printf("%d ",current->id);
		current=current->next;
	}
	printf("\n");
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int *citizen=(int *)malloc(n*sizeof(int));
		for(int i=0;i<n;i++)
		{
			scanf("%d",&citizen[i]);
		}
		struct Node* door[n];
		for(int i=0;i<n;i++)
		{
			door[i]=NULL;
			for(int j=0;j<citizen[i];j++)
			{
				int id;
				scanf("%d",&id);
				door[i]=insertNode(door[i],id);
			}
		}
		//��ӵ�����
		int k;
		scanf("%d",&k);
		
		//ģ����
		for(int i=0;i<k;i++)
		{
			int id2,door2;//����˱�źͳ��ű��
			scanf("%d %d",&id2,&door2);
			door[door2-1]=insertNode(door[door2-1],id2);
		}
		
		//���
		for(int i=0;i<n;i++)
		{
			printList(door[i]);
		}
		
		//�ͷ������ڴ�
		for(int i=0;i<n;i++)
		{
			struct Node* current=door[i];
			while(current!=NULL)
			{
				struct Node* temp=current;
				current=current->next;
				free(temp);
			}
		}
	}
	return 0;
}