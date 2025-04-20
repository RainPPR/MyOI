#include <cstdio>

int main()
{
	long long n, k;
	scanf("%lld %lld", &n, &k);

	long long a;

	long long min_left = -1, min_i = 0, min_need = 0;
	for (int i = 1 ; i <= k ; ++i)
	{
		scanf("%lld", &a);

		long long left = n % a;
		long long need = n / a;
		if (min_left == -1 || left < min_left)
			min_left = left, min_i = i, min_need = need;
	}

	printf("%lld %lld", min_i, min_need);
	return 0;
}
