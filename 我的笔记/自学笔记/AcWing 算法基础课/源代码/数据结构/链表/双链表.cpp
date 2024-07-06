#include<iostream>
#include<cstdio>
using namespace std;
const int N = 100010;
int m;
//    ��ֵ�����ң������
int e[N], l[N], r[N], idx;
// ��ʼ��
void init()
{
	//0��ʾ��˵㣬1��ʾ�Ҷ˵�
	r[0] = 1;
	l[1] = 0;
	idx = 2;
}
// �ڵ�k������Ҳ����x
void insert(int k, int x)
{
	e[idx] = x;
	l[idx] = k;
	r[idx] = r[k];
	l[r[k]] = idx;
	r[k] = idx++;
}
// �ڵ�k�����������x
void insert_left(int k, int x)
{
	insert(l[k], x);
}
// ɾ����k�����
void remove(int k)
{
	r[l[k]] = r[k];
	l[r[k]] = l[k];
}
int main()
{
	int m = 0;
	scanf("%d", &m);
	init();
	while (m--)
	{
		string op;
		cin >> op;
		int x = 0, k = 0;
		if (op == "L")
		{
			// �����������˲����� x
			scanf("%d", &x);
			insert(0, x);
		}
		else if (op == "R")
		{
			// ����������Ҷ˲����� x
			scanf("%d", &x);
			insert_left(1, x);
		}
		else if (op == "D")
		{
			// ���� k ���������ɾ��
			scanf("%d", &k);
			remove(k + 1);
		}
		else if (op == "IL")
		{
			// �ڵ� k ���������������һ����
			scanf("%d %d", &k, &x);
			insert_left(k + 1, x);
		}
		else
		{
			// �ڵ� k ����������Ҳ����һ����
			scanf("%d %d", &k, &x);
			insert(k + 1, x);
		}
	}
	// ��������ֵ
	for (int i = r[0] ; i != 1 ; i = r[i])
		printf("%d ", e[i]);
	return 0;
}
