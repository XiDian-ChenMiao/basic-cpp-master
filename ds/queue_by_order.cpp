#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100
typedef int ElemType;
typedef struct Queue
{
	ElemType *base;
	int front;
	int rear;
}CycleQueue;
//初始化队列
void InitQueue(CycleQueue *q)
{
	q->base = (ElemType *)malloc(MAX_QUEUE_SIZE * sizeof(ElemType));
	if(!q->base)
		exit(0);
	q->front = q->rear = 0;
}
//入队列操作
void InsertQueue(CycleQueue *q,ElemType e)
{
	if((q->rear + 1) % MAX_QUEUE_SIZE == q->front)
		return;//队列已满
	q->base[q->rear] = e;
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
}
//出队列操作
void DeleteQueue(CycleQueue *q,ElemType *e)
{
	if(q->front == q->rear)
		return;//队列为空
	*e = q->base[q->front];
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
}
int main(int argc, char const *argv[])
{
	printf("InsertQueue Order:");
	CycleQueue *q;
	int i,count = 5,callBack;
	InitQueue(q);
	for (i = 0; i < count; ++i)
	{
		printf("%3d",i);
		InsertQueue(q,i);
	}
	printf("\nDeleteQueue Order:");
	for (i = 0; i < count; ++i)
	{
		DeleteQueue(q,&callBack);
		printf("%3d",callBack);
	}
	printf("\n");
	system("pause");
	return 0;
}
