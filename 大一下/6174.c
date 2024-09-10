#include<stdio.h>
#include<stdlib.h>
int compare(const void *a,const void *b)
{
	return (*(int *)a-*(int *)b);
}

int getBlackHoleSteps(int num) 
{
    int steps = 0;
    int digits[4];
    
    while (num != 6174) {
        // 将数字的每一位存入数组
        for (int i = 0; i < 4; i++) {
            digits[i] = num % 10;
            num /= 10;
        }
        
        // 降序排列
        qsort(digits, 4, sizeof(int), compare);
        int max = digits[3] * 1000 + digits[2] * 100 + digits[1] * 10 + digits[0];
        int min = digits[0] * 1000 + digits[1] * 100 + digits[2] * 10 + digits[3];
        
        // 计算差值
        num = max - min;
        steps++;
    }
    
    return steps;
}
int main() 
{
    int num;
    
    while (scanf("%d", &num) != EOF) 
	{
        int steps = getBlackHoleSteps(num);
        printf("%d\n", steps);
    }
    
    return 0;
} 