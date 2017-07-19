#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <stack>
using namespace std;
/*二叉树的数据结构*/
typedef struct BiNode {
	char data;
	struct BiNode *lchild;
	struct BiNode *rchild;
}BiNode,*BiTree;
/*先序递归建立二叉树*/
void createBiTree(BiNode **root) {
	char ch;
	scanf("\n%c",&ch);
	if(ch == '#')
		*root = NULL;
	else {
		*root = (BiNode *)malloc(sizeof(BiNode));
		(*root)->data = ch;
		printf("请输入%c的左孩子：",ch);
		createBiTree(&((*root)->lchild));
		printf("请输入%c的右孩子：",ch);
		createBiTree(&((*root)->rchild));
	}
}
/*先序递归遍历二叉树*/
void previousOrder(BiNode *root) {
	if(root == NULL)
		return;
	printf("%c ",root->data);
	previousOrder(root->lchild);
	previousOrder(root->rchild);
}
/*中序递归遍历二叉树*/
void middleOrder(BiNode *root) {
	if(root == NULL)
		return;
	middleOrder(root->lchild);
	printf("%c ",root->data);
	middleOrder(root->rchild);
}
/*后序递归遍历二叉树*/
void postOrder(BiNode *root) {
	if(root == NULL)
		return;
	postOrder(root->lchild);
	postOrder(root->rchild);
	printf("%c ",root->data);
}
/*先序非递归方式遍历二叉树*/
/*二叉树的非递归前序遍历思想：先让根进栈，只要栈不为空，就可以做弹出操作。
每次弹出一个节点，记住把它的左右节点都进栈。右子树先进栈，保证右子树在栈中总处于左子树的下方*/
void preOrderNoRecursive(BiTree T) {
	if(!T)
		return;
	stack<BiTree> s;
	s.push(T);
	while(!s.empty()) {
		BiTree temp = s.top();
		printf("%c ",temp->data);
		s.pop();
		if(temp->rchild)
			s.push(temp->rchild);
		if(temp->lchild)
			s.push(temp->lchild);
	}
}
/*二叉树的非递归中序遍历*/
void middleOrderNoRecursive(BiTree T) {
	if(!T)
		return;
	stack<BiTree> s;
	BiTree curr = T->lchild;
	s.push(T);
	while(curr != NULL || !s.empty()) {
		while(curr != NULL) {
			s.push(curr);
			curr = curr->lchild;
		}
		curr = s.top();
		s.pop();
		printf("%c ",curr->data);
		curr = curr->rchild;
	}
}
/*二叉树后序遍历的非递归形式*/
void postOrderNoRecursive(BiTree T) {
	stack<BiTree> s1,s2;
	BiTree curr;
	s1.push(T);
	while(!s1.empty()) {
		curr = s1.top();
		s1.pop();
		s2.push(curr);
		if(curr->lchild)
			s1.push(curr->lchild);
		if(curr->rchild)
			s1.push(curr->rchild);
	}
	while(!s2.empty()) {
		printf("%c ",s2.top()->data);
		s2.pop();
	}
}
/*访问二叉树的节点函数*/
bool visit(BiTree T) {
	if(T) {
		printf("%c ",T->data);
		return true;
	} else {
		return false;
	}
}
/*二叉树的层序遍历*/
void levelOrderTraverse(BiTree T) {
	queue<BiTree> queue;
	BiTree p;
	p = T;
	if(visit(p) == 1)
		queue.push(p);
	while(!queue.empty()) {
		p = queue.front();
		queue.pop();
		if(visit(p->lchild))
			queue.push(p->lchild);
		if(visit(p->rchild))
			queue.push(p->rchild);
	}
}
/*获取二叉树的深度函数*/
int getDepth(BiNode *T) {
	if(!T) {
		return 0;
	}
	int d1,d2;
	d1 = getDepth(T->lchild);
	d2 = getDepth(T->rchild);
	return (d1 > d2 ? d1 : d2) + 1;
}
/*二叉树的节点个数*/
int getNodeCount(BiNode *T) {
	if(!T)
		return 0;
	return 1 + getNodeCount(T->lchild) + getNodeCount(T->rchild);
}
/*创建菜单选项*/
void createMenu() {
	printf("|---------------本程序实现二叉树的基本操作---------------|\n");
	printf("|                     0.创建二叉树                       |\n");
	printf("|                     1.递归先序遍历                     |\n");
	printf("|                     2.递归中序遍历                     |\n");
	printf("|                     3.递归后序遍历                     |\n");
	printf("|                     4.非递归先序遍历                   |\n");
	printf("|                     5.非递归中序遍历                   |\n");
	printf("|                     6.非递归后序遍历                   |\n");
	printf("|                     7.非递归层序遍历                   |\n");
	printf("|                     8.二叉树的深度                     |\n");
	printf("|                     9.二叉树节点个数                   |\n");
	printf("|                     10.退出程序                        |\n");
	printf("|--------------------------------------------------------|\n");
	printf("您的操作选择是：");
}

/*初始化程序运行的信息*/
bool flag = true;/*程序退出的标志*/
BiNode *root = NULL;/*定义一个根节点*/
int command = 10;/*初始化操作命令*/


/*执行命令函数*/
void execution(int command) {
	switch(command) {
		case 0:
			printf("请建立二叉树并输入二叉树的根节点：");
			createBiTree(&root);
			break;
		case 1:
			if(root) {
				printf("递归先序遍历二叉树的结果为：");
				previousOrder(root);
				printf("\n");
			} else {
				printf("二叉树为空！");
			}
			break;
		case 2:
			if(root) {
				printf("递归中序遍历二叉树的结果为：");
				middleOrder(root);
				printf("\n");
			} else {
				printf("二叉树为空！");
			}
			break;
		case 3:
			if(root) {
				printf("递归后序遍历二叉树的结果为：");
				postOrder(root);
				printf("\n");
			} else {
				printf("二叉树为空！");
			}
			break;
		case 4:
			if(root) {
				printf("非递归先序遍历二叉树的结果为：");
				preOrderNoRecursive(root);
				printf("\n");
			} else {
				printf("二叉树为空！");
			}
			break;
		case 5:
			if(root) {
				printf("非递归中序遍历二叉树的结果为：");
				middleOrderNoRecursive(root);
				printf("\n");
			} else {
				printf("二叉树为空！");
			}
			break;
		case 6:
			if(root) {
				printf("非递归后序遍历二叉树的结果为：");
				postOrderNoRecursive(root);
				printf("\n");
			} else {
				printf("二叉树为空！");
			}
			break;
		case 7:
			if(root) {
				printf("非递归层序遍历二叉树的结果为：");
				levelOrderTraverse(root);
				printf("\n");
			} else {
				printf("二叉树为空！");
			}
			break;
		case 8:
			if(root) {
				printf("二叉树的深度为：%d",getDepth(root));
				printf("\n");
			} else {
				printf("二叉树为空！");
			}
			break;
		case 9:
			if(root) {
				printf("二叉树的节点个数为：%d",getNodeCount(root));
				printf("\n");
			} else {
				printf("二叉树为空！");
			}
			break;
		default:
			flag = false;
			printf("程序运行结束，按任意键退出！");
	}
}
/*主函数*/
int main() {
	while(flag) {
		createMenu();
		scanf("%d",&command);
		execution(command);
	}
	return 0;
}
