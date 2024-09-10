#include<stdio.h>
#include<math.h>
int main()
{
	double weight,height,BMI;
	scanf("%lf %lf",&weight,&height);
		BMI=weight/pow(height,2.0);
		printf("%.1lf\n",BMI);
		if(BMI>25)
		{
			printf("PANG\n");
		}
		else
		{
			printf("Hai Xing\n");
		}
	return 0;
}