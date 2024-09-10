#include <stdio.h>
//online judge P1134 chatGPT version.
// 定义数组大小，用来存储大数
#define MAX_DIGITS 10000

// 大数乘法函数
void multiply(int result[], int num, int *num_digits) 
{
    int carry = 0;
    for (int i = 0; i < *num_digits; i++) 
	{
        int prod = result[i] * num + carry;
        result[i] = prod % 10;
        carry = prod / 10;
    }
    while (carry > 0) 
	{
        result[*num_digits] = carry % 10;
        carry /= 10;
        (*num_digits)++;
    }
}

// 计算阶乘函数
void factorial(int n) 
{
    int result[MAX_DIGITS] = {0};
    int num_digits = 1;
    result[0] = 1;

    for (int i = 2; i <= n; ++i) 
	{
        multiply(result, i, &num_digits);
    }
    for (int i = num_digits - 1; i >= 0; --i) 
	{
        printf("%d", result[i]);
    }
    printf("\n");
}

int main() 
{
    int N;
    while(scanf("%d", &N)!=EOF)
    {
    factorial(N);
	}
    return 0;
}