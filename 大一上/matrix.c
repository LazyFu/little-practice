#include <stdio.h>

void generateSpiral(int n, int a[n][n]) {
    int value = n * n, minRow = 0, maxRow = n - 1, minCol = 0, maxCol = n - 1;
    while (value > 0) {
        for (int i = minCol; i <= maxCol && value > 0; i++) {
            a[minRow][i] = value--;
        }
        minRow++;
        for (int i = minRow; i <= maxRow && value > 0; i++) {
            a[i][maxCol] = value--;
        }
        maxCol--;
        for (int i = maxCol; i >= minCol && value > 0; i--) {
            a[maxRow][i] = value--;
        }
        maxRow--;
        for (int i = maxRow; i >= minRow && value > 0; i--) {
            a[i][minCol] = value--;
        }
        minCol++;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n][n];
    generateSpiral(n, a);

    // Output the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}