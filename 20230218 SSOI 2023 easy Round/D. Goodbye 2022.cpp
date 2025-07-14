#include <cstdio>
#include <cmath>

int main()
{
	int n, k, p;
	scanf("%d %d %d", &n, &k, &p);
	long long ans = (long long)n * pow(p, k);
	printf("%lld\n", ans);
	return 0;
}
