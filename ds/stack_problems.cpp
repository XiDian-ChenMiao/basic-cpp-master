/**栈数据结构
  *InitStack() : 初始化栈的操作
  *IsEmpty()   : 判断是否栈空
  *Push()      : 进栈操作
  *Pop()       : 出栈操作
  *GetTop()    : 获取栈顶元素操作
  */
#include <stdio.h>
#include <stdlib.h>
//定义栈最大元素数量
#define STACK_MAX_SIZE 100
#define IN_TYPE "%d"
#define OUT_TYPE "%3d"

#define NULL 0
//建立形成二叉树的结构体
typedef struct BiTNode
{
        int data;
        struct BiTNode *lchild;
        struct BiTNode *rchild;
}BiLNode,*BiTree;
//构造二叉树
BiTree Create(BiTree T)
{
       int ch;
       cin >> ch;
       if(ch == -1)
           T=NULL;
       else
       {
           if(!(T=(BiTree)malloc(sizeof(BiTNode))))
               cout<<"Error!";
           T->data = ch;
           T->lchild=Create(T->lchild);
           T->rchild=Create(T->rchild);
       }
       return T;
}


//定义栈的数据结构
typedef struct Stack
{
	BiTNode data[STACK_MAX_SIZE];//数据及容量
	int top;//栈顶游标
}Stack;


//初始化栈的操作
Stack *InitStack()
{
    Stack *s;
	s = (Stack *)malloc(sizeof(Stack));
	s->top = -1;
}
//判断是否栈空
int IsEmpty(Stack *s)
{
	//栈顶游标若为-1,说明栈中无元素
	if(s->top == -1)
		return 1;
	return 0;
}
//进栈操作
int Push(Stack *s,ElemType e)
{
	if(s->top == STACK_MAX_SIZE - 1)
	{
		printf("Stack Overflow.\n");
		return 0;
	}
	s->data[++s->top] = e;
	return 1;
}
//出栈操作
int Pop(Stack *s,ElemType *e)
{
	if(IsEmpty(s))
	{
		printf("Stack Underflow.\n");
		return 0;
	}
	*e = s->data[s->top--];
	return 1;
}
//获取栈顶元素
int GetTop(Stack *s,ElemType *e)
{
	if(IsEmpty(s))
	{
		printf("No Element In Stack.\n");
		return 0;
	}
	*e = s->data[s->top];
	return 1;
}
//主函数
int main()
{
	Stack *s;//声明栈变量
	ElemType pushElem,callBack;//返回值
	int i;
	//初始化栈
	s = InitStack();
	//数据进栈
	printf("Enter Element:");
	for(i = 0;i < 5;i++)
	{
		scanf(IN_TYPE,&pushElem);
		Push(s,pushElem);
	}
	//数据出栈
	printf("Pop Order:");
	for(i = 0;i < 5;i++)
	{
		Pop(s,&callBack);
		printf(OUT_TYPE,callBack);
	}
	int info = IsEmpty(s);
	system("pause");
	return 0;
}
