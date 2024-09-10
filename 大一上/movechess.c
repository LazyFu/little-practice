#include <stdio.h>

void moveChess(int n) {
    int total = 2 * n;
    int i;

    // 初始化棋子排列
    char chess[total];
    for (i = 0; i < n; i++) {
        chess[i] = 'O';
        chess[i+n] = 'X';
    }

    // 输出初始棋子排列
    for (i = 0; i < total; i++) {
        printf("%c", chess[i]);
    }
    printf("\n");

    // 移动棋子
    for (i = 0; i < n-1; i++) {
        // 交换相邻两个棋子
        char temp = chess[i];
        chess[i] = chess[i+1];
        chess[i+1] = temp;

        // 输出移动步骤
        printf("%d,%d-->%d,%d\n", i+1, i+2, i+n+1, i+n+2);

        // 输出移动后的棋子排列
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