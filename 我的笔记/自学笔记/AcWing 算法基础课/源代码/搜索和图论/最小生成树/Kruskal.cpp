#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 200010;

int n, m;
int p[N];

// 用结构体存储图
struct Edge
{
	int a, b, w;

	bool operator< (const Edge &W)const
	{
		return w < W.w;
	}
} edges[N];

// 并查集-查找祖宗
int find(int x)
{
	if (p[x] != x)
		p[x] = find(p[x]);
	return p[x];
}

int main()
{
	// 输入
	scanf("%d %d", &n, &m);
	int a, b, w;
	for (int i = 0 ; i < m ; ++i)
	{
		scanf("%d %d %d", &a, &b, &w);
		edges[i] = {a, b, w};
	}

	// 排序
	sort(edges, edges + m);

	// 初始化并查集
	for (int i = 1 ; i <= n ; ++i)
		p[i] = i;

	// 从小到大枚举所有边
	int res = 0, cnt = 0;
	for (int i = 0 ; i < m ; ++i)
	{
		int a = edges[i].a, b = edges[i].b, w = edges[i].w;

		// 查找祖宗
		a = find(a), b = find(b);

		// 如果不连通
		if (a != b)
		{
			res += w, ++cnt;
			// 合并并查集
			p[a] = b;
		}
	}

	// 输出
	if (cnt < n - 1)
		printf("impossible\n");
	else
		printf("%d\n", res);
	return 0;
}
