#include <cstdio>
#include <cmath>

using namespace std;

const double INF = 2e9;
const int N = 1e5 + 10;

inline double MIN(const double a, const double b)
{
	return (a < b) ? a : b;
}
inline double MAX(const double a, const double b)
{
	return (a > b) ? a : b;
}

int n, m;
int a[N];

int main()
{
	scanf("%d %d", &n, &m);

	double l_ans = -INF, r_ans = INF;
	double l, r;
	for (int i = 1 ; i <= n ; ++i)
	{
		scanf("%d", a + i);

		l = (double)m / i / a[i];
		r = (double)m / i / (a[i] - 1);
		l_ans = MAX(l_ans, l);
		r_ans = MIN(r_ans, r);
	}

	if (r_ans == INF)
		printf("xiaogougege");
	else
	{
		long long ans = 0;
		for (long long i = ceil(l_ans) ; i < r_ans ; ++i)
			++ans;
		printf("%lld", ans);
	}

	return 0;
}
