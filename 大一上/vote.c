#include <stdio.h>

#define MAX_CANDIDATES 1000

int main() {
    int votes[MAX_CANDIDATES + 1] = {0}; // 初始化得票数数组，+1是因为候选人编号从1开始
    int candidate;

    // 读取候选人编号，直到输入-1
    while (scanf("%d", &candidate) && candidate != -1) {
        if (candidate >= 1 && candidate <= MAX_CANDIDATES) {
            votes[candidate]++; // 为对应编号的候选人增加一票
        }
    }

    // 按编号升序输出得票数大于0的候选人编号和得票数
    for (int i = 1; i <= MAX_CANDIDATES; i++) {
        if (votes[i] > 0) {
            printf("%d %d\n", i, votes[i]);
        }
    }

    return 0;
}