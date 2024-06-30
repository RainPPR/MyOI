#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
typedef pair<int, int> PII;
const int N = 110;
int n, m;
int g[N][N];
int d[N][N];
PII pre[N][N];	//这一格从哪来
int bfs()
{
	queue<PII> q;
	q.push({0, 0});
	memset(d, -1, sizeof(d));
	d[0][0] = 0;
	int dx[4] = {-1, 0, 0, 1};
	int dy[4] = {0, -1, 1, 0};
	while (!q.empty())
	{
		PII t = q.front();
		q.pop();
		for (int i = 0 ; i < 4 ; ++i)
		{
			int x = t.first + dx[i], y = t.second + dy[i];
			if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1)
			{
				d[x][y] = d[t.first][t.second] + 1;
				pre[x][y] = t;
				q.push({x, y});
			}
		}
	}
	//输出路径
	int x = n - 1, y = m - 1;
	while (x || y)
	{
		cout << x << " " << y << endl;
		PII t = pre[x][y];
		x = t.first, y = t.second;
	}
	//
	return d[n - 1][m - 1];
}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0 ; i < n ; ++i)
		for (int j = 0 ; j < m ; j++)
			scanf("%d", g[i] + j);
	cout << bfs() << endl;
}
