#include<stdio.h>
#include<stdlib.h>
typedef struct LNode
{
	int password;
	int num;
	struct LNode *next;
}LNode,*LinkList;

LinkList l,p,q;    //结构体指针
void creatlist()
{                         //初始化约瑟夫环
    int i;
	l=(LNode*)malloc(sizeof(LNode));    //作用是在内存的动态存储区中分配一个长度为 sizeof(LNode)的连续空间
	printf("请输入各元素的编号和密码:");
	scanf("%d%d",&l->num,&l->password);
    p=l; //p指针指向第一个人
	for(i=1;i<7;i++)
    {
		q=(LNode*)malloc(sizeof(LNode));
		scanf("%d%d",&q->num,&q->password);
		l->next=q;
		l=q;  //l指针指向当前环上的最后一个人
	}
	l->next=p; //将最后一个人和第一个人串起来
	p=l; //p指针此时指向约瑟夫环上的最后一个人
}

void loseph(int k)
{
    int i;
	while(p!=p->next)
    {
		if(k==1)
        {                       //得到密码,根据密码顺时针遍历,找到下一个要出列的人,如此循环,直到所有人都出列为止
			k=p->next->password;
			q=p->next;
			p->next=q->next;           //密码为1的人作特殊处理
			printf("%d,",q->num);
			free(q);
		}
		else{
			for(i=1;i<k;i++)                //其它密码的处理
				p=p->next;
			k=p->next->password;
			q=p->next;
			p->next=q->next;
			printf("%d,",q->num);
			free(q);
		}
	}
	printf("%d\n",p->num);
    free(p);
}

int main()
{
	int m;
	creatlist();
    printf("请输入报数的初始值m(m<=30):");
	scanf("%d",&m);
	printf("\n出列顺序:\n");
	loseph(m);
	system("pause");
	return 0;
}
