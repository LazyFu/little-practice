#include<stdio.h>

#include<math.h>



int sushu(int n)

{

 int i,m;

 m=sqrt (1.0*n);

 for(i=2;i<=m;i++)

 if(n%i==0)break;

 if(i>m&&n!=1)

 n=1;

 else

 n=0;

 return n;

}

 

int main()/*��֤��°ͺղ���*/

{

 int x,a,b;

 scanf("%d",&x);

 if(x%2!=0||x<=4)

 {

 printf("�����������");

 return 0;

 }

 for(a=2;a<=x/2;a++)

 {

 b=x-a;

 if(sushu(a)&&sushu(b))

 {

 printf("��֤ͨ��");

 return 0;

 }

 } 

 printf("�����������");

 return 0;

}

