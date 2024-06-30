#include<iostream>
#include<cstdio>
using namespace std;
const int N = 100010;
int head, e[N], ne[N], idx = 0;
void init()
{
	head = -1;
	idx = 0;
}
void add_to_head(int x)
{
	e[idx] = x;
	ne[idx] = head;
	head = idx++;
}
void add(int x, int k)
{
	e[idx] = x;
	ne[idx] = ne[k];
	ne[k] = idx++;
}
void del(int k)
{
	ne[k] = ne[ne[k]];
}
int main()
{
	int m = 0;
	scanf("%d", &m);
	init();
	while (m--)
	{
		char op;
		int k, x;
		cin >> op;
		if (op == 'H')	// 在头结点后插入
		{
			scanf("%d", &x);
			add_to_head(x);
		}
		else if (op == 'D')	// 删除第k个结点指向的结点
		{
			scanf("%d", &k);
			if (!k)
				head = ne[head];
			else
				del(k - 1);
		}
		else	 // 在第k个结点后插入
		{
			scanf("%d %d", &k, &x);
			add(x, k - 1);
		}
	}
	// 输出链表的内容
	int now = head;
	while (now != -1)
	{
		printf("%d ", e[now]);
		now = ne[now];
	}
	return 0;
}
