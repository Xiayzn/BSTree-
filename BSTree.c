#include "BSTree.h"
#include"Stack.h"
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<assert.h>

void InitBSTree(BSTNode** pRoot)
{
	if (NULL == *pRoot)
		return;
	(*pRoot)->_pLeft = NULL;
	(*pRoot)->_pRright = NULL;
    
}

BSTNode* BuyBSTNode(DataType data)
{
	BSTNode* newBSTNode = NULL;
	newBSTNode = (BSTNode*)malloc(sizeof(BSTNode));
	if (NULL == newBSTNode)
	{
		assert(0);
		return NULL;
	}

	return newBSTNode;
}

void InsertBSTree(BSTNode** pRoot, DataType data)
{
	BSTNode* parent = NULL;
	BSTNode* root = NULL;

	if (NULL == *pRoot)
		return;

	if (data == (*pRoot)->_date)
		return;
	
	if (data < (*pRoot)->_date)
	{
		parent = (*pRoot)->_pLeft;
		while (parent)
		{
			if (data == parent->_date)
				return;
			root = parent;
			parent = parent->_pLeft;
		}
		root->_pLeft = BuyBSTNode(data);
	}
	else
	{
		parent = (*pRoot)->_pRright;
		while (parent)
		{
			if (data == parent->_date)
				return;
			root = parent;
			parent = parent->_pRright;
		}
		root->_pLeft = BuyBSTNode(data);
	}
}

void DeleteBSTree(BSTNode** pRoot, DataType data)
{
	BSTNode* parent = NULL;
	BSTNode* pDel = NULL;
	if (NULL == (*pRoot))
		return;
	
    if (data < (*pRoot)->_date)
	{
		pDel = *pRoot;
		while (pDel)
		{   
			parent = pDel;
			pDel = pDel->_pLeft;
			//要删除的元素在左子树 
			if (data == pDel->_date)
			{
				//要删除的结点没有左右孩子
				//要删除的结点有左孩子
				if (NULL == pDel->_pRright)
				{
					parent->_pLeft = pDel->_pLeft;
					free(pDel);
					pDel = NULL;
				}

				//要删除的结点有右孩子
				if (NULL == pDel->_pLeft)
				{
					parent->_pLeft = pDel->_pRright;
					free(pDel);
					pDel = NULL;
				}
			}
		}
	}
	else if (data > (*pRoot)->_date)
	{
		pDel = *pRoot;
		while (pDel)
		{
			parent = pDel;
			pDel = pDel->_pRright;
			//要删除的元素在右子树 
			if (data == pDel->_date)
			{
				//要删除的结点没有左右孩子
				//要删除的结点有右孩子
				if (NULL == pDel->_pLeft)
				{
					parent->_pRright = pDel->_pRright;
					free(pDel);
					pDel = NULL;
				}

				//要删除的结点有左孩子
				if (NULL == pDel->_pRright)
				{
					parent->_pRright = pDel->_pLeft;
					free(pDel);
					pDel = NULL;
				}
			}
		}
	}
	else
	{
		//要删除的结点是根结点 从右子树中找最小的结点作为替代结点  
		BSTNode* pCur = NULL;
		pCur = (*pRoot)->_pRright;
	
		//左子树存在
		if (NULL != pCur->_pLeft)
		{
			while (pCur)
			{
				pDel = pCur;
				pCur = pCur->_pLeft;
			}
			(*pRoot)->_date = pDel->_date;
			free(pDel);
			pDel = NULL;
		}
		else
		{   //左子树不存在
			pDel = pCur;
			(*pRoot)->_date = pDel->_date;
			(*pRoot)->_pRright = pDel->_pRright;
			free(pDel);
			pDel = NULL;
		}
	}
}

BSTNode* FindBSTree(BSTNode** pRoot, DataType data)
{
	BSTNode* pCur = NULL;
	if (NULL == *pRoot)
		return NULL;

	pCur = *pRoot;
	if (data < pCur->_date)
	{
		pCur = pCur->_pLeft;
		while (pCur)
		{
			if (data == pCur->_date)
				return pCur;
			pCur = pCur->_pLeft;
		}

	}
	else if (data > pCur->_date)
	{
		pCur = pCur->_pRright;
		while (pCur)
		{
			if (data == pCur->_date)
				return pCur;
			pCur = pCur->_pRright;
		}
	}
	else
	{
		return pCur;
	}

	return NULL;
}

void PreOrder(BSTNode* pRoot)
{
	Stack s;
	BSTNode* pCur = NULL;
	assert(pRoot);
	StackInit(&s);

	while (pCur)
	{
		if (pCur->_pLeft)
		{
			StackPush(&s, pCur);
			pCur = pCur->_pLeft;
		}
		else
		{
			printf("%d  ",pCur->_date);
			pCur = StackTop(&s);
			if (pCur->_pRright)
			{
				printf("%d  ", pCur->_date);
			}
			StackPop(&s);
		}
	}
}

void DestroyBSTree(BSTNode** pRoot)
{
	Stack s;
	BSTNode* pCur = NULL;
	assert(pRoot);
	StackInit(&s);

	while (pCur)
	{
		if (pCur->_pLeft)
		{
			StackPush(&s, pCur);
			pCur = pCur->_pLeft;
		}

		if (NULL == pCur->_pRright)
			free(pCur);

		pCur = StackTop(&s);
		StackPop(&s);

		if (pCur->_pRright)
		{
			StackPush(&s, pCur);
			if (NULL == pCur->_pRright && NULL == pCur->_pLeft)
			{
				free(pCur);
				pCur = StackTop(&s);
				StackPop(&s);
			}
			pCur = pCur->_pLeft;
		}

	}
}
