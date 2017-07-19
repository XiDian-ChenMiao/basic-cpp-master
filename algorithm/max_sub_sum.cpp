#include <stdio.h>
#include <stdlib.h>
int max(int a,int b)
{
	return a > b ? a : b;
}
/*方法1,时间复杂度为O(n)*/
int findMaxSubSum_1(int A[],int length)
{
	int maxendinghere = 0,maxsofar = 0;
	int i;
	for(i = 0;i < length;i++)
		maxendinghere = max(maxendinghere + A[i],0);
	return max(maxsofar,maxendinghere);
}
/*方法2:动态规划的方法，时间复杂度为O(n).*/
int findMaxSubSum_2(int A[],int length)
{
	int B[length],sum,i;
	sum = B[0] = A[0];
	for(i = 1;i < length;i++)
	{
		if(B[i-1] > 0)
			B[i] = B[i-1] + A[i];
		else
			B[i] = A[i];
		if(B[i] > sum)
			sum = B[i];
	}
	return sum;
}
/*方法3：一般算法，时间复杂度为O(n*n).*/
int findMaxSubSum_3(int A[],int length,int *bestStart,int *bestEnd)
{
	int i,j,sum = 0,thisSum;
	for(i = 0;i < length;i++)
	{
		thisSum = 0;
		for(j = i;j < length;j++)
		{
			thisSum += A[j];
			if(thisSum > sum)
			{
				sum = thisSum;
				*bestStart = i;
				*bestEnd = j;
			}

		}
	}
	return sum;
}
int main()
{
	printf("请输入数组长度:");
	int length;
	scanf("%d",&length);
	printf("请输入数组元素:");
	int i,array[length],start,end;
	for(i = 0;i < length;i++)
		scanf("%d",&array[i]);
	printf("From %d to %d,result:%d.\n",start + 1,end + 1,findMaxSubSum_3(array,length,&start,&end));
	system("pause");
	return 0;
}
