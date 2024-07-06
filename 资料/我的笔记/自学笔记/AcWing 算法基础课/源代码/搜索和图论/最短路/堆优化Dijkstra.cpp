#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e6 + 10;
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

int h[N], w[N], e[N], ne[N], idx;	// 稀疏图用邻接表存储
int dist[N];	// 从1号点走到每个点的最短距离
bool st[N];		// 这个点的最短距离是否已经确定

void add(int a, int b, int c)
{
	e[idx] = b;
	w[idx] = c;
	ne[idx] = h[a];
	h[a] = idx++;
}

// 求出 1 号点到 n 号点的最短距离
int dijkstra()
{
	// 初始化距离
	memset(dist, 0x3f, sizeof(dist));
	dist[1] = 0;

	// 用堆维护、查找距离最短的点
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	heap.push({0, 1});

	while (heap.size())
	{
		// 不在 s 中的，距离最短的点
		PII t = heap.top();
		heap.pop();

		int ver = t.second, distance = t.first;
		if (st[ver])	// 确保不在 s 中
			continue;
		st[ver] = true;

		// 用 t 更新其他所有点的距离
		for (int i = h[ver] ; i != -1 ; i = ne[i])
		{
			int j = e[i];
			if (dist[j] > distance + w[i])
			{
				dist[j] = distance + w[i];
				heap.push({dist[j], j});
			}
		}
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
	// 初始化邻接表
	memset(h, -1, sizeof(h));

	// 输入
	scanf("%d %d", &n, &m);
	int a, b, c;
	while (m--)
	{
		scanf("%d %d %d", &a, &b, &c);
		add(a, b, c);	// 用邻接表存储，无需判断重边
	}

	// 堆优化Dijkstra
	int t = dijkstra();

	// 输出
	printf("%d\n", t);

	return 0;
}
