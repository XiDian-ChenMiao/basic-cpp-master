#include <stdio.h>
#include <stdlib.h>
typedef int Elemtype;
//二叉排序树的结构定义
typedef struct TreeNode
{
	/* data */
	Elemtype data;
	struct TreeNode *lchild,*rchild;
}BSTNode,*BSTree;
//二叉排序树的递归查找算法
BSTNode *search(BSTNode *p,Elemtype x){
	if(p == NULL)
		return NULL;
	else if(x < p->data)
		return search(p->lchild,x);
	else if(x > p->data)
		return search(p->rchild,x);
	else return p;
}
//二叉排序树的非递归查找算法,当查找成功时，函数返回x所在节点地址，father返回该节点的父节点的
//地址；当查找不成功时，函数返回NULL，father返回新节点应插入的节点地址，此时新节点应作为叶子
//节点插入到father下。
BSTNode *search(BSTree root,Elemtype x,BSTNode *&father){
	BSTNode *p = root;
	father = NULL;
	while(p != NULL && p->data != x){
		father = p;
		if(x < p->data)
			p = p->lchild;
		else
			p = p->rchild;
	}
	return p;
}
//二叉排序树的插入
int insertNode(BSTree& root,Elemtype x){
	BSTNode *s,*p,*f;
	p = search(root,x,f);//寻找插入位置
	if(p != NULL)
		return 0;//查找成功，不插入
	s = (BSTNode *)malloc(sizeof(BSTNode));//否则新节点插入
	if(!s)
		return 0;
	s->data = x;
	s->lchild = NULL;
	s->rchild = NULL;
	if(f == NULL)
		root = s;//如果为空树，新节点为根节点
	else if(x < f->data)
		f->lchild = s;//作为左孩子插入
	else f->rchild = s;//作为右孩子插入
	return 1;
}
