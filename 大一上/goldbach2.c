#include<stdio.h>
#include<math.h>

int isPrime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n;
    while(scanf("%d", &n)!=EOF)
	{
    for (int i = 2; i <= n / 2; i++) {
        if (isPrime(i) && isPrime(n - i)) {
            printf("%d+%d\n",i,n-i);
            break;
        }
    }
	}
    return 0;
}