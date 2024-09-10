#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 10001

int is_palindrome(const char *str, int len) {
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            return 0; // ���ǻ���
        }
    }
    return 1; // �ǻ���
}

int main() {
    char str[MAX_LENGTH];

    // ʹ��ѭ����ȡ��������ֱ��EOF
    while (fgets(str, MAX_LENGTH, stdin)) {
        // ȥ�����з�
        size_t len = strlen(str);
        if (len > 0 && (str[len - 1] == '\n' || str[len - 1] == '\r')) {
            str[--len] = '\0';
        }

        // ����Ƿ��ǻ���
        if (is_palindrome(str, len)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}