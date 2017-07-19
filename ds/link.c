#include <stdio.h>
#include <stdlib.h>
typedef int TYPE;//自定义用户数据类型
#define IN_OR_OUT "%d"
//定义链表结构体
typedef struct Node
{
         TYPE data;
         struct Node *next;
}Node;
//使用头插法建立单链表，链表的头结点head作为返回值
/*无论是哪种插入方法，如果要插入建立的单线性链表的结点是n个，算法的时间复杂度均为O(n)。
  对于单链表，无论是哪种操作，只要涉及到钩链(或重新钩链)，如果没有明确给出直接后继，
  钩链(或重新钩链)的次序必须是“先右后左”。
*/
Node *create_LinkListFromHead()
{
     TYPE data;
     Node *head,*p;
     //创建链表的表头节点head
     head = (Node *)malloc(sizeof(Node));
     head->next = NULL;
     while(1)
     {
             scanf(IN_OR_OUT,&data);
             if(data == -1)
                break;
             p = (Node *)malloc(sizeof(Node));
             p->data = data;//赋值
             p->next = head->next;//调整链表
             head->next = p;//新创建的节点总是第一个节点
     }
     return(head);
}
//尾插入法创建单链表,链表的头结点head作为返回值
Node *create_LinkListFromRear()
{
    TYPE data;
    Node *head,*p,*q;
    head = p = (Node *)malloc(sizeof(Node));
    p->next = NULL;//创建单链表的表头结点head
    while(1)
    {
         scanf(IN_OR_OUT,&data);
         if (data == -1)
            break ;
         q = (Node *)malloc(sizeof(Node));
         q->data = data;//数据域赋值
         q->next = p->next;
         p->next = q;
         p=q;
         //钩链，新创建的结点总是作为最后一个结点
    }
    return(head);
}
//删除未排序重复元素的操作
void delete_repeatElem(Node *head)
{
     Node *p = head->next,*r;//指向第一个元素节点
     Node *q;//定义中间节点q
     while(p)
     {
             r = p;
             q = r->next;
             while(q)
             {
                     if(q->data == p->data)
                     {
                            r->next = q->next;
                            free(q);
                            q = r->next;
                     }
                     else
                     {
                         r = r->next;
                         q = r->next;
                     }
             }
             p = p->next;
     }
}
//删除已排好序的链表中的重复结点数据
void delete_sortedElemLinkList(Node *head)
{
     Node *p = head->next,*r;
     r = p->next;
     while(p)
     {
             if(r == NULL)
                  break;
             if(r->data == p->data)
             {
                        p->next = r->next;
                        free(r);
                        r = p->next;
             }
             else
             {
                 p = p->next;
                 r = p->next;
             }
     }
}
//求链表的长度
int lengthOfLinkList(Node *head)
{
	int length = 0;
	Node *p = head->next;
	while(p)
	{
		length++;
		p = p->next;
	}
	return length;
}
//打印出链表内容
void display_LinkList(Node *head)
{
     Node *p = head->next;
     while(p)
     {
                   printf("%3d",p->data);
                   p = p->next;
     }
     printf("\n");
}
//添加元素操作
void addElem(Node *head,int position,TYPE element)
{
	int i = 1;
	Node *p = head,*q;
	while(p && i < position)
	{
		i++;
		p = p->next;
	}
	if(i < position)
         printf("Over the bound.\n");
    else
    {
	    q = (Node *)malloc(sizeof(Node));//申请存放数据元素的结点q
	    q->data = element;
	    q->next = p->next;
	    p->next = q;
    }
}
//删除链表中元素的操作
void delete_Element(Node *head,int position)
{
     int i = 1;
     Node *p = head->next,*q;
     while(p && i < position)
	{
		i++;
		q = p;
		p = p->next;
	}
	if(i < position)
         printf("Over the bound.\n");
    else
    {
        q->next = p->next;
        free(p);
    }
}
int main()
{
    Node *head = create_LinkListFromRear();
    printf("Enter position and element:");
    int pos,elem;
    scanf("%d%d",&pos,&elem);
    //添加元素函数调用
    addElem(head,pos,elem);
    printf("After adding the element,result:");
    //显示添加之后的结果
    display_LinkList(head);
    int deletePos;
    printf("Enter deleted-position:");
    scanf("%d",&deletePos);
    //删除某位置元素所调用函数
    printf("Deleting the element,result:");
    delete_Element(head,deletePos);
    display_LinkList(head);
    //删除重复元素之前结果
    printf("After deleting the repeated elements,result:");
    delete_repeatElem(head);
    //delete_sortedElemLinkList(head);
    display_LinkList(head);
    printf("LinkList length:%d.\n",lengthOfLinkList(head));
    system("pause");
    return 0;
} 
