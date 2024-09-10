#include <stdio.h>

int main() {
    int L, M;
    while(scanf("%d %d", &L, &M)!=EOF)
    {
    int road[L + 2];
    for (int i = 0; i <= L; i++) {
        road[i] = 0;
    }

    for (int i = 0; i < M; i++) {
        int start, end;
        scanf("%d %d", &start, &end);
        for (int j = start; j <= end; j++) {
            road[j] = 1;
        }
    }

    int count = 0;
    for (int i = 0; i <= L; i++) {
        if (road[i] == 0) {
            count++;
        }
    }

    printf("%d\n", count);
}
    return 0;
}