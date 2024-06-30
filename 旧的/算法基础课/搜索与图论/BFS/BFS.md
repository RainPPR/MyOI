# BFS
最短路问题
## 八数码
```cpp
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
vector<int> getpos(int z)
{
	vector<int> pos;
	if (z > 2)
		pos.push_back(z - 3);
	if (z % 3 != 0)
		pos.push_back(z - 1);
	if (z % 3 != 2)
		pos.push_back(z + 1);
	if (z < 6)
		pos.push_back(z + 3);
	return pos;
}
int bfs(string start)
{
	string end = "12345678x";

	queue<string> q;
	unordered_map<string, int>d;

	q.push(start);
	d[start] = 0;

	while (!q.empty())
	{
		string t = q.front();
		q.pop();

		int dis = d[t];

		if (t == end)
			return dis;

		int k = t.find('x');
		auto pos = getpos(k);
		for (int i = 0 ; i < pos.size() ; ++i)
		{
			swap(t[k], t[pos[i]]);
			if (!d.count(t))
			{
				d[t] = dis + 1;
				q.push(t);
			}
			swap(t[k], t[pos[i]]);
		}
	}
	return -1;
}
int main()
{
	string str;
	for (int i = 0 ; i < 9 ; ++i)
	{
		char c = getc(stdin);
		getc(stdin);
		str += c;
	}
	printf("%d", bfs(str));
	return 0;
}
```
## 走迷宫
```cpp
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
```