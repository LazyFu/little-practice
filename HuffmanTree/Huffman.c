#include "Huffman.h"
#include<ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//显示帮助信息
void showhelp()
{
    printf("H:显示帮助信息\n");
    printf("I:输入字符个数，输入字符数据和权重，创建哈夫曼树\n");
    printf("E:编码\n");
    printf("D:译码\n");
    printf("P:打印代码文件\n");
    printf("T:打印哈夫曼树\n");
    printf("Q:退出程序\n");
}

//创建哈夫曼树结点
HufTree CreateNode(char data, int weight)
{
    HufTree node = (HufTree)malloc(sizeof(HufNode));
    if (node == NULL)
    {
        perror("内存分配失败\n");
        return NULL;
    }
    node->data = data;
    node->weight = weight;
    node->left = NULL;
    node->right = NULL;
    return node;
}

//插入哈夫曼树结点到优先队列
void InsertHufNode(PriorityQueue** head, HufTree tree)
{
    PriorityQueue* node = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    node->tree = tree;
    node->next = NULL;
    //权重小的在队前
    if (*head == NULL || (*head)->tree->weight > tree->weight)
    {
        node->next = *head;
        *head = node;
    }
    else
    {
        PriorityQueue* current = *head;
        while (current->next != NULL && current->next->tree->weight <= tree->weight)
        {
            current = current->next;
        }
        node->next = current->next;
        current->next = node;
    }
}

//最小的先出队，返回哈夫曼树叶子节点
HufTree PriorityQueueOut(PriorityQueue** head)
{
    PriorityQueue* node = *head;
    *head = (*head)->next;
    HufTree tree = node->tree;
    free(node);
    return tree;
}

//创建哈夫曼树
HufTree CreateHuffmanTree()
{
    int n;
    char data;
    int weight;
    printf("输入字符个数：");
    scanf("%d", &n);
    printf("输入每个字符的数据和权重，一行一个字符和权重：\n");
    //所有数据插入优先队列
    PriorityQueue* PriorityQueue = NULL;
    for (int i = 0; i < n; i++)
    {
        scanf(" %c %d", &data, &weight);
        HufTree node = CreateNode(data, weight);
        InsertHufNode(&PriorityQueue, node);
    }
    //构建哈夫曼树
    while (PriorityQueue != NULL && PriorityQueue->next != NULL)
    {
        HufTree left = PriorityQueueOut(&PriorityQueue);
        HufTree right = PriorityQueueOut(&PriorityQueue);
        HufTree parent = CreateNode('\0', left->weight + right->weight);
        parent->left = left;
        parent->right = right;
        //两最小的节点合并后插入优先队列
        InsertHufNode(&PriorityQueue, parent);
    }
    return PriorityQueueOut(&PriorityQueue);
}

//保存哈夫曼树到文件
void SaveHufTree(HufTree T, FILE* file)
{
    if (T != NULL)
    {
        if (T->data != '\0')
        {
            fprintf(file, "%c %d\n", T->data, T->weight);
        }
        SaveHufTree(T->left, file);
        SaveHufTree(T->right, file);
    }
}

//从文件中导入哈夫曼树
HufTree LoadHufTree()
{
    FILE* file = fopen("hfmtree.txt", "r");
    if (file == NULL)
    {
        perror("无法打开文件hfmtree\n");
        return NULL;
    }
    char data;
    int weight;
    PriorityQueue* PriorityQueue = NULL;
    while (fscanf(file, "%c %d\n", &data, &weight) != EOF)
    {
        HufTree node = CreateNode(data, weight);
        InsertHufNode(&PriorityQueue, node);
    }
    //构建哈夫曼树
    while (PriorityQueue != NULL && PriorityQueue->next != NULL)
    {
        HufTree left = PriorityQueueOut(&PriorityQueue);
        HufTree right = PriorityQueueOut(&PriorityQueue);
        HufTree parent = CreateNode('\0', left->weight + right->weight);
        parent->left = left;
        parent->right = right;
        //两最小的节点合并后插入优先队列
        InsertHufNode(&PriorityQueue, parent);
    }
    printf("导入哈夫曼树完成\n");
    fclose(file);
    return PriorityQueueOut(&PriorityQueue);
}

// 构建编码表
void buildCodeTable(HufTree T, char** codeTable, char* code, int depth)
{
    if (T->left == NULL && T->right == NULL)
    {
        code[depth] = '\0';
        codeTable[(unsigned char)T->data] = _strdup(code);
        return;
    }
    if (T->left != NULL)
    {
        code[depth] = '0';
        buildCodeTable(T->left, codeTable, code, depth + 1);
    }
    if (T->right != NULL)
    {
        code[depth] = '1';
        buildCodeTable(T->right, codeTable, code, depth + 1);
    }
}

// 释放编码表
void freeCodeTable(char** codeTable)
{
    for (int i = 0; i < 256; i++)
    {
        if (codeTable[i] != NULL)
        {
            free(codeTable[i]);
        }
    }
}

//编码
void Encode(HufTree T)
{
    FILE* file = fopen("ToBeTran.txt", "r");
    if (file == NULL)
    {
        perror("无法打开文件ToBeTran\n");
        return;
    }
    FILE* out = fopen("CodeFile.txt", "w");
    if (out == NULL)
    {
        perror("无法创建文件CodeFile\n");
        return;
    }
    // 构建编码表
    char* codeTable[256] = { 0 };
    char code[256];
    buildCodeTable(T, codeTable, code, 0);
    // 读取文件并编码
    char data;
    while (fscanf(file, "%c", &data) != EOF)
    {
        data=tolower((unsigned char)data);
        if (codeTable[(unsigned char)data] != NULL)
        {
            fprintf(out, "%s", codeTable[(unsigned char)data]);
        }
    }
    printf("编码完成\n");
    fclose(file);
    fclose(out);
    // 释放编码表
    freeCodeTable(codeTable);
}

//译码
void Decode(HufTree T)
{
    FILE* file = fopen("CodeFile.txt", "r");
    if (file == NULL)
    {
        perror("无法打开文件CodeFile\n");
        perror("检查是否已经编码\n");
        return;
    }
    FILE* out = fopen("TextFile.txt", "w");
    if (out == NULL)
    {
        perror("无法创建文件TextFile\n");
        return;
    }
    char bit;
    HufTree current = T;
    while (fscanf(file, "%c", &bit) != EOF)
    {
        if (bit == '0')
        {
            current = current->left;
        }
        else if (bit == '1')
        {
            current = current->right;
        }
        if (current->data != '\0')
        {
            fprintf(out, "%c", current->data);
            current = T;
        }
    }
    printf("译码完成\n");
    fclose(file);
    fclose(out);
}

//打印代码文件
void PrintCode()
{
    FILE* file = fopen("CodeFile.txt", "r");
    if (file == NULL)
    {
        perror("无法打开文件CodeFile\n");
        return;
    }
    FILE* out = fopen("CodePrint.txt", "w");
    char bit;
    int count = 0;
    while (fscanf(file, "%c", &bit) != EOF)
    {
        printf("%c", bit);
        count++;
        if (count % 50 == 0)
        {
            printf("\n");
            fprintf(out, "\n");
        }
        fprintf(out, "%c", bit);
    }
    printf("\nCodeFile输出完成，且写入到CodePrint中\n");
    fclose(file);
    fclose(out);
}

//打印哈夫曼树
void PrintHufTree(HufTree T, int depth, FILE* file)
{
    if (T != NULL)
    {
        if (T->data != '\0')
        {
            for (int i = 0; i < depth; i++)
            {
                printf("\t");
                fprintf(file, "\t");
            }
            printf("%c %d\n", T->data, T->weight);
            fprintf(file, "%c %d\n", T->data, T->weight);
        }
        PrintHufTree(T->left, depth + 1, file);
        PrintHufTree(T->right, depth + 1, file);
    }
}