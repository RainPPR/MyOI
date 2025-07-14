#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

const int N = 110;

struct point
{
	int x, y;

	point()
	{
		x = 0, y = 0;
	}
	point(const int &_x, const int &_y)
	{
		x = _x;
		y = _y;
	}

	bool operator == (const point &b) const
	{
		return (this->x == b.x && this->y == b.y);
	}
};

char mp[N][N];
int ans[N][N];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	point s, g;
	scanf("%d %d", &s.x, &s.y);
	scanf("%d %d", &g.x, &g.y);

	for (int i = 1 ; i <= n ; ++i)
		scanf("%s", mp[i] + 1);

	ans[s.x][s.y] = 1;
	queue<point> q;
	q.emplace(s);

	int tx, ty;
	while (q.size())
	{
		point now = q.front();
		q.pop();

		if (now == g)
			break;

		for (int i = 0 ; i < 4 ; ++i)
		{
			tx = now.x + dx[i];
			ty = now.y + dy[i];
			if (mp[tx][ty] == '.' && ans[tx][ty] == 0)
			{
				ans[tx][ty] = ans[now.x][now.y] + 1;
				q.emplace(tx, ty);
			}
		}
	}

	printf("%d\n", ans[g.x][g.y] - 1);
	return 0;
}
