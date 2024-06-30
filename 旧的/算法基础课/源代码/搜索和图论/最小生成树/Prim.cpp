#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 510;
const int INF = 0x3f3f3f3f;

int n, m;
int g[N][N];	// 稠密图用邻接矩阵存储
int dist[N];	// 每个点到连通块的距离
bool st[N];		// 这个点是否在连通块内

int prim()
{
	memset(dist, 0x3f, sizeof dist);

	int res = 0;	// 所有边的长度之和
	for (int i = 0 ; i < n ; ++i)
	{
		int t = -1;
		for (int j = 1 ; j <= n ; ++j)
			if (!st[j] && (t == -1 || dist[t] > dist[j]))
				t = j;

		// 图不连通，没有最小生成树
		if (i && dist[t] == INF)
			return INF;
		if (i)				// 如果不是第一个点
			res += dist[t];	// 结果中加入边

		// 更新距离
		for (int j = 1 ; j <= n ; ++j)
			dist[j] = min(dist[j], g[t][j]);

		// 加入连通块
		st[t] = true;
	}

	return res;
}

int main()
{
	// 初始化距离为正无穷
	memset(g, 0x3f, sizeof g);

	// 输入
	scanf("%d %d", &n, &m);

	int a, b, c;
	while (m--)
	{
		scanf("%d %d %d", &a, &b, &c);
		g[a][b] = g[b][a] = min(g[a][b], c);
	}

	// Prim算法
	int t = prim();

	// 输出
	if (t == INF)
		printf("impossible\n");
	else
		printf("%d\n", t);
	return 0;
}
