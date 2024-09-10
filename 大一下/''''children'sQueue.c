#include<stdio.h>
#include<string.h>
int f[1005][105];
void init()
{
    memset(f,0,sizeof(f));
    f[0][1]=1;
    f[1][1]=1;
    f[2][1]=2;
    f[3][1]=4;
 
    for(int i=4;i<=1000;i++)
    {
        int add=0;
        for(int j=1;j<=100;j++)
        {
            f[i][j]=f[i-1][j]+f[i-2][j]+f[i-4][j]+add;
            add=f[i][j]/10000;
            f[i][j]%=10000;
            if(add==0&&f[i][j]==0)break;
        }
    }
}
int main()
{
    int n;
    init();
    while(scanf("%d",&n)!=EOF)
    {
        int k=100;
        while(!f[n][k])k--;
        printf("%d",f[n][k--]);
        for(;k>0;k--)
        {
            printf("%04d",f[n][k]);
        }
        printf("\n");
    }
    return 0;
}
/*设f[n]表示，n个人的情况。情况一、在f[n-1]的情况后面加一个男孩；情况二、在f[n-2]的情况后面加两个女孩；情况三、在f[n-3]最后是男孩（等价于在f[n-4]个个数）的后面加三个女孩；
所以：f[n]=f[n-1]+f[n-2]+f[n-4];由于数据比较大，所以采用大数加法就可以了。*/
