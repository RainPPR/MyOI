#include<bits/stdc++.h>
using namespace std;
typedef struct BSTNode
{
	int key;	// ����ֵ
	struct BSTNode
		*lchild,	// ָ��洢������
		*rchild;	// ָ��洢������
} BSTNode, *BSTree;
// �ڶ������в���ֵΪ key �Ľ�㣨ѭ��ʵ�֣�
BSTNode *BST_Search_1(BSTree T, int key)
{
	// �����ջ����Ҫ���ҵ�ֵ��ѭ��ֹͣ
	while ((T != NULL) && (T->key != key))
		if (key < T->key)	// key����һ�ڵ�С�������������ϲ���
			T = T->lchild;
		else				// key����һ�ڵ�������������ϲ���
			T = T->rchild;
	return T;
}
// �ڶ������в���ֵΪ key �Ľ�㣨�ݹ�ʵ�֣�
BSTNode *BST_Search_2(BSTree T, int key)
{
	if (T == NULL)		// ����ʧ��
		return NULL;
	if (key == T->key)	// ���ҳɹ�
		return T;
	if (key < T->key)	// key ����һ�ڵ�С�������������ϲ���
		return BST_Search_2(T->lchild, key);
	else				// key ����һ�ڵ�������������ϲ���
		return BST_Search_2(T->rchild, key);
}
// �ڶ����������в���ؼ���Ϊk���½ڵ�
bool BST_Insert(BSTree &T, int k)
{
	if (T == NULL)	// ԭ��Ϊ�գ��²���Ľ��Ϊ���ڵ�
	{
		T = (BSTree)malloc(sizeof(BSTNode));
		T->key = k;
		T->lchild = T->rchild = NULL;
		return true;	// ����ɹ�������TRUE
	}
	if (k == T->key)	// ���д�����ֵͬ�Ľ�㣬����ʧ��
		return false;
	if (k < T->key)		// kС�ڸ��ڵ�ֵ�����뵽������
		return BST_Insert(T->lchild, k);
	else				// k���ڸ��ڵ�ֵ�����뵽������
		return BST_Insert(T->rchild, k);
}
// ���� p[] �е�ֵ���н�������������
void Creat_BST(BSTree &T, int p[], int n)
{
	T = NULL;						// ��ʼ��TΪ����
	for (int i = 0 ; i < n ; ++i)	// ���ν�ÿ��ֵ���뵽������������
		BST_Insert(T, p[i]);
}
int main()
{
	return 0;
}
