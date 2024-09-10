#include <stdio.h>
void fun(int n, int *a, int *b) {
    if (n == 1) {
        *a = 2;
        *b = 1;
    }
    else if (n == 2) {
        *a = -3;
        *b = 2;
    }
    else {
        int a1, b1, a2, b2;
        fun(n - 2, &a1, &b1);
        fun(n - 1, &a2, &b2);
        *a= a1 + (-1 * a2);
        *b= b1 + b2;
    }
}
int main()
{
    int n;
    while(scanf("%d", &n)!=EOF)
    {
    int a, b;
    fun(n, &a, &b);
    printf("%d/%d\n",a, b);
	}
    return 0;
}
