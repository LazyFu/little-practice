#include<stdio.h>
#include<string.h>

int main()
{
	char s[1000]; // �������벻�ᳬ��1000�ַ�
    int index = 0;
    char ch;

    // ��ȡ����ֱ�������ַ� 'E'
    while ((ch = getchar()) != 'E') {
        s[index++] = ch;
    }
    s[index] = '\0'; // ȷ���ַ�������
		int hua=0,antihua=0;//W����,L����
		//11����
		for(int i=0;s[i]!='\0';i++)
		{
			if(s[i]=='W')
			{
				hua++;
			}
			else if(s[i]=='L')
			{
				antihua++;
			}
			if((hua>=11||antihua>=11)&&(hua-antihua>=2||antihua-hua>=2))
			{
				printf("%d:%d\n",hua,antihua);
				hua=0;
				antihua=0;
			}
			/*else
			{
				if(s[i]=='W')
				{
					hua++;
					if(hua-antihua>=2||antihua-hua>=2)
					{
						printf("%d:%d\n",hua,antihua);
					}
				}
				else if(*(s+i)=='L')
				{
					antihua++;
					if(hua-antihua>=2||antihua-hua>=2)
					{
						printf("%d:%d\n",hua,antihua);
					}
				}
			}*/
		}
		// ������һ��δ�����ıȷ�
        if (hua != 0 || antihua != 0) 
		{
            printf("%d:%d\n", hua, antihua);
        }
		printf("\n");
		//21����
		hua=0;
		antihua=0;
		for(int i=0;s[i]!='\0';i++)
		{
			if(s[i]=='W')
			{
				hua++;
			}
			else if(s[i]=='L')
			{
				antihua++;
			}
			if((hua>=21||antihua>=21)&&hua-antihua>=2||antihua-hua>=2)
			{
				printf("%d:%d\n",hua,antihua);
				hua=0;
				antihua=0;
			}
		}
		// ������һ��δ�����ıȷ�
        if (hua != 0 || antihua != 0) 
		{
            printf("%d:%d\n", hua, antihua);
        }
	return 0;
}