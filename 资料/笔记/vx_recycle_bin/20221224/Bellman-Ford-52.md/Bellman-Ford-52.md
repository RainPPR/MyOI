# 单源最短路问题：Bellman-Ford

百科：**贝尔曼-福特算法**（**Bellman-Ford**）是由**理查德·贝尔曼**（Richard Bellman）和**莱斯特·福特** 创立的。有时候这种算法也被称为 **Moore-Bellman-Ford** 算法，因为 **Edward F. Moore** 也为这个算法的发展做出了贡献。

## 特征

### 适用情况

单源最短路：从1号点到其他所有点的最短距离
存在负权边：边的权重（长度）可以为负数
特点：<mark>可以（通常用SPFA求）</mark>判断是否有负权回路（若有负权回路，最短路径长度为负无穷）

适合解决（与SPFA算法相比）“**不超过 k 条边**”一类问题

### 特征

时间复杂度：O(nm)

图的存储可以直接用 *struct* 自定义结构体（存储每一条边的起点、终点、长度）

## 思路

1. 迭代 n 次：`for i : 1 ~ n`　<mark>第 i 次操作表示：不超过 i 条边的最短距离</mark>

   1. 枚举所有边：`for : `![](https://latex.codecogs.com/svg.image?a%20\overset{w}{\longrightarrow}%20b)　<mark>松弛操作</mark>

   2. `dist[b] = min(dist[b], dist[a] + w);`

## 证明

证明：`dist[b] ≤ dist[a] + w`（<mark>三角不等式</mark>）

## 经典应用：有边数限制的最短路

>给定一个 n 个点 m 条边的有向图，图中可能存在**重边和自环**， **边权可能为负数**。
>请你求出从 1 号点到 n 号点的最多经过 k 条边的最短距离，如果无法从 1 号点走到 n 号点，输出 `impossible`。
>注意：图中可能**存在负权回路** 。


#### 详解见代码注释

### 代码

```cpp
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
```