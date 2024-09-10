#include<stdio.h>
#include<stdlib.h>

void josephus(int n,int m);

int main()
{
	int m,n;/*人数n和间隔数m*/
	
	while(scanf("%d %d",&n,&m)!=EOF)
	{
	
	josephus(n,m);}
	return 0;
}

void josephus(int n,int m)
{
	int *people=(int *)malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
	{
		people[i]=1+i;
	}
    int count = 0;
    int index = 0;
    while (count < n)
	{
        int step = 0;
        while (step < m) 
		{
            index = (index + 1) % n;
            if (people[index] == 0)
			{
                continue;
            }
            step++;
        }
        if(index==0)
        {
        	index=n;
		}
		if(count!=0)
		{
			printf(" ");
		}
        printf("%d",index);
        if(index==n)
        {
        	index=0;
		}
        people[index]=0;
        count++;
    }
    printf("\n");
    free(people);
}