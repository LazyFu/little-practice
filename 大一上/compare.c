#include <stdio.h>
void print(int degree) {
    if (degree==1) {
        printf("X\n");
        return;
    }
    print(degree-1);
    for(int i=0;i<(1<<(degree-1));i++)
	{
        for(int j=0;j<(1<<(degree-1));j++)
		{
            printf(" ");
        }
        printf("\n");
    }
    print(degree-1);
}
int main() {
    int degree;
    while(scanf("%d", &degree)!=EOF)
{
    printf("-\n");
    print(degree);
    printf("-\n");
}
    return 0;
}