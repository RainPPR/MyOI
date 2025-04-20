#include <cstdio>

using namespace std;

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	int all = 0;

	int i = 1;
	int a, left = 0;
	for (i = 1 ; (i <= n) && (i <= k) ; ++i)
	{
		scanf("%d", &a);

		a += left, left = 0;
		if (a > 8)
			left += a - 8, a = 8;
		all += a;

		if (all >= k)
		{
			printf("%d\n", i);
			return 0;
		}
	}

	printf("-1\n");
	return 0;
}
