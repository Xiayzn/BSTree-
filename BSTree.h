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
