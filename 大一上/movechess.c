#include <stdio.h>

void moveChess(int n) {
    int total = 2 * n;
    int i;

    // ��ʼ����������
    char chess[total];
    for (i = 0; i < n; i++) {
        chess[i] = 'O';
        chess[i+n] = 'X';
    }

    // �����ʼ��������
    for (i = 0; i < total; i++) {
        printf("%c", chess[i]);
    }
    printf("\n");

    // �ƶ�����
    for (i = 0; i < n-1; i++) {
        // ����������������
        char temp = chess[i];
        chess[i] = chess[i+1];
        chess[i+1] = temp;

        // ����ƶ�����
        printf("%d,%d-->%d,%d\n", i+1, i+2, i+n+1, i+n+2);

        // ����ƶ������������
        for (int j = 0; j < total; j++) {
            printf("%c", chess[j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        moveChess(n);
    }
    return 0;
}