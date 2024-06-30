# Floyd

求多元汇最短路
基于动态规划
复杂度：O(n^3)

## 思路
1. 用邻接矩阵存储
$d[i,j]$存储所有的边
2. 三重循环：
$\text{for }k : 1 \sim n$
$\text{for }i : 1 \sim n$
$\text{for }j : 1 \sim n$
$d[i,j]=min(d[i,j],d[i,k]+d[k,j]);$

## 原理
$d[k,i,j]=d[k-1,i,k]+d[k-1,k,j]$
动态规划降维就OK

## 代码
代码比较简单，没写注释
```cpp
#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 210, INF = 1e9;

int n, m, Q;
int d[N][N];	// 邻接矩阵

void floyd()
{
	for (int k = 1 ; k <= n ; ++k)
		for (int i = 1 ; i <= n ; ++i)
			for (int j = 1 ; j <= n ; ++j)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main()
{
	scanf("%d %d %d", &n, &m, &Q);
	
	for (int i = 1 ; i <= n ; ++i)
		for (int j = 1 ; j <= n ; ++j)
			if (i == j)
				d[i][j] = 0;
	else
		d[i][j] = INF;
	
	int a, b, w;
	while (m--)
	{
		scanf("%d %d %d", &a, &b, &w);
		d[a][b] = min(d[a][b], w);
	}
	
	floyd();
	
	while (Q--)
	{
		scanf("%d %d", &a, &b);
		int t = d[a][b];
		if (t > INF / 2)
			printf("impossible\n");
		else
			printf("%d\n", d[a][b]);
	}
	return 0;
}
```