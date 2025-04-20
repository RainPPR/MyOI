#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;
const int N = 610;

int MAX(const int x, const int y)
{
	return (x > y) ? x : y;
}

struct point
{
	int x, y;
	bool operator < (const point b) const
	{
		return (x == b.x) ? (y < b.y) : (x < b.x);
	}
} ;

point pos[N];
map<point, int> dp;

int main()
{
	freopen("point.in", "r", stdin);
	freopen("point.out", "w", stdout);

	int n, k, x, y, ans = -1;
	scanf("%d %d", &n, &k);
	for (int i = 0 ; i < n ; ++i)
	{
		scanf("%d %d", &x, &y);
		pos[i] = {x, y};
	}
	sort(pos, pos + n);
	for (int i = 0 ; i < n ; ++i)
	{
		x = pos[i].x, y = pos[i].y;
		dp[{x + 1, y}] = MAX(dp[{x + 1, y}], dp[pos[i]] + 1);
		ans = MAX(ans, dp[{x + 1, y}]);
		dp[{x, y + 1}] = MAX(dp[{x, y + 1}], dp[pos[i]] + 1);
		ans = MAX(ans, dp[{x, y + 1}]);
	}
	printf("%d\n", ans);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
