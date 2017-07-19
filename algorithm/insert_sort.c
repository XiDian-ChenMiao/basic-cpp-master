#include <stdio.h>
#include <stdlib.h>
/*Swap Func*/
void exchange(int *p,int *q)
{
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}
//Insert Sort
void insertSort(int A[],int length){
	int i,j,key;
	for(i = 1;i < length;i++)
	{
		key = A[i];
		j = i - 1;
		while(j >= 0 && A[j] > key)
		{
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = key;
	}
}
void Insertsort3(int a[], int n)
{
   int i, j;
   for (i = 1; i < n; i++)
       for (j = i - 1; j >= 0 && a[j] > a[j + 1]; j--)
           exchange(&a[j], &a[j + 1]);
}
int main(int argc, char const *argv[])
{
	int array[5] = {5,6,4,7,2},i;
	insertSort(array,5);
	//Insertsort3(array,5);
	for(i = 0;i < 5;i++)
		printf("%d\t",array[i]);
	system("pause");
	return 0;
}
