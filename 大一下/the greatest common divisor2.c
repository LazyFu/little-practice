#include<stdio.h>
int culculate(int x,int y)
{
	if(y==0)
		return x;
	else
		return culculate(y,x%y);/*取余数*/
}
int main()
{
	int i,n,a,b,c,p,q;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		p=culculate(a,b);
		q=culculate(p,c);
		printf("%d\n",q);
	}
	return 0;
}
