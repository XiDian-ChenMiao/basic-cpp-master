#include <iostream>
#include <assert.h>
using namespace std;

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

void FindPath(BinaryTreeNode* pRoot,int Sum,int nArr[],int& nPos)
{
	if (NULL == pRoot || Sum < 0)
	{
		return;
	}
	if (pRoot->m_nValue == Sum)
	{
		//输出数组元素
		for (int i = 0;i < nPos;i++)
		{
			cout<<nArr[i]<<" ";
		}
		cout<<pRoot->m_nValue <<endl;
		return;
	}
	nArr[nPos++] = pRoot->m_nValue;
	FindPath(pRoot->m_pLeft,Sum - pRoot->m_nValue,nArr,nPos);
	FindPath(pRoot->m_pRight,Sum - pRoot->m_nValue,nArr,nPos);
	nPos--;
}

void FindPath(BinaryTreeNode* pRoot,int Sum)
{
	assert(pRoot);
	int nArr[100];
	int nPos = 0;
	FindPath(pRoot,Sum,nArr,nPos);
}

void Create(BinaryTreeNode*& pRoot)
{
	int newData;
	cin >> newData;
	if (-1 == newData)
	{
		pRoot = NULL;
	}
	else
	{
		pRoot = new BinaryTreeNode;
		pRoot->m_nValue = newData;
		Create(pRoot->m_pLeft);      
		Create(pRoot->m_pRight);
	}
}

int main()
{
	BinaryTreeNode* pRoot = NULL;
	Create(pRoot);
	FindPath(pRoot,22);
	system("pause");
	return 1;
}
