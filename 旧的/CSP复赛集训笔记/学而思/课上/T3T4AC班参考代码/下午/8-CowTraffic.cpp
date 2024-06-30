#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1005;
int n, m, g[N][N], h[N][N], d[N], f[N], ans;
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		g[x][y]++;
		h[y][x]++;
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j < i; j++)
			d[i] += d[j] * g[j][i];
		if(d[i] == 0) d[i] = 1;
	}
	for(int i = n; i >= 1; i--)
	{
		for(int j = i+1; j <= n; j++)
			f[i] += f[j] * h[j][i];
		if(i == n) f[i] = 1;
	}
	for(int i = 1; i <= n; i++)
		for(int j = i+1; j <= n; j++)
			if(g[i][j])
				ans = max(ans, d[i] * f[j]);
	printf("%d\n", ans);
	return 0;
}
