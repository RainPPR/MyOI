#include <cstdio>

using namespace std;

const int N = 20;

struct
{
	long long m, a;
	long long mul;
} tef[N];

long long ex_gcd(long long a, long long b, long long &x, long long &y)
{
	if (!b)
	{
		x = 1, y = 0;
		return a;
	}
	int d = ex_gcd(b, a % b, y, x);
	y -= a / b * x;
	return d;
}

int main()
{
	int n;
	scanf("%d", &n);

	long long mul = 1;
	for (int i = 0 ; i < n ; ++i)
	{
		scanf("%lld %lld", &tef[i].m, &tef[i].a);
		mul *= tef[i].m;
	}

	long long ans = 0;
	for (int i = 0 ; i < n ; ++i)
	{
		tef[i].mul = mul / tef[i].m;

		long long x = 0, y = 0;
		ex_gcd(tef[i].mul, tef[i].m, x, y);
		if (x < 0)
			x += tef[i].m;

		ans += tef[i].a * tef[i].mul * x;
	}

	printf("%lld\n", ans % mul);

	return 0;
}
