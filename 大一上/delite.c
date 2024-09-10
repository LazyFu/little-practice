#include <stdio.h>
#include <string.h>

int main() {
    char line[1001]; // 假设输入的最大长度为1000
    while (fgets(line, sizeof(line), stdin)) {
        int i, leading_stars = 1;
        int len = strlen(line);
        if (line[len - 1] == '\n') {
            line[len - 1] = '\0'; // 移除换行符
            len--;
        }
        for (i = 0; i < len; i++) {
            if (line[i] != '*' || leading_stars) {
                putchar(line[i]);
                if (line[i] != '*') {
                    leading_stars = 0; // 遇到第一个非*字符后，停止保留*字符
                }
            }
        }
        putchar('\n');
    }
    return 0;
}