#include <stdio.h>
#include <stdlib.h>
#define MAX 20
/*
 * 定义结构体Char并重命名为CharCase，属性有字符内容，出现的次数
*/

typedef struct Char
{
	char content;//字符内容
	int number;//字符的统计个数
	int flag;//标志位
}CharCase;
//判断是否与数组中已经出现的元素重复
bool justify(char content,char *temp)
{
	int i = 0;
	while(*(temp+i) != '0')
	{
		if(content == *(temp+i))
			return true;
		else
			i++;
	}
	return false;
}
void exchange(int *e1,int *e2)
{
    int e;
    e = *e1;
    *e1 = *e2;
    *e2 = e;
}
int main()
{
	char charinfo;
	int max = 0,nextmax = 0;
	int size = 0;//用来统计输入的字符的个数
	int i,j,p;//中间计数变量
	char dealwith[MAX];
	CharCase charcont[MAX];//定义MAX个CharCase类型的变量
	printf("请输入信息:");
	//初始化charcont[MAX]数组
	for(i = 0;i < MAX;i++)
	{
		charcont[i].content = '0';
		charcont[i].number = 0;
		charcont[i].flag = 0;
	}
	//初始化dealwith[MAX]数组
	for (i = 0;i < MAX ;i++ )
		dealwith[i] = '0';
	//获取字符串
	i = 0;
	while((charinfo = getchar())!= '\n')
	{
		//charcont[i].state = true;
		charcont[i].content = charinfo;
		charcont[i].number++;
		size++;
		i++;
	}
	//遍历整个charcont数组来统计各种字符的个数
	i = 0;//计数器归零
	p = 0;//引入计数器p
	for(;i < size;i++)
	{
		if(justify(charcont[i].content,dealwith))
			continue;
		for(j = 0;j < size;j++)
		{
			if(charcont[i].content == charcont[j].content)
			{
				dealwith[p] = charcont[i].content;
				++charcont[i].number;
				charcont[i].flag = 1;
			}
		}
		p++;
	}
	//重新整合满足要求的结构体
	p = 0;
	for(i = 0;i < size;i++)
	{
		if(charcont[i].flag == 1)
		{
			charcont[i].number--;
			charcont[p] = charcont[i];
			p++;
		}
	}
	max = charcont[0].number;
	nextmax = charcont[1].number;
	if(nextmax > max)
	    exchange(&max,&nextmax);
	for(i = 2;i < p;i++)
	{
	    if(charcont[i].number > max){
	        exchange(&max,&nextmax);
	         max = charcont[i].number;
	     }
        if(charcont[i].number > nextmax && charcont[i].number < max)
             nextmax = charcont[i].number;
     }
	printf("%d\n",max+nextmax);
	system("pause");
	return 0;
}
