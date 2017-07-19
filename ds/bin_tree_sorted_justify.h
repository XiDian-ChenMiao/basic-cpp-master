#ifndef __BIN_TREE_SORTED_JUSTIFY_H__
#define __BIN_TREE_SORTED_JUSTIFY_H__
/*
	判定给定的二叉树是否是二叉排序树是建立在二叉树中序遍历的基础上。
	在遍历中附设一指针pre指向树中当前访问节点的中序直接前驱，每访
	问一个结点就比较前驱节点pre与该节点是否有序。若遍历结束后各节点
	和其中序直接前驱节点均满足有序，则此二叉树即为二叉排序树，否则不是。
*/
void BisortTreeBit(BiTree T,BiTree pre,int &flag){
	//初始时pre = NULL，flag = 1，若结束时flag = 1，则为二叉排序树
	if (T != NULL && flag == 1)
	{
		BisortTreeBit(T->lchild,pre,flag);//遍历左子树
		if(pre == NULL)
		{
			flag = 1;
			pre = T;
		}
		else{//比较T与中序直接前驱pre的大小
			if(pre->data < T->data)
			{
				flag = 1;
				pre = T;
			}
			else
				flag = 0;//pre与T无序
		}
		BisortTreeBit(T->rchild,pre,flag);//遍历右子树
	}
}
#endif
