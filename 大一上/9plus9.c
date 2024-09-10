#include<stdio.h>
int main()
{
	int i,j,k;
	printf("---------------------------------------\n");
	for(i=1;i<10;i++)
	{
		printf("%4d",i);
	}
	printf("\n---------------------------------------\n");
	for(j=1;j<10;j++)
		{
		printf("%d",j);
		for(k=1;k<10;k++)
			{
			printf("%4d",j*k);
			}
		printf("\n");
		}
	printf("---------------------------------------\n");
	return 0;
}