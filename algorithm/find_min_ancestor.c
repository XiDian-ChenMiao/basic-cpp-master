#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct Node
{
	int length;
	int id;
	struct Node *parent;
}Node;
int findCommonAncestor(Node *p,Node *q)
{
	int ptreeHeight,qtreeHeight;
	Node *pNode = p,*qNode = q;
	if(pNode->parent != qNode->parent)
	{
		while(pNode->parent != qNode->parent)
		{
			if(pNode->length > qNode->length)
				pNode = pNode->parent;
			else if(pNode->length < qNode->length)
				qNode = qNode->parent;
			else
			{
				pNode = pNode->parent;
				qNode = qNode->parent;
			}
		}
	}
	else if(pNode->parent == qNode->parent)
		return pNode->parent->id;
	if(pNode->parent != NULL)
		return pNode->parent->id;
	else
		return -1;
}
int lengthFromSonToRoot(Node *root,Node *son)
{
	Node *p = root,*q = son;
	int length = 0;
	while(son != root)
	{
		length++;
		son = son->parent;
	}
	return length;
}
int main()
{
	int numberNode;//节点个数
	int rootNumber;//根节点编号
	int sourceNode,destNode;
	int child1,child2;

	printf("Please enter the number of Node:");
	scanf("%d",&numberNode);

	printf("Please enter information:\n");
	Node treeNode[numberNode];
	int i;
	for(i = 0;i < numberNode - 1;i++)
	{
		scanf("%d%d",&sourceNode,&destNode);
		treeNode[destNode - 1].id = destNode;
		treeNode[sourceNode - 1].id = sourceNode;
		treeNode[destNode - 1].parent = &treeNode[sourceNode - 1];
	}

	printf("Root number:");
	scanf("%d",&rootNumber);
	treeNode[rootNumber - 1].length = 0;//根节点深度为0
	treeNode[rootNumber - 1].id = rootNumber;//根节点编号为rootNumber
	//计算各个节点深度
	int length;
	for(i = 0;i < numberNode;i++)
	{
		if(i != rootNumber - 1)
		{
			length = lengthFromSonToRoot(&treeNode[rootNumber-1],&treeNode[i]);
			treeNode[i].length = length;
		}
	}
	printf("Please enter two descentNumber:");
	scanf("%d%d",&child1,&child2);
	int result = findCommonAncestor(&treeNode[child1 - 1],&treeNode[child2 - 1]);
	printf("result:%d\n",result);
	system("pause");
	return 0;
} 
