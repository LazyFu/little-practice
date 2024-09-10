#include <stdio.h>

// 递归计算青蛙过河的方法数
int frog_jump(int n) 
{
    if (n == 0) 
	{
        return 1; // 如果没有荷叶，唯一的方法是不跳
    } else if (n == 1) 
	{
        return 1; // 如果只有一片荷叶，直接跳过
    } else 
	{
        return frog_jump(n - 1) + frog_jump(n - 2); // 递归计算跳过n-1和n-2片荷叶的方法数之和
    }
}
/*青蛙可以选择的最后一步是跳到第 n 片荷叶上，或者是跳过第 n 片荷叶直接到达对岸。
如果青蛙选择跳到第 n 片荷叶上，那么之前的 n-1 片荷叶上的跳法数目就和跳过 n 片荷叶的跳法数目是一样的；
如果青蛙选择直接跳过第 n 片荷叶，那么之前的 n-2 片荷叶上的跳法数目就和跳过 n 片荷叶的跳法数目是一样的。*/
int main() 
{
    int n;
    while (scanf("%d", &n) != EOF) 
	{
        printf("%d\n", frog_jump(n));
    }
    return 0;
}