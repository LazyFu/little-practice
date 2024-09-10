#include <stdio.h>
//backtrack version?»ØËÝ·¨£¿
int count = 0;

void backtrack(int matrix[3][3], int rowSum[3], int colSum[3], int row, int col) {
    if (row == 3) {
        count++;
        return;
    }

    if (col == 3) {
        if (rowSum[row] == 5) {
            backtrack(matrix, rowSum, colSum, row + 1, 0);
        }
        return;
    }

    for (int i = 0; i <= 5; i++) {
        if (rowSum[row] + i <= 5 && colSum[col] + i <= 5) {
            matrix[row][col] = i;
            rowSum[row] += i;
            colSum[col] += i;
            backtrack(matrix, rowSum, colSum, row, col + 1);
            rowSum[row] -= i;
            colSum[col] -= i;
        }
    }
}

int main() {
    int matrix[3][3] = {0};
    int rowSum[3] = {0};
    int colSum[3] = {0};
    
    backtrack(matrix, rowSum, colSum, 0, 0);
    printf("%d\n", count);
    
    return 0;
}