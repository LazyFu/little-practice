#include <stdio.h>
#include <string.h>

int main() {
    char line[1001]; // �����������󳤶�Ϊ1000
    while (fgets(line, sizeof(line), stdin)) {
        int i, leading_stars = 1;
        int len = strlen(line);
        if (line[len - 1] == '\n') {
            line[len - 1] = '\0'; // �Ƴ����з�
            len--;
        }
        for (i = 0; i < len; i++) {
            if (line[i] != '*' || leading_stars) {
                putchar(line[i]);
                if (line[i] != '*') {
                    leading_stars = 0; // ������һ����*�ַ���ֹͣ����*�ַ�
                }
            }
        }
        putchar('\n');
    }
    return 0;
}