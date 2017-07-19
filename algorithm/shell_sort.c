#include <stdio.h>
#include <stdlib.h>
#include "shell_sort.h"
int main(int argc, char const *argv[])
{
	int array[10],i;
	printf("Array:");
	array[0] = 0;//哨兵位置
	for(i = 1;i < 10;i++)
		scanf("%d",&array[i]);
	ShellSort(array,10);
	printf("After Shell Sort:");
	for(i = 1;i < 10;i++)
		printf("%d\t", array[i]);
	system("pause");
	return 0;
}
