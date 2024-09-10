#include <stdio.h>
#include <stdlib.h>

// ��������ڵ�
struct Node {
    int id;
    struct Node* next;
};

// ����ڵ㵽����β��
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

// ��������нڵ��ֵ
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->id);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int n; // ��������
    scanf("%d", &n);

    int citizenCount[n]; // ÿ�����ŵĺù����Ŷ�����
    for (int i = 0; i < n; ++i) {
        scanf("%d", &citizenCount[i]);
    }

    // ��ʼ��ÿ�����ŵĶ���
    struct Node* queues[n];
    for (int i = 0; i < n; ++i) {
        queues[i] = NULL;
        for (int j = 0; j < citizenCount[i]; ++j) {
            int id;
            scanf("%d", &id);
            insertNode(&queues[i], id);
        }
    }

    int k; // �����������
    scanf("%d", &k);

    // ģ���ӹ���
    for (int i = 0; i < k; ++i) {
        int bi, di; // ��������źͲ�ӵĳ��ű��
        scanf("%d %d", &bi, &di);
        insertNode(&queues[di - 1], bi);
    }

    // ���ÿ�������ϳ�����Ա���
    for (int i = 0; i < n; ++i) {
        printList(queues[i]);
    }

    // �ͷ������ڴ�
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