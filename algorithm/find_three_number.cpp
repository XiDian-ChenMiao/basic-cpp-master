#include <stdio.h>
#include <stdlib.h>
/*快速排序算法，其中l表示最左边的索引位置，通常为0，r表示最右边的索引位置，通常为数组长度减1*/
void Quicksort(int s[], int l, int r)
{
    int i, j, x;
    if (l < r)
    {
        i = l;
        j = r;
        x = s[i];
        while (i < j)
        {
            while(i < j && s[j] > x) j--; /* 从右向左找第一个小于x的数 */
            if(i < j) s[i++] = s[j];
            while(i < j && s[i] < x) i++; /* 从左向右找第一个大于x的数 */
            if(i < j) s[j--] = s[i];
        }
        s[i] = x;
        Quicksort(s, l, i-1); /* 递归调用 */
        Quicksort(s, i+1, r);
    }
}
/*在已经排好序的数组中查找出三个数之和大于某一定值的可能情况*/
int sumOfCase(int data[],int length,int sum)
{
	int head,rear;
	int i;
	int temp,sumCase = 0;
	for(i = 0;i < length - 1;i++)
	{
		head = i + 1;
		rear = length - 1;
		while(head < rear)
		{
			int curValue = data[head] + data[rear];
			if(curValue >= sum - data[i])
			{
				temp = rear - head;
				sumCase += temp;
				rear--;
				continue;
			}
			else
				head++;
		}
	}
	return sumCase;
}
int main()
{
	int data[5] = {3,5,4,6,7};
	Quicksort(data,0,4);
    printf("%d",sumOfCase(data,5,15));
	system("pause");
	return 0;
}
