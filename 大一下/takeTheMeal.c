#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	int n;
	scanf("%d",&n);
		getchar();
		int i=1,size=0;
		int order,id;
		int queue[1002]={0};
		
		for(int j=0;j<n;j++)
		{
			char buffer[10];
			fgets(buffer,sizeof(buffer),stdin);
			sscanf(buffer,"%d",&order);
            switch (order) 
			{
                case 1: // ���� id ������ĩβ
                    i++;
                    break;
                case 2: // ���� id ������ǰ��
                	sscanf(buffer,"%*d %d",&id);
                    for (int k=size;k>=i;k--) 
					{
                        queue[k+1] = queue[k];
                    }
                    queue[i] = id;
                    size++;
                    break;
                case 3: // �Ӷ���ǰ��ɾ��һ��Ԫ��
            		for(int k=i;k<size;k++)
            		{
            			queue[k]=queue[k+1];
					}
					queue[size]=0;
					size--;
                    break;
            }
		}
		//output
		for(int j=1;j<=size;j++)
		{
			printf("%d ",queue[j]);
		}
		printf("\n");
	return 0;
}