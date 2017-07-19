#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
typedef int Elemtype;
//定义二叉树的结构
typedef struct tree
{
        Elemtype data;
        struct tree *lchild;
        struct tree *rchild;
}*Ptree,Dtree;      //Dtree只要用于申请结构体空间，而*Ptree用于生成一个指针结构体
//先序建立二叉树
Ptree createTree()
{
      Elemtype ch;
      Ptree t;
      scanf("%d",&ch);
      if(ch==-1)
          t=NULL;
      else
      {
          if(!(t=(Ptree)malloc(sizeof(Dtree))))
                cout<<"ERROR!";
          t->data=ch;
          t->lchild=createTree();
          t->rchild=createTree();
      }
      return t;
}
//定义队列
typedef struct queue
{
        Ptree data[100];
        int front,rear;
}Dqueue,*Pqueue;
//初始化队列
Pqueue initQueue()
{
       Pqueue p;
       p=(Pqueue)malloc(sizeof(Dqueue));
       if(p)
       {
            p->front=0;
            p->rear=0;
       }
       return p;
}
//判断队列是否为空
int emptyQueue(Pqueue p)
{
    if(p->front==p->rear)
        return 1;
    else
        return 0;
}
//入队
void inQueue(Pqueue p,Ptree t)
{
     p->rear=(p->rear+1)%100;
     p->data[p->rear]=t;
}
//出队
void outQueue(Pqueue p,Ptree *t)
{
     p->front=(p->front+1)%100;
     *t=p->data[p->front];
}
//******************************************************
//层次遍历
void levelOrder(Ptree t)
{
     Ptree p=t;
     Pqueue Q;
     if(p)
     {
          Q=initQueue();//初始化队列
          cout<<p->data;
          inQueue(Q,p);
          while(!emptyQueue(Q))//当队列不为空
          {
                outQueue(Q,&p);//出队
                if(p->lchild)
                {
                             cout<<p->lchild->data;
                             inQueue(Q,p->lchild);//进队
                }
                if(p->rchild)
                {
                             cout<<p->rchild->data;
                             inQueue(Q,p->rchild);//进队
                }
          }
     }
}
//*******************************************************
//度为1的节点个数
int Degrees_1(Ptree t)
{
      if (t == NULL)
          return 0;
      if(t->lchild != NULL && t->rchild == NULL || t->lchild == NULL && t->rchild != NULL)
          return 1 + Degrees_1(t->lchild) + Degrees_1(t->rchild);
      else
          return Degrees_1(t->lchild) + Degrees_1(t->rchild);
}
//度为2的节点个数
int Degrees_2(Ptree t)
{
    if (t == NULL)
          return 0;
    if(t->lchild != NULL && t->rchild != NULL)
          return 1 + Degrees_2(t->lchild) + Degrees_2(t->rchild);
    else
          return Degrees_2(t->lchild) + Degrees_2(t->rchild);
}
//先序遍历
void preOrder(Ptree t)
{
     if(t)
     {
          cout<<t->data;
          preOrder(t->lchild);
          preOrder(t->rchild);
     }
}
//中序遍历
void intOrder(Ptree t)
{
     if(t)
     {
          intOrder(t->lchild);
          cout<<t->data;
          intOrder(t->rchild);
     }
}
//后序遍历
void postOrder(Ptree t)
{
     if(t)
     {
          postOrder(t->lchild);
          postOrder(t->rchild);
          cout<<t->data;
     }
}
//求叶子数，另外一种算法就是叶子数 = 度为2的数 + 1；
int leafCount(Ptree t)
{
     int count1,count2,sum=0;
     if(t)
     {
         if((!t->lchild)&&(!t->rchild))
             sum++;
         count1=leafCount(t->lchild);
         sum+=count1;
         count2=leafCount(t->rchild);
         sum+=count2;
    }
    return sum;
}
//求二叉树每层结点的个数，保存到数组num中
void levelCount(Ptree t,int l,int num[])
{
     if(t)
     {
          num[l]++;
          levelCount(t->lchild,l+1,num);
          levelCount(t->rchild,l+1,num);
     }
}
//求二叉树的高度
int heightTree(Ptree t)
{
     int h1,h2;
     if(t==NULL)
         return 0;
     else
     {
         h1=heightTree(t->lchild);
         h2=heightTree(t->rchild);
         if(h1>h2)
              return h1+1;
         else
              return h2+1;
     }
}
//从以t为根的二叉树中删除所有叶子节点
void deleteLeaf(Ptree t)
{
    if(t == NULL)
        return;
    if(t->lchild == NULL && t->rchild == NULL)
    {
        delete t;
        t = NULL;
    }else{
        deleteLeaf(t->lchild);
        deleteLeaf(t->rchild);
    }
}
//以t为根节点的二叉树中各节点中的最大值
void MaxValue(Ptree t,Elemtype &Maxelement)
{
    if(t != NULL)
    {
        if(t->data > Maxelement)
            Maxelement = t->data;
        MaxValue(t->lchild,Maxelement);
        MaxValue(t->rchild,Maxelement);
    }
}
//利用二叉树的前序遍历求前序遍历序列第k个节点
Ptree Pre_search_K(Ptree t,int &count,int k)
{
    if(t != NULL)
    {
        count++;
        if(count == k)
            return t;
        Ptree p;
        if((p = Pre_search_K(t->lchild,count,k)) != NULL)
            return p;
        return Pre_search_K(t->rchild,count,k);
    }
    return NULL;
}
//利用后序遍历求二叉树的高度并判断此二叉树是否为平衡二叉树
bool HeightBalance(Ptree t,int &height)
{
    if (t != NULL)
    {
      /* code */
      int lHeight,rHeight;
      bool lFlag = HeightBalance(t->lchild,lHeight);//左子树的高度
      bool rFlag = HeightBalance(t->rchild,rHeight);//右子树的高度
      height = (lHeight > rHeight) ? lHeight + 1 : rHeight + 1;
      if(abs(lHeight - rHeight) <= 1)
          return true;
      else
          return false;
    }
    else{
        height = 0;
        return false;
    }
}
//交换以t为根节点的每个节点的左右孩子
void reflect(Ptree t){
    if(t == NULL)
        return;
    reflect(t->lchild);
    reflect(t->rchild);
    Ptree p = t->lchild;
    t->lchild = t->rchild;
    t->rchild = p;
}
bool FIND_BRANCH_FLAG = false;
//在二叉树上寻找是否存在支路上数字之和为sum的支路
void find_branch(Ptree t,int sum)
{
	if(FIND_BRANCH_FLAG == true)
		return;
	if(t)
	{
		sum = sum - t->data;
		if(sum == 0 && t->lchild == NULL && t->rchild == NULL)
		{
			FIND_BRANCH_FLAG = true;
			return;
		}
	}
	if(t->lchild != NULL)
		find_branch(t->lchild,sum + t->data);
	if(t>rchild != NULL)
		find_branch(t->rchild,sum + t->data);
}
//主函数
int main()
{
    int num[10]={0};
    int height;
    int i,count = 0;
    char maxValue;
    Ptree t,temp;
    cout<<"请输入二叉树的形式（其中#代表空结点）：";
    t=createTree();//先序建立二叉树
    cout<<"先序遍历:";
    preOrder(t);
    cout<<endl;
    temp = Pre_search_K(t,count,5);
    cout<<"前序遍历第5个节点是:"<<temp->data<<endl;
    cout<<"中序遍历:";
    intOrder(t);
    cout<<endl;
    cout<<"后序遍历：";
    postOrder(t);
    cout<<endl;
    //deleteLeaf(t);//删除所有叶节点
    MaxValue(t,maxValue);
    cout<<"该二叉树为平衡二叉树?"<<HeightBalance(t,height)<<endl;
    cout<<"二叉树中值最大为:"<<maxValue<<endl;
    cout<<"度为1的节点个数:"<<Degrees_1(t)<<endl;
    cout<<"度为2的节点个数:"<<Degrees_2(t)<<endl;
    cout<<"层次遍历(即广度优先遍历)：";
    levelOrder(t);
    cout<<endl;
    height=heightTree(t);//树的深度
    cout<<"树的深度是："<<height<<endl;
    levelCount(t,1,num);//每层结点数
    for(i=1;i<=height;i++)
         cout<<"第"<<i<<"层结点个数："<<num[i]<<endl;
    cout<<"叶子总数："<<leafCount(t)<<endl;
    cout<<"交换左右孩子，后序遍历结果是:";
    postOrder(t);
    cout<<endl;
    system("pause");
    return 0;
}
