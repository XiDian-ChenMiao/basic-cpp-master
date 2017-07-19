#include <stdio.h>
int BinaryCheck(int a[],int start,int end,int check)
{
	int i,j;
	int key;
	int low;
	int high;
	int mid;
	if(check == a[start])
		return start;
	for(i = start + 1;i < end;i++)
	{
		key = a[i];
		j = i - 1;
		while(j >= 0 && key < a[j])
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
		low = 0;
		high = i;
		while(low <= high)
		{
			mid = (low + high) / 2;
			if(a[mid] == check)
				return mid;
			else if(a[mid] > check)
				high = mid - 1;
			else
				low = mid + 1;
		}
	}
	return -1;
}
int main()
{
	int check;//需要二分查找的元素
	printf("数组个数:");
	int length;
	scanf("%d",&length);
	int a[length];
	printf("数组元素:");
	int i;
	for(i = 0;i < length;i++)
		scanf("%d",&a[i]);
	printf("查找元素:");
	scanf("%d",&check);
	int index = BinaryCheck(a,0,length,check);
	printf("位置在:%d.\n",index);
	return 0;
} 
