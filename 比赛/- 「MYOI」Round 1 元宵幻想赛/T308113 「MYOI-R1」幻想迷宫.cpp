#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 11;
const int M = 1010;

char mp[N][M][M];
int ans[N][M][M];

int n, m;

struct point
{
	int s;
	int x, y;
	point()
	{
		s = 0;
		x = 0;
		y = 0;
	}
	point(int _s, int _x, int _y)
	{
		s = _s;
		x = _x;
		y = _y;
	}
};

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n ; ++i)
		for (int j = 1 ; j <= m ; ++j)
			scanf("%s", mp[i][j] + 1);

	for (int i = 1 ; i <= n ; ++i)
		for (int j = 1 ; j <= m ; ++j)
			for (int k = 1 ; k <= m ; ++k)
				ans[i][j][k] = 2e9;

	point target;

	queue <point> q;
	ans[1][1][1] = 0;
	q.push({1, 1, 1});
	while (q.size())
	{
		point now = q.front();
		q.pop();

		if (mp[now.s][now.x][now.y] == '@')
		{
			target = now;
			break;
		}

		if ((now.x + 1 <= m) && (mp[now.s][now.x + 1][now.y] != '*'))
		{
			if ((mp[now.s][now.x + 1][now.y] != '.') && (mp[now.s][now.x + 1][now.y] != '@'))
			{
				if (mp[int(mp[now.s][now.x + 1][now.y] - '0')][1][1] != '*')
				{
					if (ans[int(mp[now.s][now.x + 1][now.y] - '0')][1][1] > ans[now.s][now.x][now.y] + 1)
					{
						ans[int(mp[now.s][now.x + 1][now.y] - '0')][1][1] = ans[now.s][now.x][now.y] + 1;
						q.push({int(mp[now.s][now.x + 1][now.y] - '0'), 1, 1});
					}
				}
				else if (ans[now.s][now.x + 1][now.y] > ans[now.s][now.x][now.y] + 2)
				{
					ans[now.s][now.x + 1][now.y] = ans[now.s][now.x][now.y] + 2;
					q.push({now.s, now.x + 1, now.y});
				}
			}
			else if (ans[now.s][now.x + 1][now.y] > ans[now.s][now.x][now.y] + 1)
			{
				ans[now.s][now.x + 1][now.y] = ans[now.s][now.x][now.y] + 1;
				q.push({now.s, now.x + 1, now.y});
			}
		}

		if ((now.y + 1 <= m) && (mp[now.s][now.x][now.y + 1] != '*'))
		{
			if ((mp[now.s][now.x][now.y + 1] != '.') && (mp[now.s][now.x][now.y + 1] != '@'))
			{
				if (mp[int(mp[now.s][now.x][now.y + 1] - '0')][1][1] != '*')
				{
					if (ans[int(mp[now.s][now.x][now.y + 1] - '0')][1][1] > ans[now.s][now.x][now.y] + 1)
					{
						ans[int(mp[now.s][now.x][now.y + 1] - '0')][1][1] = ans[now.s][now.x][now.y] + 1;
						q.push({int(mp[now.s][now.x][now.y + 1] - '0'), 1, 1});
					}
				}
				else if (ans[now.s][now.x][now.y + 1] > ans[now.s][now.x][now.y] + 2)
				{
					ans[now.s][now.x][now.y + 1] = ans[now.s][now.x][now.y] + 2;
					q.push({now.s, now.x, now.y + 1});
				}
			}
			else if (ans[now.s][now.x][now.y + 1] > ans[now.s][now.x][now.y] + 1)
			{
				ans[now.s][now.x][now.y + 1] = ans[now.s][now.x][now.y] + 1;
				q.push({now.s, now.x, now.y + 1});
			}
		}
	}

	if (target.s)
		printf("%d\n", ans[target.s][target.x][target.y]);
	else
		printf("-1\n");
	return 0;
}
