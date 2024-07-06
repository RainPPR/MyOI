#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 1e5 + 10;
int s, t, n;
struct Range
{
	int l, r;
	bool operator < (const Range &W) const
	{
		return l < W.l;
	}
} range[N];
int main()
{
	scanf("%d %d", &s, &t);
	scanf("%d", &n);
	for (int i = 0 ; i < n ; ++i)
		scanf("%d %d", &range[i].l, &range[i].r);
	sort(range, range + n);
	int res = 0, start = s;
	bool success = false;
	for (int i = 0 ; i < n ; ++i)
	{
		int j = i, r = -2e9;
		while ((j < n) && (range[j].l <= start))
			r = max(r, range[j++].r);
		if (r < start)
		{
			res = -1;
			break;
		}
		++res;
		if (r >= t)
		{
			success = true;
			break;
		}
		start = r;
		i = j - 1;
	}
	printf("%d\n", success ? res : -1);
	return 0;
}
