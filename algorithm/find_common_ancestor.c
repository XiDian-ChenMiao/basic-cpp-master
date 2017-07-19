#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct Node
{
	int length;
	int id;
	struct Node *parent;
}Node;
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
int findCommonAncestor(Node *p,Node *q,Node *root)
{
	Node *pNode = p,*qNode = q,*rootNode = root;
	pNode->length = lengthFromSonToRoot(rootNode,pNode);
	qNode->length = lengthFromSonToRoot(rootNode,qNode);
	//第一种情况，当指定的是相同的节点时
	if(pNode == qNode)
		return pNode->id;
	else{
		while(pNode != qNode)
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
			return pNode->id;
	}

}

int main()
{
	int numberNode;//节点个数
	int start,end;
	int root,node1,node2;
	int i;
	int caseNumber;
	Node treeNode[100];
	while(scanf("%d",&numberNode) != EOF)
	{
		for(i = 0;i < numberNode - 1;i++)
		{
			scanf("%d%d",&start,&end);
			treeNode[start - 1].id = start;
			treeNode[end - 1].id = end;
			treeNode[end - 1].parent = &treeNode[start - 1];
		}
		scanf("%d",&caseNumber);
		for(i = 0;i < caseNumber;i++)
		{
			scanf("%d%d%d",&root,&node1,&node2);
			printf("%d\n",findCommonAncestor(&treeNode[node1-1],&treeNode[node2-1],&treeNode[root-1]));
		}
	}
	return 0;
} 
