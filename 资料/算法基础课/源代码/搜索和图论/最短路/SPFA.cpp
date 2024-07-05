#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e6 + 10;

int n, m;		// n:点数 m:边数

int h[N], w[N], e[N], ne[N], idx;
int dist[N];	// 从1号点走到每个点的最短距离
bool st[N];		// 这个点是否在队列当中，避免重复存储

void add(int a, int b, int c)
{
	e[idx] = b;
	w[idx] = c;
	ne[idx] = h[a];
	h[a] = idx++;
}

// 求出 1 号点到 n 号点的最短距离
int spfa()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;

	queue<int> q;
	q.push(1);
	st[1] = true;

	while (q.size())
	{
		int t = q.front();
		q.pop();

		st[t] = false;

		for (int i = h[t] ; i != -1 ; i = ne[i])
		{
			int j = e[i];
			if (dist[j] > dist[t] + w[i])
			{
				dist[j] = dist[t] + w[i];
				if (!st[j])
				{
					q.push(j);
					st[j] = true;
				}
			}
		}
	}

	if (dist[n] == 0x3f3f3f3f)
		return -2;
	else
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
		add(a, b, c);
	}

	// SPFA
	int t = spfa();

	// 输出
	if (t == -2)
		printf("impossible\n");
	else
		printf("%d\n", t);

	return 0;
}
