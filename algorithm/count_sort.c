#include <stdio.h>
#include <stdlib.h>

int countSort(int A[],int B[],int max,int Alength)
{
	int C[max+1];//计数数组
	/*初始化C数组*/
	int i;
	for(i = 0;i <= max;i++)
		C[i] = 0;
	/*统计完每个数字有多少次*/
	for(i = 0;i < Alength;i++)
		C[A[i]] = C[A[i]] + 1;
	/*统计不大于A[i]元素的个数*/
	for(i = 1;i <= max;i++)
		C[i] = C[i] + C[i - 1];
	/*对B数组进行赋值，结果即为有序数组*/
	for(i = Alength - 1;i >= 0;i--)
	{
		B[C[A[i]] - 1] = A[i];
		C[A[i]]--;
	}
}
int main()
{
	printf("请输入元素个数:");
	int numberElement;
	scanf("%d",&numberElement);
	int A[numberElement];
	int B[numberElement];
	printf("请输入元素内容:");
	int i;
	int max = 0;
	for(i = 0;i < numberElement;i++)
	{
		scanf("%d",&A[i]);
		if(A[i] > max)
			max = A[i];
	}
	/*调用排序算法*/
	countSort(A,B,max,numberElement);
	printf("排序后结果:");
	for(i = 0;i < numberElement;i++)
		printf("%3d",B[i]);
	printf("\n");
	system("pause");
	return 0;
}
