#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*交换函数*/
void exchange(int *p,int *q)
{
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}
/*快排中的分割函数*/
int partition(int A[],int start,int end)
{
	int x = A[end];
	int i = start - 1,j;
	for(j = start;j < end;j++)
	{
		if(A[j] <= x)
		{
			i = i + 1;
			exchange(&A[i],&A[j]);
		}
	}
	exchange(&A[i+1],&A[end]);
	return i + 1;
}
/*改进后的partition*/
int randomPartition(int A[],int start,int end)
{
	/*产生一个0到end之间的随机数*/
	int i = rand() % (end + 1);
	exchange(&A[end],&A[i]);
	return partition(A,start,end);
}
/*快排的递归算法*/
void QuickSort(int A[],int start,int end)
{
	if(start < end)
	{
		int q = randomPartition(A,start,end);
		QuickSort(A,start,q - 1);
		QuickSort(A,q + 1,end);
	}
}
int main()
{
	printf("请输入数组元素个数:");
	int numberElement;
	scanf("%d",&numberElement);
	int array[numberElement];
	printf("请输入数组元素:");
	int i;
	/*初始化数组元素*/
	for(i = 0;i < numberElement;i++)
		scanf("%d",&array[i]);
	QuickSort(array,0,numberElement - 1);
	printf("快排之后结果:");
	for(i = 0;i < numberElement;i++)
		printf("%5d",array[i]);
	printf("\n");
	system("pause");
	return 0;
}
