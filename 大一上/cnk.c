#include <stdio.h>



int comm(int n, int k)

{

    if (n == k || k == 0)

    {

        return 1;

    }

    else

        return comm(n - 1, k) + comm(n - 1, k - 1);

}



int main()

{

    int comm(int n, int k);

    int n, k;

    scanf("%d%d", &n, &k);

    printf("C(n, k) = %d\n", comm(n, k));

    getchar(); getchar();

    return 0;
}