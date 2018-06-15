# BSTree-
//stack.h
#ifndef __STACK_H__
#define __STACK_H__

#pragma once

typedef struct BSTtreeNode* DataTypeBS;

typedef struct Stack
{
	DataTypeBS* _array;
	int _top;//表示有效元素个数  表示栈顶位置
	int _capacity;//底层空间的大小
}Stack;

//初始化
void StackInit(Stack* s);

// 检测栈是否为空 
int StackEmpty(Stack* s);

// 入栈 
void StackPush(Stack* s, DataTypeBS data);

// 出栈 
void StackPop(Stack* s);

// 获取栈顶元素 
DataTypeBS StackTop(Stack* s);

// 有效元素的个数 
int StackSize(Stack* s);

//打印栈
void PrintStack(Stack* s);

//增容 
void StackCapacity(Stack* s);

//括号匹配问题
int MatchBrackets(Stack* s, const char* pstr);

//后缀表达式求值
int RPN(Stack* s, const char* pstr);
int FindSpace(const char* pstr);


#endif //__STACK_H__


//stack.c
#include"Stack.h"
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

void StackInit(Stack* s)
{
	assert(s);

	s->_top = 0;
	s->_capacity = 10;
	s->_array = (DataTypeBS *)malloc(sizeof(DataTypeBS)*s->_capacity);
	if (NULL == s->_array)
	{
		assert(s->_array);
		return;
	}
}

int StackEmpty(Stack* s)
{
	assert(s);

	if (s->_top)
		return 0;
	
	return 1;
}

void StackPush(Stack* s, DataTypeBS data)
{
	assert(s);

	//判断栈是否满了
	if (s->_top >= s->_capacity)
		StackCapacity(s);

	s->_array[s->_top++] = data;
}

void StackPop(Stack* s)
{
	assert(s);

	//动态栈为空
	if (StackEmpty(s))
		return;

	--s->_top;
}

DataTypeBS StackTop(Stack* s)
{
	assert(!StackEmpty(s));

	return s->_array[s->_top - 1];
}

int StackSize(Stack* s)
{
	assert(s);

	return s->_top;
}

void PrintStack(Stack* s)
{
	int i = 0;
	assert(s);

	//动态栈为空
	if (StackEmpty(s))
		return;

	if (0 == s->_top)
		return;

	for (i = 0; i < s->_top; ++i)
	{
		printf("%d ",s->_array[i]);
	}
	printf("\n");
}

void StackCapacity(Stack* s)
{
	assert(s);

	DataTypeBS * temp = s->_array;
	//动态栈为空
	if (StackEmpty(s))
		return;

	s->_array = (DataTypeBS *)realloc(s->_array, sizeof(DataTypeBS)*s->_capacity * 2);
	if (NULL == s->_array)
	{
		printf("增容失败");
		s->_array = temp;
	}

}

//int MatchBrackets(Stack* s, const char* pstr)
//{
//	assert(s);
//
//	int i = 0;
//	int len = 0;
//	len = strlen(pstr);
//	if (NULL == pstr)
//		return 0;
//	for (i = 0; i < len; ++i)
//	{
//		if (pstr[i] == '(' || pstr[i] == ')' ||
//			pstr[i] == '[' || pstr[i] == ']' ||
//			pstr[i] == '{' || pstr[i] == '}')
//		{
//			if (pstr[i] == '(' || pstr[i] == '[' || pstr[i] == '{')
//			{
//				StackPush(s, pstr[i]);
//			
//			}
//
//			if (pstr[i] == ')' || pstr[i] == ']' || pstr[i] == '}')
//			{
//				char str = 0;
//				if (StackEmpty(s))
//				{
//					printf("右括号多余左括号\n");
//					return 0;
//				}
//
//				str = StackTop(s);
//				if (pstr[i] == ')' && str == '(' ||
//					pstr[i] == ']' && str == '[' ||
//					pstr[i] == '}' && str == '{')
//				{
//					StackPop(s);
//				}
//				else
//				{
//					printf("括号不匹配\n");
//					return 0;
//				}
//			}
//		}
//		else
//			continue;
//		
//	}
//
//	if (!StackEmpty(s))
//	{
//		printf("左括号多余右括号\n");
//		return 0;
//	}
//
//	printf("匹配正确\n");
//	return 1;
//}
//
//int RPN(Stack* s, const char* pstr)
//{
//	int i = 0;
//	int len = 0;
//	int num = 0;
//	len = strlen(pstr);
//	assert(s);
//	assert(pstr);
//
//	for (i = 0; i < len; ++i)
//	{
//		int right = 0;
//		int left = 0;
//		if (pstr[i] >= '0' && pstr[i] <= '9')
//		{
//			StackPush(s, atoi(&pstr[i]));
//
//			i = i + FindSpace(&pstr[i]);
//			
//		}
//		else
//		{
//			if (' ' != pstr[i])
//			{
//				right = StackTop(s);
//				StackPop(s);
//				left = StackTop(s);
//				StackPop(s);
//			}
//
//			switch (pstr[i])
//			{
//			case '+':
//				StackPush(s, left + right);
//				break;
//			case '-':
//				StackPush(s, left - right);
//				break;
//			case '*':
//				StackPush(s, left * right);
//				break;
//			case '/':
//			{	
//				if (0 == right)
//				{
//					printf("分母不能为0\n");
//					break;
//	            }
//				StackPush(s, left / right);
//				break;
//			}
//			default:
//				break;
//			}
//		}
//	}
//	return StackTop(s);
//}

int FindSpace(const char* pstr)
{
	int i = 0;
	assert(pstr);

	while (' ' != pstr[i])
	{
		++i;
	}

	return i;
}


//BSTree.h


#ifndef __BSTREE_H__
#define __BSTREE_H__

#pragma once

typedef int DataType;

typedef struct BSTtreeNode
{
	struct BSTtreeNode* _pLeft;
	struct BSTtreeNode* _pRright;
	DataType _date;

}BSTNode;

//初始化二叉搜索树
void InitBSTree(BSTNode** pRoot);
//插入二叉搜索树
void InsertBSTree(BSTNode** pRoot, DataType data);
//删除值为data的结点
void DeleteBSTree(BSTNode** pRoot, DataType data);
//在二叉搜索树种查找值为data的结点
BSTNode* FindBSTree(BSTNode** pRoot, DataType data);
//中序遍历二叉搜索树
void PreOrder(BSTNode* pRoot);
//销毁二叉搜索树
void DestroyBSTree(BSTNode** pRoot);

#endif //__BSTREE_H__



//BSTree.c

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


//test.c
#include "BSTree.h"


void TestInitBSTree()
{
	BSTNode* BSTree;
	InitBSTree(&BSTree);
}

void TestInsertBSTree()
{
	BSTNode* BSTree;
	InitBSTree(&BSTree);
	InsertBSTree(&BSTree, 8);
	InsertBSTree(&BSTree, 4);
	InsertBSTree(&BSTree, 5);

}

void TestDeleteBSTree()
{
	BSTNode* BSTree;
	InitBSTree(&BSTree);
	InsertBSTree(&BSTree, 8);
	InsertBSTree(&BSTree, 4);
	InsertBSTree(&BSTree, 5);
	DeleteBSTree(&BSTree, 8);
}

void TestFindBSTree()
{
	BSTNode* BSTree;
	InitBSTree(&BSTree);
	InsertBSTree(&BSTree, 8);
	InsertBSTree(&BSTree, 4);
	InsertBSTree(&BSTree, 5);
	FindBSTree(&BSTree, 5);
	FindBSTree(&BSTree, 9);

}

void TestPreOrder()
{
	BSTNode* BSTree;
	InitBSTree(&BSTree);
	InsertBSTree(&BSTree, 8);
	InsertBSTree(&BSTree, 4);
	InsertBSTree(&BSTree, 5);
	PreOrder(BSTree);
}

void TestDestroyBSTree()
{
	BSTNode* BSTree;
	InitBSTree(&BSTree);
	InsertBSTree(&BSTree, 8);
	InsertBSTree(&BSTree, 4);
	InsertBSTree(&BSTree, 5);
	DestroyBSTree(&BSTree);
}
int main()
{
	TestInitBSTree();
	TestInsertBSTree();
	TestDeleteBSTree();
	TestFindBSTree();
	TestPreOrder();
	TestDestroyBSTree();
	return 0;
}

