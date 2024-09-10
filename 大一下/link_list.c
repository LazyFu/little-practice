#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<malloc.h>

const int mod = 46337; // ��������α�������ģ��
int id = 1; // ȫ�ֱ�������������α�����

// ����α������ĺ���
int myrand(int x)
{
    id += 2024; // ����һ���̶�ֵ
    id %= mod; // ȡģ
    id += x;
    id %= mod;
    id = id * id; // ƽ��
    id %= mod; // ȡģ
    id ++;
    id %= mod;
    while (id % 2 == 0 || id % 3 == 0)
    {
        id += 5; // ����һ���̶�ֵ
        id %= mod; // ȡģ
    }
    while(id == 1){
        id ++;
        id %= mod;
        while (id % 2 == 0 || id % 3 == 0)
        {
            id += 5; // ����һ���̶�ֵ
            id %= mod; // ȡģ
        }
    }
    return id % mod; // ����α�����
}

// ����ڵ�Ľṹ�嶨��
struct NODE
{
    int data; // �ڵ��е�����
    struct NODE * pnext; // ָ����һ���ڵ��ָ��
};

typedef struct NODE Node;

// �����ݲ��뵽�����еĺ���
void insert_to_list(Node * phead, int data)
{
    Node* p;
    // ��������ֱ��β��
    for(p = phead; p->pnext; p = p->pnext);
    // �����½ڵ㲢��������
    p->pnext = (Node *)malloc(sizeof(Node));
    p = p->pnext;
    p->pnext = NULL;
    p->data = data;
}

int main()
{
    Node a, b, *p; // ������������ڵ��һ��ָ��
    int n, i, d, j; // �����������ڿ���ѭ���ʹ洢�����
    a.pnext = b.pnext = NULL; // ��ʼ������ͷָ��ΪNULL
    scanf("%d", &n); // ��ȡ�û����������n����ʾ������ĸ���

    // ����n����������������Ƿ�Ϊ����������뵽����������
    for(int i = 0; i < n; i++)
    {
        d = myrand(n); // ����myrand()��������α�����
        // �ж�������Ƿ�Ϊ����
        int f = 0;
        for(int j = 2; j < d; j++)
            if(d % j == 0){
              f=1;//��2�� �жϿ�֪d��������ʱ��f=1
              break; 
            }                   
        if(f) 
            insert_to_list(&b, d);//��3�� �������������뵽����b��
        else 
            insert_to_list(&a, d); // �����������뵽����a��
    }

    // ��ӡ����a������
    printf("list 1: \n");
    for(p = a.pnext; p; p = p->pnext)
        printf("%d\t", p->data);

    // ��ӡ����b������
    printf("\nlist 2: \n");
    for(p = b.pnext; p; p = p->pnext)
        printf("%d\t", p->data);
    
    return 0;
}