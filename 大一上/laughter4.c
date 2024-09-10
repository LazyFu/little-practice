#include <stdio.h>

int count(int a[20]) 
{
    int s = 0, i;
    for (i = 0; a[i]!=-1; i++) 
	{
        s++;
    }
    return s;
}

int max1(int a[20]) {
    int max = a[0], i;
    for (i = 0; a[i] != -1; i++) 
	{
        if (max < a[i]) 
		{
            max = a[i];
 		}
    }
    return max;
}

int min1(int a[20]) 
{
    int min = a[0], i;
    for (i = 0; a[i] != -1; i++) 
	{
        if (min > a[i]) 
		{
            min = a[i];
        }
    }
    return min;
}

float avg1(int a[20]) 
{
    int sum = 0, i;
    float avg;
    int count = 0;
    for (i = 0; a[i] != -1; i++) 
	{
        sum += a[i];
        count++;
    }
    avg = (float)sum / count;
    return avg;
}

int main() 
{
    int T, a[10][20], i, j, s, max, min;
    float avg;
    scanf("%d", &T);
    for (i = 0; i < T; i++) 
	{
        for (j = 0; j < 20; j++) 
		{
            scanf("%d", &a[i][j]);
            if (a[i][j] == -1) 
			{
                break;
            }
        }
        s = count(a[i]);
        max = max1(a[i]);
        min = min1(a[i]);
        avg = avg1(a[i]);
        printf("%d\n%d\n%d\n%.1f\n", s, max, min, avg);
    }
    return 0;
}