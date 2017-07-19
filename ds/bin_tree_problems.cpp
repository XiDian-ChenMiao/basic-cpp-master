#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
/*******************************
采用二叉树存储结构二叉树进行先序遍历的非递归算法
void preorder(BT *bt)
{
     BT *stack[maxsize],*p;
     int top;
     if(bt!=NULL)
     {
                 top=1;
                 stack[top]=bt;              //根结点入栈
                 while(top>0)
                 {
                             p=stack[top];
                             top--;         //退栈，并访问栈顶结点
                             cout<<p p;
                             if(p->rchild!=NULL)   //右孩子先入栈
                             {
                                                top++;
                                                stack[top]=p->rchild;
                             }
                             if(p->lchild!=NULL)   //左孩子后入栈，作为栈顶
                             {
                                                top++;   //在下次循环中先被访问
                                                stack[top]=p->lchild;
                             }
                 }
     }
}
**********************************/
#define NULL 0
//建立形成二叉树的结构体
typedef struct BiTNode
{
        char data;
        struct BiTNode *lchild;
        struct BiTNode *rchild;
}BiLNode,*BiTree;
//构造二叉树
BiTree Create(BiTree T)
{
       char ch;
       cin>>ch;
       if(ch=='#')
           T=NULL;
       else
       {
           if(!(T=(BiTree)malloc(sizeof(BiTNode))))
               cout<<"Error!";
           T->data=ch;
           T->lchild=Create(T->lchild);
           T->rchild=Create(T->rchild);
       }
       return T;
}
//二叉树的先序遍历
void Preorder(BiTree T)
{
     if(T)
     {
          cout<<T->data;
          Preorder(T->lchild);
          Preorder(T->rchild);
     }
}
//统计出所建立的二叉树中叶子的数目
int Sumleaf(BiTree T)
{
    int sum=0,m,n;
    if(T)
    {
         if((!T->lchild)&&(!T->rchild))
             sum++;
         m=Sumleaf(T->lchild);
         sum+=m;
         n=Sumleaf(T->rchild);
         sum+=n;
    }
    return sum;
}
//二叉树的中序遍历
void Midorder(BiTree T)
{
     if(T)
     {
          Midorder(T->lchild);
          cout<<T->data;
          Midorder(T->rchild);
     }
}
//二叉树的后序遍历
void Lastorder(BiTree T)
{
     if(T)
     {
          Lastorder(T->lchild);
          Lastorder(T->rchild);
          cout<<T->data;
     }
}
//求此二叉树的深度
int Depth(BiTree T)
{
    int dep=0,depl,depr;
    if(!T)  dep=0;
    else
    {
        depl=Depth(T->lchild);
        depr=Depth(T->rchild);
        dep=1+(depl>depr?depl:depr);
    }
    return dep;
}
//主函数
int main()
{
    BiTree T;
    int sum,dep;
    cout<<"请输入二叉树的样式：(其中#代表空结点）";
    T=Create(T);
    cout<<"先序遍历结果是：";
    Preorder(T);
    cout<<endl;
    cout<<"中序遍历结果是：";
    Midorder(T);
    cout<<endl;
    cout<<"后序遍历结果是：";
    Lastorder(T);
    cout<<endl;
    sum=Sumleaf(T);
    cout<<"叶子总数是："<<sum<<endl;
    dep=Depth(T);
    cout<<"这个二叉树的深度是："<<dep<<endl;
    system("pause");
    return 0;
}
