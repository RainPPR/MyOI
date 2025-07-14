/*
  归来且做云梦梦一场 大梦好
  栽花闻酒香 醒醒醉醉笑笑
  天地偌大复路远山高 最难得偷半日逍遥
  偶尔糊涂不问世事不知晓

  ——银临 & 慕寒《云梦谣》
 */
#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

const int N = 3010;
const int dx[4] = {-1, 0, 0, +1};
const int dy[4] = {0, -1, +1, 0};

int n, m, k;
int h[N][N];
bool f[N][N];
bool visit[N][N];
int max_h = -2e9;

typedef struct
{
	int x, y;
} point;
vector<point> fly;

bool cmp(point a, point b)
{
	return h[a.x][a.y] < h[b.x][b.y];
}

int ans = 2e9;
void dfs(point now, int steps)
{
	if (now.x == n && now.y == m)
	{
		ans = (steps < ans) ? steps : ans;
		return ;
	}
	// 上下左右
	for (int i = 0 ; i < 4 ; ++i)
	{
		int tx = now.x + dx[i];
		int ty = now.y + dy[i];
		if (!visit[tx][ty] && h[tx][ty])
		{
			visit[tx][ty] = true;
			dfs({tx, ty}, steps + 1);
			visit[tx][ty] = false;
		}
	}
	// 御剑飞行
	if (f[now.x][now.y])
	{
		for (point i : fly)
		{
			if (h[i.x][i.y] >= h[now.x][now.y])
			{
				if (!visit[i.x][i.y] && h[i.x][i.y] == h[now.x][now.y])
				{
					visit[i.x][i.y] = true;
					dfs({i.x, i.y}, steps + 1);
					visit[i.x][i.y] = false;
				}
				else
				{
					break;
				}
			}
		}
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1 ; i <= n ; ++i)
	{
		for (int j = 1 ; j <= m ; ++j)
		{
			scanf("%d", h[i] + j);
			max_h = (h[i][j] > max_h) ? h[i][j] : max_h;
		}
	}

	int x, y;
	while (k--)
	{
		scanf("%d %d", &x, &y);
		f[x][y] = 1;
		fly.push_back({x, y});
	}
	sort(fly.begin(), fly.end(), cmp);
	visit[1][1] = true;
	dfs({1, 1}, 0);

	if (ans == 2e9)
		ans = -1;
	printf("%d", ans);
	return 0;
}
