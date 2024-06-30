# 单源最短路算法：Dijkstra

## 适用场景

单源最短路：从1号点到其他所有点的最短距离
没有负权边：所有边的权重（长度）都是正数

## 朴素版 Dijkstra 适用于【稠密图】

#### [原题链接](https://www.**.com/problem/content/851/)

### 特征

* 贪心
* 时间复杂度：O(n^2)

### 思路

1. 初始化距离：`dist[1] = 0, dist[i] = ∞;`
   1 号点到 1 号点的距离是 0；其他点到 1 号点的距离设为正无穷
2. 集合 s：存储已经确定最短距离的点
3. 循环：`for i : 0 ~ n`
   1. t ← 不在 s 中的，距离最短的点
   2. 将 t 加入 s 中：s ← t
   3. 用 t 更新其他所有点的距离（从 t 出去的所有边，能不能更新其他点的距离）：![](https://latex.codecogs.com/svg.image?\small%20[%20\text{%20}%20\overset{t}{O}%20\overset{w}{\rightarrow}%20\overset{x}{O}%20\text{%20}%20]%20\text{%20}%20if%20\text{%20}%20dist[x]%20%3E%20dist[t]%20+%20w)

### C++代码

```cpp
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

int n, m;                // n:点数 m:边数
int g[N][N];        // 稠密图用邻接矩阵存储
int dist[N];        // 从1号点走到每个点的最短距离
bool st[N];                // 这个点的最短距离是否已经确定

// 求出 1 号点到 n 号点的最短距离
int dijkstra()
{
        // 初始化距离
        memset(dist, 0x3f, sizeof(dist));
        dist[1] = 0;

        // 循环 n 次
        for (int i = 0 ; i < n ; ++i)
        {
                int t = -1;        // 不在 s 中的，距离最短的点
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
                g[a][b] = MIN(g[a][b], c);        // 图中可能存在重边和自环：保留长度最短的边
        }

        // 朴素版Dijkstra
        int t = dijkstra();

        // 输出
        printf("%d\n", t);

        return 0;
}
```


## 堆优化 Dijkstra 适用于【稀疏图】

#### [原题链接](https://www.**.com/problem/content/852/)

### 特征
* 贪心、堆
* 时间复杂度：O(m log n)

### 回顾朴素版的思路

1. 初始化距离：`dist[1] = 0, dist[i] = ∞;`
   1 号点到 1 号点的距离是 0；其他点到 1 号点的距离设为正无穷
2. 集合 s：存储已经确定最短距离的点
3. 循环：`for i : 0 ~ n`
   1. t ← 不在 s 中的，距离最短的点
   2. 将 t 加入 s 中：s ← t
   3. 用 t 更新其他所有点的距离（从 t 出去的所有边，能不能更新其他点的距离）：![](https://latex.codecogs.com/svg.image?\small%20[%20\text{%20}%20\overset{t}{O}%20\overset{w}{\rightarrow}%20\overset{x}{O}%20\text{%20}%20]%20\text{%20}%20if%20\text{%20}%20dist[x]%20%3E%20dist[t]%20+%20w)

#### 通过分析可知，3.1 找距离最短的点复杂度高，可使用“堆（SLT-优先队列）”进行维护

#### 缺点：STL不能修改任意元素，可能有冗余

### C++代码

```cpp
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

int n, m;                // n:点数 m:边数

int h[N], w[N], e[N], ne[N], idx;        // 稀疏图用邻接表存储
int dist[N];        // 从1号点走到每个点的最短距离
bool st[N];                // 这个点的最短距离是否已经确定

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
                if (st[ver])        // 确保不在 s 中
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
                add(a, b, c);        // 用邻接表存储，无需判断重边
        }

        // 堆优化Dijkstra
        int t = dijkstra();

        // 输出
        printf("%d\n", t);

        return 0;
}
```