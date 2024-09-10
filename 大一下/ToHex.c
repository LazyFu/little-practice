#include<stdio.h>
#include<string.h>

int binaryToDecimal(char *binary)
{
	int len=strlen(binary);
	int decimal=0;
	for(int i=0;i<len;i++)
	{
		if(binary[i]=='1')
			decimal+=1<<(len-i-1);
	}
	return decimal;
}
char* decimalToHex(int decimal)
{
	static char hex[10];
	sprintf(hex,"%X",decimal);
	return hex;
}

int main()
{
	char binary[32];
	char eg[]="0";
	int decimal;
	char *hex;
	while(scanf("%s",binary)&&(strcmp(binary,eg)!=0))
	{
		decimal=binaryToDecimal(binary);
		hex=decimalToHex(decimal);
		printf("%s\n",hex);
	}
	return 0;
}