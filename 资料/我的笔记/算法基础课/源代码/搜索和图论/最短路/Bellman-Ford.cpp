#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 510, M = 10010;

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

int n, m, k;	// n:点数 m:边数 求不超过k条边的最短距离
int dist[N];	// 从1号点走到每个点的最短距离
int backup[N];	// dist的备份

// 用自定义结构体存储图（边）
struct Edge
{
	int a, b, w;	// 从 a 到 b 有一条长度为 w 的边
} edges[M];

// 求出 1 号点到 n 号点，不超过 k 条边的最短距离
int bellman_ford()
{
	// 初始化距离
	memset(dist, 0x3f, sizeof(dist));
	dist[1] = 0;

	// 迭代 k 次（需要求几条边，就循环几次）
	for (int i = 0 ; i < k ; ++i)
	{
		// 将 dist 备份到 backup 中
		// 不进行备份的话，可能会发生“串联”
		// 备份，以保证更新只使用上一次迭代的结果
		memcpy(backup, dist, sizeof(dist));

		// 枚举所有边
		for (int j = 0 ; j < m ; ++j)
		{
			// 将这一次枚举到的数据先“拷”下来（写得代码短一点）
			int a = edges[j].a;
			int b = edges[j].b;
			int w = edges[j].w;

			// 更新最短距离
			dist[b] = min(dist[b], backup[a] + w);
		}
	}

	// 如果没有路径，返回
	if (dist[n] > 0x3f3f3f3f / 2)
		return -2;
	// 返回最短距离
	return dist[n];
}

int main()
{
	// 输入
	scanf("%d %d %d", &n, &m, &k);

	// 读入 m 条边
	int a, b, w;
	for (int i = 0 ; i < m ; ++i)
	{
		scanf("%d %d %d", &a, &b, &w);
		edges[i] = {a, b, w};
	}

	// Bellman-Ford算法
	int t = bellman_ford();

	// 输出
	if (t == -2)
		printf("impossible\n");
	else
		printf("%d\n", t);
	return 0;
}
