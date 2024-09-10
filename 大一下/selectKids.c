#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*wrong answer*/
void kids(char **arr,int w,int s,int n)
{
	int *people=(int *)malloc(n*sizeof(int));
	for(int i=0;i<n;i++)
	{
		people[i]=1;
	}
    int count = 0;
    int index = w-1;
    while (count < n)
	{
        int step = 0;
        while (step < s) 
		{
            
            if (people[index]==1)
			{
               	step++;
               	if(step==s) break;
            }
            index = (index + 1) % n;
        }
        printf("%s\n",arr[index]);

        people[index]=0;
        count++;
        while(people[index]==0)
        {
        	index=(index+1)%n;
		}
    }
    free(people);
}

int main()
{
	int n,w,s;
	while(scanf("%d",&n)!=EOF)
	{
		char **arr=(char**)malloc(n*sizeof(char *));
		if(arr==NULL)
		{
			printf("Memory allocation1 failed\n");
			return 1;
		}
		for(int i=0;i<n;i++)
		{
			arr[i]=(char *)malloc(15*sizeof(char));
			if(arr[i]==NULL)
			{
				printf("Memory allocation2 failed\n");
			}
			scanf("%s",arr[i]);
		}
		scanf("%d,%d",&w,&s);
		kids(arr,w,s,n);
		for(int j=0;j<n;j++)
		{
			free(arr[j]);
		}
		free(arr);
	}
	return 0;
}