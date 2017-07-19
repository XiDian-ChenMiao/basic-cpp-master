#include <stdio.h>
#include <stdlib.h>

void change(int *value1,int *value2)
{
	int temp;
	temp = *value1;
	*value1 = *value2;
	*value2 = temp;
}
void (*Change)(int *,int *);
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	printf("交换之前:a = %d,b = %d.\n");
	Change = change;
	Change(&a,&b);
	printf("交换之后:a = %d,b = %d.\n");
	return 0;
}
