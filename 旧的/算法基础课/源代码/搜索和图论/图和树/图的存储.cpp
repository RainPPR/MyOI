#include<cstring>
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 100010,	// 结点总数（有几条链表）
          M = N * 2;	// 边的总数（链表的结点总数）
int h[N],	// i号结点对应的链表的头
    e[M],	// 这一个结点指向的点
    ne[M],	// 下一个结点的下标
    idx;	// 结点数量
// 初始化
void init()
{
	idx = 0;
	memset(h, -1, sizeof(h));
}
// 插入一条a指向b边
void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
// 插入一条 a <-> b 的边
void add_double(int a, int b)
{
	add(a, b);
	add(b, a);
}
// 遍历x指向的所有边，返回个数
int geteg(int x)
{
	int count = 0;
	for (int i = h[x] ; i != -1 ; i = ne[i])
	{
		// 此时遍历到一条边：x -> e[i]
		count++;
		// 其他处理
	}
	return count;
}
int main()
{
	init();
	return 0;
}
