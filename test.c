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
