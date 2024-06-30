# DFS
搜索树（重点：回溯--完全恢复原状、顺序--字典序、剪枝--提前判断分支不合法）
## 排列数字
```cpp
#include<iostream>
#include<cstdio>
using namespace std;
const int N = 10;
int n;
int a[N];
bool st[N];
void dfs(int now)
{
	if (now == n)
	{
		for (int i = 0 ; i < n ; i++)
			printf("%d ", a[i]);
		printf("\n");
		return;
	}
	for (int i = 1 ; i <= n ; i++)
		if (!st[i])
		{
			st[i] = 1;
			a[now] = i;
			dfs(now + 1);
			st[i] = 0;
		}
}
int main()
{
	scanf("%d", &n);
	dfs(0);
	return 0;
}
```
## n皇后问题
### 方法1：$O(2^{n^2})$
```cpp
#include<iostream>
#include<cstdio>
using namespace std;
const int N = 20;
int n;
bool g[N][N];
bool row[N], col[N], dg[N], udg[N];
void dfs(int x, int y, int s)
{
	if (y == n)
		y = 0, ++x;
	if (x == n)
	{
		if (s == n)
		{
			for (int i = 0 ; i < n ; i++)
			{
				for (int j = 0 ; j < n ; j++)
					printf("%c", g[i][j] ? 'Q' : '.');
				printf("\n");
			}
			printf("\n");
		}
		return;
	}
	// 不放
	dfs(x, y + 1, s);
	// 放
	if (!row[x] && !col[y] && !dg[x + y] && !udg[x - y + n])
	{
		g[x][y] = 1;
		row[x] = col[y] = dg[x + y] = udg[x - y + n] = 1;
		dfs(x, y + 1, s + 1);
		row[x] = col[y] = dg[x + y] = udg[x - y + n] = 0;
		g[x][y] = 0;
	}
}
int main()
{
	scanf("%d", &n);
	dfs(0, 0, 0);
	return 0;
}
```
### 方法2：$O(n!)$
```cpp
#include<iostream>
#include<cstdio>
using namespace std;
const int N = 20;
int n;
bool g[N][N];
bool col[N], dg[N], udg[N];
void dfs(int u)
{
	if (u == n)
	{
		for (int i = 0 ; i < n ; i++)
		{
			for (int j = 0 ; j < n ; j++)
				printf("%c", g[i][j] ? 'Q' : '.');
			printf("\n");
		}
		printf("\n");
		return;
	}
	for (int i = 0 ; i < n ; i++)
		if (!col[i] && !dg[u + i] && !udg[n - u + i])
		{
			g[u][i] = 1;
			col[i] = dg[u + i] = udg[n - u + i] = true;
			dfs(u + 1);
			col[i] = dg[u + i] = udg[n - u + i] = false;
			g[u][i] = 0;
		}
}
int main()
{
	scanf("%d", &n);
	dfs(0);
	return 0;
}
```