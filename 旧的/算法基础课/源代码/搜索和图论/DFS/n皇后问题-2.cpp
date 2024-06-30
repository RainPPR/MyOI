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
	// ²»·Å
	dfs(x, y + 1, s);
	// ·Å
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
