#include <stdio.h>
#include <string.h>

// 函数声明
void eliminate_children(char children[][16], int N, int W, int S);

int main() {
    int N, W, S;
    char children[64][16];

    // 输入小孩人数
    scanf("%d", &N);
    
    // 输入小孩名字
    for (int i = 0; i < N; i++) {
        scanf("%s", children[i]);
    }

    // 输入起始位置和报数
    scanf("%d,%d", &W, &S);

    eliminate_children(children, N, W, S);

    return 0;
}

void eliminate_children(char children[][16], int N, int W, int S) {
    int i, index = W - 1;
    int remaining = N;
    int count = 0;

    while (remaining > 0) {
        // 跳过已经出列的小孩
        if (children[index][0] != '\0') {
            count++;
        }

        // 找到第S个小孩并出列
        if (count == S) {
            printf("%s\n", children[index]);
            children[index][0] = '\0'; // 标记为出列
            remaining--;
            count = 0; // 重置计数器
        }

        // 移动到下一个小孩
        index = (index + 1) % N;
    }
}
