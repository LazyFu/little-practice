#include <stdio.h>

void leftRotate(int arr[], int n, int k) {
    int temp[k];
  
    // 将前k个元素保存到临时数组中
    for (int i = 0; i < k; i++) {
        temp[i] = arr[i];
    }
  
    // 将剩余的元素左移k个位置
    for (int i = k; i < n; i++) {
        arr[i - k] = arr[i];
    }
  
    // 将临时数组中的元素放回数组末尾
    for (int i = 0; i < k; i++) {
        arr[n - k + i] = temp[i];
    }
}

int main() {
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);
  
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
  
    leftRotate(arr, n, k);
  
    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }
  
    return 0;
}