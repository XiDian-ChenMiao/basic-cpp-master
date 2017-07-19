#ifndef __TREE_H__
#define __TREE_H__
typedef int ElemType;//定义节点数据类型
#define IN_OR_OUT_TYPE "%d"
#define MAX_TREE_SIZE 10
//孩子节点
typedef struct CTNode
{
	int child;//孩子节点的下标
	struct CTNode *next;//指向下一个孩子节点的指针
}*ChildPtr;
//表头节点
typedef struct
{
	int parent;//双亲节点的下标
	ElemType data;//节点信息
	ChildPtr firstChild;//第一个孩子节点
}CTBox;
//树结构
typedef struct
{
	CTBox nodes[MAX_TREE_SIZE];
	int root;//根节点的位置
	int number;//节点的数量
}Tree_Parent_Child;
//二叉链表
typedef struct BiTNode
{
	ElemType data;
	struct BiTNode *lchild,*rchild;//左孩子和右孩子
}BiTNode，*BiTree;
//二叉树的遍历方式：前序遍历，中序遍历，后序遍历，层序遍历
/*前序遍历：若二叉树为空，则空操作返回，否则先访问根节点，然后前序遍历左子树，再前序遍历右子树*/
//前序遍历二叉树，并输出每个节点所在层数
void visit(ElemType elem,int level){
	//下面即为访问节点数据的操作
	printf("Node %c ,Level %d\n",elem,level);
}
void PreOrderTraverse(BiTree T,int level){
	if (T)
	{
		visit(T->data,level);//用于访问节点的数据
		PreOrderTraverse(T->lchild,level+1);
		PreOrderTraverse(t->rchild,level+1);
	}
}
/*中序遍历：若树为空，则空操作返回，否则从根节点开始（注意并不是先访问根节点），中序遍历
根节点的左子树，然后访问根节点，最后中序遍历右子树。*/
/*后序遍历：若树为空，则空操作返回，否则从左到右先叶子后节点的方式遍历访问左右子树，最后访问根节点*/
//按照前序建立二叉树
void createBiTree(BiTree *T){
	ElemType _data;
	scanf(IN_OR_OUT_TYPE,&data);
	if(data == '#')
		*T = NULL;
	else{
		*T = (BiTNode *)malloc(sizeof(BiTNode));
		(*T)->data = _data;
		createBiTree(&(*T)->lchild);
		createBiTree(&(*T)->rchild);
	}
}
/*线索二叉树的数据结构*/
typedef enum{Link,Thread} PointerTag;//定义枚举类型,Link指向左右孩子的指针，Thread表示指向前驱后继的线索
typedef struct BiThrNode
{
	ElemType data;
	struct BiThrNode *lchild,*rchild;
	PointerTag Ltag;
	PointerTag Rtag;
}BiThrNode,*BiThrTree;
//全局变量，始终指向刚刚访问过的节点
BiThrTree pre;
//线索二叉树的构建
void createBiThrTree(BiThrTree *T){
	ElemType _data;
	scanf(IN_OR_OUT_TYPE,&data);
	if(data == '#')
		*T = NULL;
	else{
		*T = (BiThrNode *)malloc(sizeof(BiThrNode));
		(*T)->data = _data;
		(*T)->Ltag = Link;
		(*T)->Rtag = Link;
		createBiThrTree(&(*T)->lchild);
		createBiThrTree(&(*T)->rchild);
	}
}
//线索二叉树的中序遍历线索化
void MidThreadTraverse(BiThrTree T){
	if (T)
	{
		MidThreadTraverse(T->lchild);//递归左孩子线索化
		//节点处理
		if (!T->lchild)
		{//如果该节点没有左孩子，设置Ltag为Thread，并把lchild指向上一个访问的节点
			T->Ltag = Thread;//赋值为前驱
			T->lchild = pre;
		}
		if (!pre->rchild)
		{
			pre->Rtag = Thread;
			pre->rchild = T;
		}
		pre = T;
		MidThreadTraverse(T->rchild);//递归右孩子线索化
	}
}
void InitThread(BiThrTree *p,BiThrTree T){
	*p = (BiThrTree)malloc(sizeof(BiThrNode));
	(*p)->Ltag = Link;
	(*p)->Rtag = Thread;
	(*p)->rchild = *p;
	if (!T)
		(*p)->lchild = *p;
	else{
		(*p)->lchild = T;
		pre = *p;
		MidThreadTraverse(T);
		pre->rchild = *p;
		pre->Rtag = Thread;
		(*p)->rchild = pre;
	}
}
#endif
