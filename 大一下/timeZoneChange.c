#include<stdio.h>
#include<string.h>

//noon 12:00 p.m.
//midnight 12:00 a.m.
void adjustTime(int *hour,int *minute,char *sourceTZ,char*targetTZ);

int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	for(int i=0;i<n;i++)
	{
		char time[10],period[5],sourceTZ[5],targetTZ[5];
		char zone[21];
		int hour=0,minute=0,sign=1;/*sign标记pm或am*/
		fgets(zone,sizeof(zone),stdin);
		if(strstr(zone,"noon")!=NULL)
		{
			hour=12;
			minute=0;
			strcpy(period,"p.m.");
			sign=-1;
			sscanf(zone,"noon %2s %2s",sourceTZ,targetTZ);
		}
		else if(strstr(zone,"midnight")!=NULL)
		{
			hour=0;
			minute=0;
			strcpy(period,"a.m.");
			sign=1;	
			sscanf(zone,"midnight %2s %2s",sourceTZ,targetTZ);
		}
		else
		{
			sscanf(zone,"%d:%d %s %s %s",&hour,&minute,period,sourceTZ,targetTZ);			
			if(strcmp(period,"a.m.")==0)
			{
				sign=1;
				if(hour==12)
				{
					hour=0;
				}
			}
		}
		
		//调整时间
		adjustTime(&hour,&minute,sourceTZ,targetTZ);
		
		//再调整一下
		if(minute>=60)
		{
			minute-=60;
			hour+=1;
		}
		else if(minute<=-60)
		{
			minute+=60;
			hour-=1;
		}
		if(hour>=24)
		{
			hour-=24;
			sign=-sign;
			if(sign==1)
				{
					strcpy(period,"a.m.");
				}
			else
				{
					strcpy(period,"p.m.");
				}
		}
		else if(hour<=0)
		{
			hour+=24;
			sign=-sign;
			if(sign==1)
				{
					strcpy(period,"a.m.");
				}
				else
				{
					strcpy(period,"p.m.");
				}
		}
		//准备输出！！！
		if(hour==0&&minute==0&&strcmp(period,"a.m.")==0)
		{
			printf("midnight\n");
		}
		else if(hour==12&&minute==0&&strcmp(period,"p.m.")==0)
		{
			printf("noon\n");
		}
		else
		{
			if(hour>=12)
			{
				hour-=12;
				sign=-sign;
				if(sign==1)
				{
					strcpy(period,"a.m.");
				}
				else
				{
					strcpy(period,"p.m.");
				}
				printf("%d:%d %s\n",hour,minute,period);
			}
			else if(hour>0&&hour<12)
			{
				if(sign==1)
				{
					strcpy(period,"a.m.");
				}
				else
				{
					strcpy(period,"p.m.");
				}
				printf("%d:%d %s\n",hour,minute,period);
			}
			else
			{
				hour=12;
				printf("%d:%d %s\n",hour,minute,"a.m.");
			}
		}       
		
	}
	return 0;
}

//函数根据时区调整时间
void adjustTime(int *hour,int *minute,char *sourceTZ,char*targetTZ)
{
	//初始时区转化为零时区
	if(strcmp(sourceTZ,"UTC")==0||strcmp(sourceTZ,"GMT")==0||strcmp(sourceTZ,"WET")==0)
	{
		*hour-=0;
	}
	else if(strcmp(sourceTZ,"BST")==0||strcmp(sourceTZ,"IST")==0||strcmp(sourceTZ,"WEST")==0||strcmp(sourceTZ,"CET")==0)
	{
		*hour-=1;
	}
	else if(strcmp(sourceTZ,"CEST")==0||strcmp(sourceTZ,"EET")==0)
	{
		*hour-=2;
	}
	else if(strcmp(sourceTZ,"NDT")==0)
	{
		*hour-=2;
		*minute-=30;
	}
	else if(strcmp(sourceTZ,"EEST")==0||strcmp(sourceTZ,"MSK")==0)
	{
		*hour-=3;
	}
	else if(strcmp(sourceTZ,"MSD")==0)
	{
		*hour-=4;
	}
	else if(strcmp(sourceTZ,"ADT")==0)
	{
		*hour+=3;
	}
	else if(strcmp(sourceTZ,"NST")==0)
	{
		*hour+=3;
		*minute+=30;
	}
	else if(strcmp(sourceTZ,"AST")==0||strcmp(sourceTZ,"EDT")==0)
	{
		*hour+=4;
	}
	else if(strcmp(sourceTZ,"CDT")==0||strcmp(sourceTZ,"EST")==0)
	{
		*hour+=5;
	}
	else if(strcmp(sourceTZ,"CST")==0||strcmp(sourceTZ,"MDT")==0)
	{
		*hour+=6;
	}
	else if(strcmp(sourceTZ,"MST")==0||strcmp(sourceTZ,"PDT")==0)
	{
		*hour+=7;
	}
	else if(strcmp(sourceTZ,"AWST")==0)
	{
		*hour-=8;
	}
	else if(strcmp(sourceTZ,"PST")==0||strcmp(sourceTZ,"AKDT")==0)
	{
		*hour+=8;
	}
	else if(strcmp(sourceTZ,"AKST")==0)
	{
		*hour+=9;
	}
	else if(strcmp(sourceTZ,"AEST")==0)
	{
		*hour-=10;
	}
	else if(strcmp(sourceTZ,"HST")==0)
	{
		*hour+=10;
	}
	else if(strcmp(sourceTZ,"ACST")==0)
	{
		*hour-=9;
		*minute-=30;
	}
	else if(strcmp(sourceTZ,"ACDT")==0)
	{
		*hour-=10;
		*minute-=30;
	}
	else if(strcmp(sourceTZ,"AEDT")==0)
	{
		*hour-=11;
	}
	//转换为目标时区
	if(strcmp(targetTZ,"UTC")==0||strcmp(targetTZ,"GMT")==0||strcmp(targetTZ,"WET")==0)
	{
		*hour+=0;
	}
	else if(strcmp(targetTZ,"BST")==0||strcmp(targetTZ,"IST")==0||strcmp(targetTZ,"WEST")==0||strcmp(targetTZ,"CET")==0)
	{
		*hour+=1;
	}
	else if(strcmp(targetTZ,"CEST")==0||strcmp(targetTZ,"EET")==0)
	{
		*hour+=2;
	}
	else if(strcmp(targetTZ,"NDT")==0)
	{
		*hour+=2;
		*minute+=30;
	}
	else if(strcmp(targetTZ,"EEST")==0||strcmp(targetTZ,"MSK")==0)
	{
		*hour+=3;
	}
	else if(strcmp(targetTZ,"MSD")==0)
	{
		*hour+=4;
	}
	else if(strcmp(targetTZ,"ADT")==0)
	{
		*hour-=3;
	}
	else if(strcmp(targetTZ,"NST")==0)
	{
		*hour-=3;
		*minute-=30;
	}
	else if(strcmp(targetTZ,"AST")==0||strcmp(targetTZ,"EDT")==0)
	{
		*hour-=4;
	}
	else if(strcmp(targetTZ,"CDT")==0||strcmp(targetTZ,"EST")==0)
	{
		*hour-=5;
	}
	else if(strcmp(targetTZ,"CST")==0||strcmp(targetTZ,"MDT")==0)
	{
		*hour-=6;
	}
	else if(strcmp(targetTZ,"MST")==0||strcmp(targetTZ,"PDT")==0)
	{
		*hour-=7;
	}
	else if(strcmp(targetTZ,"AWST")==0)
	{
		*hour+=8;
	}
	else if(strcmp(targetTZ,"PST")==0||strcmp(targetTZ,"AKDT")==0)
	{
		*hour-=8;
	}
	else if(strcmp(targetTZ,"AKST")==0)
	{
		*hour-=9;
	}
	else if(strcmp(targetTZ,"AEST")==0)
	{
		*hour+=10;
	}
	else if(strcmp(targetTZ,"HST")==0)
	{
		*hour-=10;
	}
	else if(strcmp(targetTZ,"ACST")==0)
	{
		*hour+=9;
		*minute+=30;
	}
	else if(strcmp(targetTZ,"ACDT")==0)
	{
		*hour+=10;
		*minute+=30;
	}
	else if(strcmp(targetTZ,"AEDT")==0)
	{
		*hour+=11;
	}
}

