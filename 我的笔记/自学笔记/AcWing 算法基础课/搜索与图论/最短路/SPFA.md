# SPFA

SPFA（Shortest Path Faster Algorithm）算法是 Bellman-Ford 算法的队列优化算法，通常用于求含负权边的单源最短路径，以及判负权环。

复杂度：一般 $O(m)$，最坏 $O(nm)$。

## Bellman-Ford 的优化

### 先回顾下 Bellman-Ford 算法的思路
1. 迭代 $n$ 次：$\text{for } i : 1 \sim n$　第 $i$ 次操作表示：不超过 $i$ 条边的最短距离

   1. 枚举所有边：$\text{for} : a \overset{w}{\longrightarrow} b$　`松弛操作`

   2. $dist[b] = \min(dist[b], dist[a] + w);$

```
1. 迭代 n 次：`for i : 1 ~ n`　第 i 次操作表示：不超过 i 条边的最短距离

   1. 枚举所有边：`for : `![](https://latex.codecogs.com/svg.image?a%20\overset{w}{\longrightarrow}%20b)　`松弛操作`

   2. `dist[b] = min(dist[b], dist[a] + w);`
```
### 如何优化
Bellman-Ford 算法，每次迭代所有边，来更新 $dist[i]$（再此进行优化）
在 $dist[b] = \min(dist[b], dist[a] + w);$ 中，如果 $dist[b]$ 变小，则 $dist[a]$ 一定变小了（否则 $dist[b]$ 不会变）

这里用宽搜进行优化

## 算法思路

1. $queue \leftarrow 1$
2. while $queue$ 不空
   1. $t \leftarrow q.front;$
   $q.pop();$
   2. 更新 $t$ 的所有出边：$t \overset{w}{\rightarrow} b$
   $queue \leftarrow b;$（如果 $b$ 不在队列里）

**详解见注释**

## 代码
```cpp
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
```