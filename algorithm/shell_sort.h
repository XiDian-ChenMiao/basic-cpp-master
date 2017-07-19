#ifndef __SHELLSORT_H__
#define __SHELLSORT_H__
//希尔排序
typedef int ElemType;
//其中数组A[]为待排序的数组，变量length为数组的长度,要求数组的第一个位置为“哨兵”
void ShellSort(ElemType A[],int length){
	int i,j;
	int increment = length;//希尔排序所需要的增量
	do{
		increment = increment / 3 + 1;//增量序列
		for (i = increment + 1; i <= length; ++i)
		{
			if(A[i] < A[i - increment]){
				//需将A[i]插入有序增量子表
				A[0] = A[i];//暂存在A[0]这个位置
				for(j = i - increment;j > 0 && A[0] < A[j];j = j - increment)
					A[j + increment] = A[j];//记录后移，查找插入位置
				A[j + increment] = A[0];
			}
		}
	}while(increment > 1);
}
#endif
