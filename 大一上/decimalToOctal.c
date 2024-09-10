#include <stdio.h>

int decimalToOctal(int decimal)
{
    int octal = 0, placeValue = 1;
    while (decimal > 0)
	{
        octal += (decimal % 8) * placeValue;
        decimal /= 8;
        placeValue *= 10;
    }
    return octal;
}

int main()/*ʮ����ת��Ϊ�˽��ơ�����һ������ʾҪת��������Ȼ��ʼת��*/
{
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
    	int decimal;
 	   	scanf("%d", &decimal);
		int octal = decimalToOctal(decimal);
 	       printf("%d\n", octal);
 	}
    return 0;
}
