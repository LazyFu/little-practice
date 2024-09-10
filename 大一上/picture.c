#include <stdio.h>

void printFractal(int degree, int level) {
    if (degree == 0) {
        for (int i = 0; i < level; i++) {
            printf("  ");
        }
        printf("X\n");
        return;
    }

    printFractal(degree - 1, level);

    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    printFractal(degree - 1, level + 1);

    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    printFractal(degree - 1, level - 1);

    printFractal(degree - 1, level);

    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    printFractal(degree - 1, level - 1);
}

int main() {
    int degree;

    printf("请输入分形的度数：");
    scanf("%d", &degree);

    printf("分形图：\n");
    printFractal(degree, 0);

    return 0;
}