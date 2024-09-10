#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �����������������ͳ���
#define MAX_COUNTRIES 100
#define MAX_LENGTH 100

// �ȽϺ��������� qsort ����
int compare(const void *a, const void *b) {
    const char *const *str1 = (const char *const *)a;
    const char *const *str2 = (const char *const *)b;
    return strcmp(*str1, *str2);
}

int main() {
    int n;
    char countries[MAX_COUNTRIES][MAX_LENGTH]; // �洢������
    const char *sorted_countries[MAX_COUNTRIES]; // ָ��������������

    // ����μӹ����� n
    scanf("%d", &n);
    getchar(); // ���ջ��з�

    // �����������������洢��������
    for (int i = 0; i < n; ++i) {
        fgets(countries[i], MAX_LENGTH, stdin);
        strtok(countries[i], "\n"); // ȥ�����з�
        sorted_countries[i] = countries[i]; // ָ������ָ������������е��ַ���
    }

    // ʹ�� qsort ������ָ�������������
    qsort(sorted_countries, n, sizeof(const char *), compare);

    // ��������Ĺ�����
    for (int i = 0; i < n; ++i) {
        printf("%s\n", sorted_countries[i]);
    }

    return 0;
}