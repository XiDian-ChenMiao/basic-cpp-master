/*-------------------------------------------------------------------------
 * Name:   哈夫曼编码源代码。
 * Date:   2011.04.16
 * Author: Jeffrey Hill
 * 在 Win-TC 下测试通过
 * 实现过程：着先通过 HuffmanTree() 函数构造哈夫曼树，然后在主函数 main()中
 *           自底向上开始(也就是从数组序号为零的结点开始)向上层层判断，若在
 *           父结点左侧，则置码为 0,若在右侧,则置码为 1。最后输出生成的编码。
 *------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#define MAXBIT      100
#define MAXVALUE  10000
#define MAXLEAF     30
#define MAXNODE    MAXLEAF*2 -1
#define MAX 20
int SIZE = 0;//全局变量，用来标记有用的CharCase类型信息的大小
typedef struct
{
    int bit[MAXBIT];
    int start;
} HCodeType;        /* 编码结构体 */
typedef struct
{
    int weight;
    int parent;
    int lchild;
    int rchild;
} HNodeType;        /* 结点结构体 */
typedef struct Char
{
	char content;//字符内容
	int number;//字符的统计个数
	int flag;//标志位
}CharCase;
CharCase charcont[MAX];
//*********************************************************************
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
void informationOfChar()
{
    char charinfo;
	int size = 0;//用来统计输入的字符的个数
	int i,j,p;//中间计数变量
	char dealwith[MAX];
	//CharCase charcont[MAX];//定义MAX个CharCase类型的变量
	printf("请输入需要进行Haffman编码的信息:");
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
			charcont[p++] = charcont[i];
		}
	}
	SIZE = p;
}
//**********************************************************************
/* 构造一颗哈夫曼树 */
void HuffmanTree (HNodeType HuffNode[MAXNODE],  int n,int temp[])
{
    /* i、j： 循环变量，m1、m2：构造哈夫曼树不同过程中两个最小权值结点的权值，
        x1、x2：构造哈夫曼树不同过程中两个最小权值结点在数组中的序号。*/
    int i, j, m1, m2, x1, x2;
    /* 初始化存放哈夫曼树数组 HuffNode[] 中的结点 */
    for (i=0; i<2*n-1; i++)
    {
        HuffNode[i].weight = 0;
        HuffNode[i].parent =-1;
        HuffNode[i].lchild =-1;
        HuffNode[i].lchild =-1;
    } /* end for */

    /* 输入 n 个叶子结点的权值 */
    for (i=0; i<n; i++)
    {
        HuffNode[i].weight = temp[i];
    } /* end for */

    /* 循环构造 Huffman 树 */
    for (i=0; i<n-1; i++)
    {
        m1=m2=MAXVALUE;     /* m1、m2中存放两个无父结点且结点权值最小的两个结点 */
        x1=x2=0;
        /* 找出所有结点中权值最小、无父结点的两个结点，并合并之为一颗二叉树 */
        for (j=0; j<n+i; j++)
        {
            if (HuffNode[j].weight < m1 && HuffNode[j].parent==-1)
            {
                m2=m1;
                x2=x1;
                m1=HuffNode[j].weight;
                x1=j;
            }
            else if (HuffNode[j].weight < m2 && HuffNode[j].parent==-1)
            {
                m2=HuffNode[j].weight;
                x2=j;
            }
        } /* end for */
            /* 设置找到的两个子结点 x1、x2 的父结点信息 */
        HuffNode[x1].parent  = n+i;
        HuffNode[x2].parent  = n+i;
        HuffNode[n+i].weight = HuffNode[x1].weight + HuffNode[x2].weight;
        HuffNode[n+i].lchild = x1;
        HuffNode[n+i].rchild = x2;
    } /* end for */
} /* end HuffmanTree */

int main(void)
{
    HNodeType HuffNode[MAXNODE];            /* 定义一个结点结构体数组 */
    HCodeType HuffCode[MAXLEAF],  cd;       /* 定义一个编码结构体数组， 同时定义一个临时变量来存放求解编码时的信息 */
    int i = 0, j, c, p, n;
	informationOfChar();
	int length = SIZE;//求产生出的字符信息的个数
	int info[length];
	while(i < length){
        info[i] = charcont[i].number;
        i++;
	}

    HuffmanTree (HuffNode, length,info);//构造赫夫曼树
    n = length;
    for (i=0; i < n; i++)
    {
        cd.start = n-1;
        c = i;
        p = HuffNode[c].parent;
        while (p != -1)   /* 父结点存在 */
        {
            if (HuffNode[p].lchild == c)
                cd.bit[cd.start] = 0;
            else
                cd.bit[cd.start] = 1;
            cd.start--;        /* 求编码的低一位 */
            c=p;
            p=HuffNode[c].parent;    /* 设置下一循环条件 */
        } /* end while */

        /* 保存求出的每个叶结点的哈夫曼编码和编码的起始位 */
        for (j=cd.start+1; j<n; j++)
        { HuffCode[i].bit[j] = cd.bit[j];}
        HuffCode[i].start = cd.start;
    } /* end for */

    /* 输出已保存好的所有存在编码的哈夫曼编码 */
    for (i=0; i<length; i++)
    {
        printf ("%c Huffman code is: ", charcont[i].content);
        for (j=HuffCode[i].start+1; j < n; j++)
        {
            printf ("%d", HuffCode[i].bit[j]);
        }
        printf ("\n");
    }
    system("pause");
    return 0;
}
