#include<stdio.h>
#include<string.h>

int main()
{
	char s[1000]; // 假设输入不会超过1000字符
    int index = 0;
    char ch;

    // 读取输入直到遇到字符 'E'
    while ((ch = getchar()) != 'E') {
        s[index++] = ch;
    }
    s[index] = '\0'; // 确保字符串结束
		int hua=0,antihua=0;//W华华,L对手
		//11分制
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
		// 输出最后一局未结束的比分
        if (hua != 0 || antihua != 0) 
		{
            printf("%d:%d\n", hua, antihua);
        }
		printf("\n");
		//21分制
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
		// 输出最后一局未结束的比分
        if (hua != 0 || antihua != 0) 
		{
            printf("%d:%d\n", hua, antihua);
        }
	return 0;
}