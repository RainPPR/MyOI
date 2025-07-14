#include<cstdio>

using namespace std;

long long MIN(const long long &a, const long long &b)
{
	return (a < b) ? a : b;
}

long long n, m, k;

bool check(long long x)
{
	long long sum = 0;

	for (long long i = 1; i <= n; i++)
		sum += MIN(m, x / i);

	return sum >= k;
}
int main()
{
	scanf("%lld %lld %lld", &n, &m, &k);

	long long l = 1;
	long long r = n * m;

	while (l < r)
	{
		long long mid = (l + r) >> 1;
		if (check(mid))
			r = mid;
		else
			l = mid + 1;
	}

	printf("%lld", l);
	return 0;
}
