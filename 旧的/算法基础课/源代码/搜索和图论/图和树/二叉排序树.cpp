#include<bits/stdc++.h>
using namespace std;
typedef struct BSTNode
{
	int key;	// 结点的值
	struct BSTNode
		*lchild,	// 指针存储左子树
		*rchild;	// 指针存储右子树
} BSTNode, *BSTree;
// 在二叉树中查找值为 key 的结点（循环实现）
BSTNode *BST_Search_1(BSTree T, int key)
{
	// 若树空或等于要查找的值，循环停止
	while ((T != NULL) && (T->key != key))
		if (key < T->key)	// key比这一节点小，则在左子树上查找
			T = T->lchild;
		else				// key比这一节点大，则在右子树上查找
			T = T->rchild;
	return T;
}
// 在二叉树中查找值为 key 的结点（递归实现）
BSTNode *BST_Search_2(BSTree T, int key)
{
	if (T == NULL)		// 查找失败
		return NULL;
	if (key == T->key)	// 查找成果
		return T;
	if (key < T->key)	// key 比这一节点小，则在左子树上查找
		return BST_Search_2(T->lchild, key);
	else				// key 比这一节点大，则在右子树上查找
		return BST_Search_2(T->rchild, key);
}
// 在二叉排序树中插入关键字为k的新节点
bool BST_Insert(BSTree &T, int k)
{
	if (T == NULL)	// 原树为空，新插入的结点为根节点
	{
		T = (BSTree)malloc(sizeof(BSTNode));
		T->key = k;
		T->lchild = T->rchild = NULL;
		return true;	// 插入成功，返回TRUE
	}
	if (k == T->key)	// 树中存在相同值的结点，插入失败
		return false;
	if (k < T->key)		// k小于根节点值，插入到左子树
		return BST_Insert(T->lchild, k);
	else				// k大于根节点值，插入到右子树
		return BST_Insert(T->rchild, k);
}
// 按照 p[] 中的值序列建立二叉排序树
void Creat_BST(BSTree &T, int p[], int n)
{
	T = NULL;						// 初始化T为空树
	for (int i = 0 ; i < n ; ++i)	// 依次将每个值插入到二叉排序树中
		BST_Insert(T, p[i]);
}
int main()
{
	return 0;
}
