#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int INF = 2100000000;
int a[20][20], s[20], p[20], ans = INF;
int f[20][20], w[20][20], n, m, r, c;
void work()
{
	//f[i][j] - 已经选了i列，最后一列是j的最小分值
	memset(f, 0x3f, sizeof(f));
	memset(w, 0, sizeof(w));
	for(int i = 1; i <= m; i++) //计算每一列内部的分值
	{
		f[1][i] = 0;
		for(int j = 1; j < r; j++)
			f[1][i] += abs(a[p[j]][i] - a[p[j+1]][i]);
	}
	for(int i = 1; i < m; i++)
		for(int j = i+1; j <= m; j++)
			for(int k = 1; k <= r; k++) //计算任意两列相邻时的分值
				w[i][j] += abs(a[p[k]][i] - a[p[k]][j]);
	for(int i = 2; i <= c; i++)
		for(int j = 1; j <= m; j++)
			for(int k = 1; k < j; k++) //线性DP
				f[i][j] = min(f[i][j], f[i-1][k] + f[1][j] + w[k][j]);
	for(int i = c; i <= m; i++)
		ans = min(ans, f[c][i]);
}
void dfs(int dep, int x) //从n行中枚举出r行
{
	if(x > n || r - dep > n - x) return;
	if(dep == r)
	{
		work();
		return;
	}
	p[dep + 1] = x + 1;
	dfs(dep + 1, x + 1);
	p[dep + 1] = 0;
	dfs(dep, x + 1);
}
int main()
{
	cin >> n >> m >> r >> c;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> a[i][j];
	dfs(0, 0);
	cout << ans << endl;
	return 0;
}
