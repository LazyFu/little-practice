#include <stdio.h>
#include <math.h>

// 计算 a^b mod 10000
int mod_pow(int a, int b, int mod) {
    int result = 1;
    a = a % mod;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % mod;
        }
        b = b / 2;
        a = (a * a) % mod;
    }
    return result;
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        int sum = 0;
        for (int j = 1; j <= a; j++) {
            sum = (sum + mod_pow(j, b, 10000)) % 10000;
        }
        printf("%d\n", sum);
    }
    return 0;
}