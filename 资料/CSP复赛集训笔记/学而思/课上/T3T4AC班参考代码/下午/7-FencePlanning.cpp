#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 1e5 + 5;
int n, m, x[N], y[N], lx, ly, rx, ry, ans = 1e9;
vector<int> v[N];
bool vis[N];
void dfs(int u)
{
	vis[u] = 1;
	lx = min(lx, x[u]);
	rx = max(rx, x[u]);
	ly = min(ly, y[u]);
	ry = max(ry, y[u]);
	for(int i = 0; i < v[u].size(); i++)
		if(!vis[v[u][i]])
			dfs(v[u][i]);
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%d%d", &x[i], &y[i]);
	for(int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i = 1; i <= n; i++)
		if(!vis[i])
		{
			lx = ly = 1e9;
			rx = ry = -1e9;
			dfs(i);
			ans = min(ans, (rx - lx) + (ry - ly));
		}
	printf("%d\n", ans * 2);
	return 0;
}
