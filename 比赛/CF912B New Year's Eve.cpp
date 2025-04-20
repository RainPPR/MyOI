#include <cstdio>

using namespace std;

int main()
{
	long long n, k;
	scanf("%lld %lld", &n, &k);

	if (k == 1)
		printf("%lld", n);
	else
	{
		long long ans = 0;
		for (long long i = 0 ; n >> i ; i++)
			ans += (1LL << i);

		printf("%lld", ans);
	}
	return 0;
}
