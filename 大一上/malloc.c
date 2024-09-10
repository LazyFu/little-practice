#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // 动态分配内存保存字符串
    char** strings = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        int l;
        scanf("%d", &l);
        strings[i] = (char*)malloc((l + 1) * sizeof(char));
        scanf("%s", strings[i]);
    }

    // 处理查询
    for (int i = 0; i < m; i++) {
        int query;
        scanf("%d", &query);
        printf("%s\n", strings[query - 1]);
    }

    // 释放内存
    for (int i = 0; i < n; i++) {
        free(strings[i]);
    }
    free(strings);

    return 0;
}