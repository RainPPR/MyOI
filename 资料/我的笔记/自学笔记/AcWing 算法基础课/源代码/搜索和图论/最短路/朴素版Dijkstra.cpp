#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 510;
const int INF = 0x3f3f3f3f;

// 返回最大值
inline int MAX(int a, int b)
{
	return (a > b) ? a : b;
}
// 返回最小值
inline int MIN(int a, int b)
{
	return (a < b) ? a : b;
}

int n, m;		// n:点数 m:边数
int g[N][N];	// 稠密图用邻接矩阵存储
int dist[N];	// 从1号点走到每个点的最短距离
bool st[N];		// 这个点的最短距离是否已经确定

// 求出 1 号点到 n 号点的最短距离
int dijkstra()
{
	// 初始化距离
	memset(dist, 0x3f, sizeof(dist));
	dist[1] = 0;

	// 循环 n 次
	for (int i = 0 ; i < n ; ++i)
	{
		int t = -1;	// 不在 s 中的，距离最短的点
		for (int j = 1 ; j <= n ; ++j)
			if (!st[j] && (t == -1 || dist[t] > dist[j]))
				t = j;
		st[t] = true;

		// 如果已经找到最短路：退出
		if (t == n)
			break;

		// 用 t 更新其他所有点的距离
		for (int j = 1 ; j <= n ; ++j)
			dist[j] = MIN(dist[j], dist[t] + g[t][j]);
	}

	// 如果没有路径
	if (dist[n] == INF)
		// 返回 -1
		return -1;
	// 返回 1 号点到 n 号点的距离
	return dist[n];
}

int main()
{
	// 初始化邻接矩阵
	memset(g, 0x3f, sizeof(g));

	// 输入
	scanf("%d %d", &n, &m);
	int a, b, c;
	while (m--)
	{
		scanf("%d %d %d", &a, &b, &c);
		g[a][b] = MIN(g[a][b], c);	// 图中可能存在重边和自环：保留长度最短的边
	}

	// 朴素版Dijkstra
	int t = dijkstra();

	// 输出
	printf("%d\n", t);

	return 0;
}
