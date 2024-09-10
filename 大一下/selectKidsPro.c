#include <stdio.h>
#include <string.h>

// ��������
void eliminate_children(char children[][16], int N, int W, int S);

int main() {
    int N, W, S;
    char children[64][16];

    // ����С������
    scanf("%d", &N);
    
    // ����С������
    for (int i = 0; i < N; i++) {
        scanf("%s", children[i]);
    }

    // ������ʼλ�úͱ���
    scanf("%d,%d", &W, &S);

    eliminate_children(children, N, W, S);

    return 0;
}

void eliminate_children(char children[][16], int N, int W, int S) {
    int i, index = W - 1;
    int remaining = N;
    int count = 0;

    while (remaining > 0) {
        // �����Ѿ����е�С��
        if (children[index][0] != '\0') {
            count++;
        }

        // �ҵ���S��С��������
        if (count == S) {
            printf("%s\n", children[index]);
            children[index][0] = '\0'; // ���Ϊ����
            remaining--;
            count = 0; // ���ü�����
        }

        // �ƶ�����һ��С��
        index = (index + 1) % N;
    }
}
