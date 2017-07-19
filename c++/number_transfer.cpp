#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//十进制数转二进制数的函数
char *get2String(long num){
	int i = 0;
	char *buffer,*temp;
	buffer = (char *)malloc(33);
	temp = buffer;
	for(i = 0;i < 32;++i){
		temp[i] = num & (1 << (31 - i));
		temp[i] = temp[i] >> (31 - i);
		temp[i] = (temp[i] == 0) ? '0' : '1';
	}
	buffer[32] = '\0';
	return buffer;
}
//十进制数转十六进制数的函数
char *get16String(long num){
	int i = 0;
	char *buffer = (char *)malloc(11);
	char *temp;
	buffer[0] = '0';
	buffer[1] = 'x';
	buffer[10] = '\0';

	temp = buffer + 2;
	for(i = 0;i < 8;i++){
		temp[i] = (char)(num << 4 * i >> 28);
		temp[i] = temp[i] >= 0 ? temp[i] : temp[i] + 16;
		temp[i] = temp[i] < 10 ? temp[i] + 48 : temp[i] + 55;
	}
	return buffer;
}
int main()
{
	char *p = NULL,*q = NULL;
	int num = 0;

	printf("输入数字：");
	scanf("%d",&num);

	p = get2String(num);
	q = get16String(num);
	printf("%d转化为二进制数为:%s\n转化为十六进制数为:%s\n",num,p,q);
	system("pause");
	return 0;
}
