#include <cstdio>

using namespace std;

int main()
{
	int T, n, x;
	scanf("%d", &T);

	while (T--)
	{
		scanf("%d", &n);

		long long ans = 0;
		for (int i = 1 ; i <= n ; ++i)
		{
			scanf("%d", &x);
			ans += (2 * i - n - 1) * x;
		}

		printf("%lld\n", ans);
	}
	return 0;
}
