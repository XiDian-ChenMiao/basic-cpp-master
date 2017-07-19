#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
const int maxsize=1024;
typedef int datatype;
typedef struct
{  datatype data[maxsize];
   int last;
}sequenlist;

void InitList(sequenlist*&);
int Length(sequenlist*);
datatype Get(sequenlist,int);
void Delete(sequenlist*,int);
void Insert(sequenlist*,datatype,int);
void purge(sequenlist*);
void PrintList(sequenlist*);

int main()
{
	sequenlist *L;
	int i=0;
	datatype x;
	InitList(L);
	scanf("%d",&x);
	while(x!=-1)
	{
		i++;
        Insert(L,x,i);
	    scanf("%d",&x);
	}
	PrintList(L);
	purge(L);
	PrintList(L);
	system("pause");
	return 0;
}
void InitList(sequenlist*&L )
{
       L=(sequenlist*)malloc(sizeof(sequenlist));
       L-> last=0;
}//建立空表

int Length(sequenlist*L )
{
       return  L->last;
}//求表长度

datatype Get(sequenlist*L, int i)
{
      return L->data[i];
}//取第i个元素

void Delete(sequenlist*L,int i)
{
    for(int j=i;j<=L->last-1;j++)
        L->data[j]=L->data[j+1];//结点前移
    L->last--;//表长度减1
}//删除第i个元素

void Insert(sequenlist*L,datatype x,int i)
{
    for(int j=L->last;j>=i;j--)
         L->data[j+1]=L->data[j];//结点后移
    L->data[i]=x;//插入到L->data[i]中
    L->last++;//表长度加1
}//在第i个元素之前插入一个元素

void purge(sequenlist*L)
{
	int i=1,j;  //为了方便起见，第0个元素不用
	datatype x,y;
    while(i<Length(L))  //每次循环使当前第i结点是无重复值的结点
    {
		x=Get(L,i); //取ai赋给x
        j=i+1; //将ai之后的各结点aj与ai比较，若aj 与ai相同，则删除aj
        while(j<=Length(L))
		{
			y=Get(L,j); //取aj赋给y
            if(x==y)  Delete(L,j); //相同，删除aj
            else  j++; //不同，准备取下一个aj
		}
        i++;
	}
}//删除相同的元素

void PrintList(sequenlist*L)
{
	int i;
	for(i=1;i<=L->last;i++)
		printf("%5d",L->data[i]);
	printf("\n");
}//输出顺序表
