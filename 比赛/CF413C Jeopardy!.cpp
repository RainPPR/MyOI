#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 110;

int point[N];
int times[N];

int a[N];

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1 ; i <= n ; ++i)
		scanf("%d", point + i);

	for (int i = 1 ; i <= m ; ++i)
	{
		scanf("%d", a + i);
		times[i] = point[a[i]];
	}

	sort(a + 1, a + 1 + m);

	for (int i = 1, j = 1, k = 1 ; i <= n ; ++i)
		if (a[k] == i)
			++k;
		else
			point[j++] = point[i];
	n -= m;

	long long ans = 0;
	for (int i = 1 ; i <= n ; ++i)
		ans += point[i];

	sort(times + 1, times + 1 + m, cmp);

	for (int i = 1 ; i <= m ; ++i)
		if (times[i] > ans)
			ans += times[i];
		else
			ans <<= 1;

	printf("%lld", ans);
	return 0;
}
