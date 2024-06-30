#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 55;
int n, m, cnt, dis[5][5], f[N][N][5], p[N][N];
char a[N][N];
bool vis[N][N];
void dfs(int x, int y, int id)
{
	if(vis[x][y] || a[x][y] != 'X') return;
	vis[x][y] = 1;
	p[x][y] = id;
	if(x > 1) dfs(x-1, y, id);
	if(x < n) dfs(x+1, y, id);
	if(y > 1) dfs(x, y-1, id);
	if(y < m) dfs(x, y+1, id);
}
int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> a[i][j];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(a[i][j] == 'X' && !vis[i][j])
				dfs(i, j, ++cnt);
	memset(dis, 0x3f, sizeof(dis));
	memset(f, 0x3f, sizeof(f));
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			for(int k = 1; k <= n; k++)
				for(int l = 1; l <= m; l++)
				{
					if(p[i][j] == p[k][l]) continue;
					if(p[i][j] == 0)
						f[i][j][p[k][l]] = min(f[i][j][p[k][l]], abs(i - k) + abs(j - l));
					else dis[p[i][j]][p[k][l]] = min(dis[p[i][j]][p[k][l]], abs(i - k) + abs(j - l));
				}
	int ans = min(dis[1][2] + dis[2][3], min(dis[1][3] + dis[3][2], dis[2][1] + dis[1][3])) - 2; //两两相连
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(p[i][j] == 0) //在某个点合并
				ans = min(ans, f[i][j][1] + f[i][j][2] + f[i][j][3] - 2);
	printf("%d\n", ans);
	return 0;
}
