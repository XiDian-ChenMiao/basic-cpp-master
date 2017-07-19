#ifndef __QUEUE_H__
#define __QUEUE_H__
//定义队列的数据结构
typedef int ElemType;
typedef struct QNode
{
	ElemType data;//数据域
	struct QNode *next;//指针域
}QNode,*QueuePointer;

typedef struct
{
	QueuePointer front,rear;//首尾指针
}LinkQueue;
//初始化队列
void InitQueue(LinkQueue *q)
{
	q->front = q->rear = (QueuePointer)malloc(sizeof(QNode));
	if(!q->front)
		exit(0);
	q->front->next = NULL;
}
//入队操作
void InsertQueue(LinkQueue *q,ElemType e)
{
	QueuePointer p;
	p = (QueuePointer)malloc(sizeof(QNode));
	if(p == NULL)
		exit(0);
	p->data = e;
	p->next = NULL;
	q->rear->next = p;
	q->rear = p;
}
//进队列操作
void DeleteQueue(LinkQueue *q,ElemType *e)
{
	QueuePointer p;
	if(q->front == q->rear)
		return;
	p = q->front->next;
	*e = p->data;
	q->front->next = p->next;
	if(q->rear == p)
		q->rear = q->front;
	free(p);
}
//销毁队列
void DestoryQueue(LinkQueue *q)
{
	while(q->front)
	{
		q->rear = q->front->next;
		free(q->front);
		q->front = q->rear;
	}
}
#endif
