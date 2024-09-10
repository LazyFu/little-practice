#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int main() {
    int N;
    scanf("%d", &N);

    int nums[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &nums[i]);
    }

    qsort(nums, N, sizeof(int), compare); // 对数组进行排序

    int count = 0;
    int left = 0, right = N - 1;
    while (left < right) {
        if (nums[left] + nums[right] == 0) {
            count++;
            left++;
            right--;
        } else if (nums[left] + nums[right] < 0) {
            left++;
        } else {
            right--;
        }
    }

    printf("%d\n", count);

    return 0;
}