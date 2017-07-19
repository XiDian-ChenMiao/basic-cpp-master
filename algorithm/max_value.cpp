#include <stdio.h>
#include <stdlib.h>
int getMax(int value[],int length,int maxValue)
{
	int i,j,temp = 0,max = 0;
	for(i = 0;i < length;i++)
	{
		for(j = i;j < length;j++)
		{
			temp = temp + value[j];
			if(temp > maxValue)
				temp = temp - value[j];
		}
		if(temp > max)
			max = temp;
		temp = 0;
	}
	return max;
}
void exchange(int *e1,int *e2)
{
    int e;
    e = *e1;
    *e1 = *e2;
    *e2 = e;
}
void sort(int a[],int length)
{
    int i,j;
    for(i = 0;i < length - 1;i++)
    {
        for(j = 0;j < length - i - 1;j++)
        {
             if(a[j] < a[j+1])
                 exchange(&a[j],&a[j+1]);
        }
    }
}
int main()
{
	int salary,count,i;
	int value[2000];
	while(scanf("%d",&salary) != EOF)
	{
		scanf("%d",&count);
		for(i = 0;i < count;i++)
			scanf("%d",&value[i]);
		sort(value,count);
		printf("%d\n",getMax(value,count,salary));
	}
	return 0;
}
