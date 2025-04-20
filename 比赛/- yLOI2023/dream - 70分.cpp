#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

const int N = 3010;
const int dx[4] = {-1, 0, 0, +1};
const int dy[4] = {0, -1, +1, 0};

int n, m, k;
int h[N][N];
bool f[N][N];
vector<pii> jump;

// BFS
namespace Solve4
{
	int ans[N][N];

	bool init()
	{
		for (int i = 1 ; i <= n ; ++i)
			for (int j = 1 ; j <= m ; ++j)
				ans[i][j] = 2e9;
		ans[1][1] = 0;
		return true;
	}

	int Main()
	{
		init();
		queue<pii> q;
		q.push({1, 1});
		int x, y;
		int tx, ty;
		while (q.size())
		{
			pii st = q.front();
			x = st.first, y = st.second;
			if (x == n && y == m)
				break;
			q.pop();
			// ËÄÏò
			for (int i = 0 ; i < 4 ; ++i)
			{
				tx = x + dx[i];
				ty = y + dy[i];
				if (h[tx][ty] && (ans[tx][ty] > ans[x][y] + 1))
				{
					ans[tx][ty] = ans[x][y] + 1;
					q.push({tx, ty});
				}
			}
			// ÌøÔ¾
			if (f[x][y])
			{
				for (pii i : jump)
				{
					int tx = i.first;
					int ty = i.second;
					if ((h[x][y] == h[tx][ty]) && (ans[tx][ty] > ans[x][y] + 1))
					{
						ans[tx][ty] = ans[x][y] + 1;
						q.push({tx, ty});
					}
					else if (h[tx][ty] && (h[x][y] != h[tx][ty]) && (ans[tx][ty] > ans[x][y] + 2))
					{
						ans[tx][ty] = ans[x][y] + 2;
						q.push({tx, ty});
					}
				}
			}
		}
		if (ans[n][m] == 2e9)
			return -1;
		return ans[n][m];
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1 ; i <= n ; ++i)
		for (int j = 1 ; j <= m ; ++j)
			scanf("%d", h[i] + j);
	while (k--)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		f[x][y] = 1;
		jump.push_back({x, y});
	}

	int ans = Solve4::Main();
	printf("%d", ans);
	return 0;
}
