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
