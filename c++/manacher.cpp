#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;
const int N = 10000;
int n,p[N];
char s[N],str[N];
#define min(x,y) ((x) < (y) ? (x) : (y))
/*初始化操作*/
void initize() {
	int i,j,k;
	str[0] = '$';
	str[1] = '#';
	for(i = 0;i < n;i++) {
		str[2 * i + 2] = s[i];
		str[2 * i + 3] = '#';
	}
	n = n * 2 + 2;
	s[n] = '\0';
}
/*Manacher方法求最长回文子串，时间复杂度为O（n）*/
void manacher() {
	int i,max = 0,id;
	for(i = n;str[i] != 0;i++)
		str[i] = 0;
	for(i = 1;i < n;i++) {
		if(max > i)
			p[i] = min(p[2 * id - i],p[id] + id - i);
		else
			p[i] = 1;
		for(;str[i + p[i]] == str[i - p[i]];p[i]++);
		if(p[i] + i > max) {
			max = p[i] + i;
			id = i;
			printf("最大中间位置为：%d.\n",id);
		}
	}
}
/*打印回文子串长度的函数*/
void print() {
	int answer = 0;
	for(int i = 0;i < n;i++)
		if(p[i] > answer)
			answer = p[i];
	printf("最长回文子串的长度为：%d\n",answer - 1);
}
/*主函数*/
int main() {
	scanf("%s",&s);
	n = strlen(s);
	initize();
	manacher();
	print();
	return 0;
}
