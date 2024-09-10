#include <stdio.h>
#include <stdlib.h>

// 定义链表节点
struct Node {
    int id;
    struct Node* next;
};

// 插入节点到链表尾部
void insertNode(struct Node** head, int id) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->id = id;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// 输出链表中节点的值
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->id);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int n; // 车门数量
    scanf("%d", &n);

    int citizenCount[n]; // 每个车门的好公民排队人数
    for (int i = 0; i < n; ++i) {
        scanf("%d", &citizenCount[i]);
    }

    // 初始化每个车门的队列
    struct Node* queues[n];
    for (int i = 0; i < n; ++i) {
        queues[i] = NULL;
        for (int j = 0; j < citizenCount[i]; ++j) {
            int id;
            scanf("%d", &id);
            insertNode(&queues[i], id);
        }
    }

    int k; // 插队生物数量
    scanf("%d", &k);

    // 模拟插队过程
    for (int i = 0; i < k; ++i) {
        int bi, di; // 插队生物编号和插队的车门编号
        scanf("%d %d", &bi, &di);
        insertNode(&queues[di - 1], bi);
    }

    // 输出每个车门上车的人员编号
    for (int i = 0; i < n; ++i) {
        printList(queues[i]);
    }

    // 释放链表内存
    for (int i = 0; i < n; ++i) {
        struct Node* current = queues[i];
        while (current != NULL) {
            struct Node* temp = current;
            current = current->next;
            free(temp);
        }
    }

    return 0;
}