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

int main()/*十进制转换为八进制。先输一个数表示要转换几个，然后开始转换*/
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
