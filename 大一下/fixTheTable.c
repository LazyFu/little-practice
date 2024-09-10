#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<malloc.h>

const int mod = 46337;
int id = 1;

int myrand()
{
	id += 2024;
	id %= mod;
	id = id * id;
	id %= mod;
	return id;
}

int main()
{
    int n, m, c;
    int *p;
    while(1)
    {
        printf("输入n和m的值，以逗号隔开。例如4,9\n");
        scanf("%d,%d", &n, &m);
        if(n * n < m)
        {
            printf("m值过大,请重新输入\n");
            continue;
        }
    
        // 申请动态内存
        p=(int *)malloc(n*n*sizeof(int));
        
        // 检查内存是否分配成功
        if(p == NULL)
        {
            printf("内存不足，请重新输入\n");
            continue;
        }
    
        if(p != NULL) break;
    }
    
    // 初始化矩阵
    for(int i = 0; i < n * n; i++)
        *(p + i) = 0;

    for(int i = 1; i <= m; i++)
    {
        do{
            c = myrand() % (n * n);
        } while(*(p + c) != 0);
        *(p+c)=i; 
    }
    
    // 打印矩阵
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            printf("%4d",*(p+i*n+j)); // 修正打印矩阵的方式
        printf("\n");
    }
    free(p);
    return 0;
}