#include <stdio.h>
#include <string.h>

// 函数：将字符数组转换为整数数组
void charToArray(char *n, int *num) 
{
    int len = strlen(n);
    for (int i = 0; i < len; i++) 
	{
        num[i] = n[i] - '0';
    }
}

// 函数：检查两个数组是否循环相等
int isCyclic(int *num, int *temp, int len) 
{
    for (int i = 0; i < len; i++) 
	{
        int j;
        for (j = 0; j < len; j++) 
		{
            if (num[j] != temp[(i + j) % len]) 
			{
                break;
            }
        }
        if (j == len) 
		{
            return 1;
        }
    }
    return 0;
}

int main() 
{
    char n[60];
    while (scanf("%s", n) != EOF) 
	{
        int num[60], temp[60], len = strlen(n);
        charToArray(n, num);
        int isCyclicNumber = 1;

        for (int i = 1; i <= len; i++) 
		{
            memset(temp, 0, sizeof(temp)); // 初始化临时数组
            for (int j = len - 1; j >= 0; j--) 
			{
                temp[j] += num[j] * i;
                if (temp[j] >= 10 && j != 0) 
				{
                    temp[j - 1] += temp[j] / 10;
                    temp[j] %= 10;
                } else if (temp[0] >= 10) 
				{
                    isCyclicNumber = 0;
                    break;
                }
            }

            if (!isCyclic(num, temp, len)) 
			{
                isCyclicNumber = 0;
                break;
            }
        }

        if (isCyclicNumber) 
		{
            printf("%s is cyclic\n", n);
        } else 
		{
            printf("%s is not cyclic\n", n);
        }
    }
    return 0;
}