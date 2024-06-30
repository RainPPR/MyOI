#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 310;
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};
int n, m;
int h[N][N];
int f[N][N];
int dp(int x, int y)
{
	if (f[x][y] != -1)
		return f[x][y];
	f[x][y] = 1;
	for (int i = 0 ; i < 4 ; ++i)
	{
		int tx = x + dx[i], ty = y + dy[i];
		if ((tx >= 1) && (tx <= n) && (ty >= 1) && (ty <= m) && (h[tx][ty] < h[x][y]))
			f[x][y] = max(f[x][y], dp(tx, ty) + 1);
	}
	return f[x][y];
}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1 ; i <= n ; ++i)
		for (int j = 1 ; j <= m ; ++j)
			scanf("%d", h[i] + j);
	memset(f, -1, sizeof(f));
	int res = 0;
	for (int i = 1 ; i <= n ; ++i)
		for (int j = 1 ; j <= m ; ++j)
			res = max(res, dp(i, j));
	printf("%d\n", res);
	return 0;
}
