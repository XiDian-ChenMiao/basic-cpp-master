#include <stdio.h>
#include <stdlib.h>
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
/*找寻一个数组中的第check大元素*/
int findSpecifyElement(int A[],int start,int end,int check)
{
	if(start == end)
		return A[start];
	int q = randomPartition(A,start,end);
	int k = q - start + 1;
	if(check == k)
		return A[q];
	if(check < k)
		return findSpecifyElement(A,start,q - 1,check);
	else
		return findSpecifyElement(A,q + 1,end,check - k);
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
	printf("请输入找寻第几大元素:");
	int check;
	scanf("%d",&check);
	printf("结果为:%d\n",findSpecifyElement(array,0,numberElement - 1,check));
	system("pause");
    return 0;
} 
