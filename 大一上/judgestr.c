#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 10001

int is_palindrome(const char *str, int len) {
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            return 0; // 不是回文
        }
    }
    return 1; // 是回文
}

int main() {
    char str[MAX_LENGTH];

    // 使用循环读取多组输入直到EOF
    while (fgets(str, MAX_LENGTH, stdin)) {
        // 去除换行符
        size_t len = strlen(str);
        if (len > 0 && (str[len - 1] == '\n' || str[len - 1] == '\r')) {
            str[--len] = '\0';
        }

        // 检查是否是回文
        if (is_palindrome(str, len)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}