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
// DFS，返回以u为根的子树中点的数量
int ans = N + 1;
int n;
bool st[N];
int dfs(int u)
{
	// 标记为已经被遍历过
	st[u] = true;
	int sum = 1,	// 当前子树的大小
	    res = 0;	// 每一个连通块的大小的最大值
	for (int i = h[u] ; i != -1 ; i = ne[i])
	{
		int j = e[i];
		if (!st[j])
		{
			int s = dfs(j);	// 当前子树的大小
			res = max(res, s);
			sum += s;
		}
	}
	res = max(res, n - sum);
	ans = min(ans, res);
	return sum;
}
int main()
{
	init();
	scanf("%d", &n);
	for (int i = 0 ; i < n - 1 ; ++i)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		add_double(a, b);
	}
	dfs(1);
	cout << ans << endl;
	return 0;
}
