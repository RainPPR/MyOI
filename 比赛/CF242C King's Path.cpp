#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

#define mt pair<int, int>
#define mk make_pair

using namespace std;

const int N = 6;
const int M = 11;

map<mt, int> fre, ans;

int main()
{
	int x, y, xx, yy;
	int n;

	scanf("%d %d %d %d", &x, &y, &xx, &yy);
	scanf("%d", &n);

	int r, a, b;
	for (int i = 0 ; i < n ; ++i)
	{
		scanf("%d %d %d", &r, &a, &b);
		for (int j = a ; j <= b ; ++j)
			fre[mk(r, j)] = 1;
	}

	queue<mt> q;
	q.push(mk(x, y));
	ans[mk(x, y)] = 1;

	while (q.size())
	{
		x = q.front().first, y = q.front().second;
		q.pop();

		if (x == xx && y == yy)
			break;

		for (int dx = -1 ; dx <= 1 ; ++dx)
		{
			for (int dy = -1 ; dy <= 1 ; ++dy)
			{
				int tx = x + dx, ty = y + dy;

				if ((fre.count(mk(tx, ty)) && fre[mk(tx, ty)] == 1) && (!ans.count(mk(tx, ty)) || ans[mk(x, y)] + 1 < ans[mk(tx, ty)]))
				{
					q.push(mk(tx, ty));
					ans[mk(tx, ty)] = ans[mk(x, y)] + 1;
//					printf("[%d, %d]: %d\n", tx, ty, ans[mk(tx, ty)]);
				}
			}
		}
	}

	printf("%d\n", ans[mk(xx, yy)] - 1);
	return 0;
}
