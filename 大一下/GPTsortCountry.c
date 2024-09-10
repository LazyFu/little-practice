#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义最大国家名数量和长度
#define MAX_COUNTRIES 100
#define MAX_LENGTH 100

// 比较函数，用于 qsort 排序
int compare(const void *a, const void *b) {
    const char *const *str1 = (const char *const *)a;
    const char *const *str2 = (const char *const *)b;
    return strcmp(*str1, *str2);
}

int main() {
    int n;
    char countries[MAX_COUNTRIES][MAX_LENGTH]; // 存储国家名
    const char *sorted_countries[MAX_COUNTRIES]; // 指针数组用于排序

    // 输入参加国家数 n
    scanf("%d", &n);
    getchar(); // 吸收换行符

    // 输入国家名，并将其存储到数组中
    for (int i = 0; i < n; ++i) {
        fgets(countries[i], MAX_LENGTH, stdin);
        strtok(countries[i], "\n"); // 去除换行符
        sorted_countries[i] = countries[i]; // 指针数组指向国家名数组中的字符串
    }

    // 使用 qsort 函数对指针数组进行排序
    qsort(sorted_countries, n, sizeof(const char *), compare);

    // 输出排序后的国家名
    for (int i = 0; i < n; ++i) {
        printf("%s\n", sorted_countries[i]);
    }

    return 0;
}