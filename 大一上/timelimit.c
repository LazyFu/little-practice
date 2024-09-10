#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // 动态分配内存保存字符串
    char** strings = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        strings[i] = (char*)malloc(20001 * sizeof(char));
        scanf("%s", strings[i]);
    }

    // 处理交换操作
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        char* temp = strings[x - 1];
        strings[x - 1] = strings[y - 1];
        strings[y - 1] = temp;
    }

    // 输出字符串
    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
    }

    // 释放内存
    for (int i = 0; i < n; i++) {
        free(strings[i]);
    }
    free(strings);

    return 0;
}