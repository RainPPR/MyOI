#include <stdio.h>

int main()
{
	int t;
	scanf("%d", &t);

	for (int tc = 1; tc <= t; ++tc)
	{
		long long a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);

		long long sum_b = (b * (b + 1)) / 2;
		long long sum_c = (c * (c + 1)) / 2;

		long long result = a * (sum_b * sum_c);

		printf("Case %d: %lld\n", tc, result);
	}
	return 0;
}
