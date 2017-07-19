#ifndef __STACK_H_
#define __STACK_H_

#include <stdio.h>
#include <stdlib.h>

#define STACK_MAX_SIZE 100
#define STACK_INCREMENT 10
#define MAX_BUFFER 10
typedef char ElemType;
typedef struct
{
	ElemType *base;//数据域
	ElemType *top;//代码域
	int stack_size;//栈空间大小
}Stack;
//初始化栈
void InitStack(Stack *s)
{
	s->base = (ElemType *)malloc(STACK_MAX_SIZE * sizeof(ElemType));
	if(!s->base)
	{
		printf("InitStack fail.\n");
		exit(0);
	}
	s->top = s->base;
	s->stack_size = STACK_MAX_SIZE;
}
//入栈操作
void Push(Stack *s,ElemType e)
{
	//判断是否栈满
	if(s->top - s->base >= s->stack_size)
	{
		s->base = (ElemType *)realloc(s->base,(s->stack_size + STACK_INCREMENT) * sizeof(ElemType));
		if(!s->base)
			exit(0);
		s->top = s->base + s->stack_size;
		s->stack_size += STACK_INCREMENT;
	}
	*(s->top++) = e;
}
//弹栈操作
void Pop(Stack *s,ElemType *e)
{
	if(s->top == s->base)
	{
		printf("Stack Empty.\n");
		return;
	}
	*e = *--(s->top);
}
//清空栈
void ClearStack(Stack *s)
{
	s->top = s->base;
}
//销毁栈
void DestoryStack(Stack *s)
{
	int i,len;
	len = s->stack_size;
	for(i = 0;i < len;i++)
	{
		free(s->base);
		s->base++;
	}
	s->base = s->top = NULL;
	s->stack_size = 0;
}
//求栈长度
int StackLen(Stack s)
{
	return s.top - s.base;
}

#endif
