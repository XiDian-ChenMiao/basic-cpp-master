#include <stdio.h>
#include <stdlib.h>

int main(){
	int a[] = {-5,4,10,-6,-8};
	int sum = a[0];
	int result = a[0];
	int i = 1;
	int start = 0,end = 0;
	for(;i < 5;i++){
		if(sum > 0)
		{
			sum += a[i];
		}
		else
		{
			sum = a[i];
			start = i;
			end = i;
		}
		if(sum > result)
		{
			result = sum;
			end = i;
		}

	}
	printf("最大子数组和为：%d，起始坐标为：%d，终止坐标为：%d.",result,start,end);
}
