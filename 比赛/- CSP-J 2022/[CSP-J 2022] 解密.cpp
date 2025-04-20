#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	freopen("decode.in", "r", stdin);
	freopen("decode.out", "w", stdout);

	long long n, d, e, sq, pp, qq;
	int k, m;
	double p, q;

	scanf("%d", &k);
	while (k--)
	{
		scanf("%lld %lld %lld", &n, &d, &e);
		m = n - (long long)e * d + 2;
		sq = (long long)m * m - n * 4;
		if (sq < 0)
		{
			printf("NO\n");
			continue;
		}
		pp = p = (m + sqrt(sq)) / 2;
		qq = q = m - p;
		if (pp != p)
		{
			printf("NO\n");
			continue;
		}
		if (qq != q)
		{
			printf("NO\n");
			continue;
		}
		printf("%lld %lld\n", qq, pp);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
