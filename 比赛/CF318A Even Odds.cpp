#include <cstdio>

using namespace std;

int main()
{
	long long n, k;
	scanf("%lld %lld", &n, &k);

	long long ji = (n + 1) / 2;
	if (k <= ji)
		printf("%lld\n", 2 * k - 1);
	else
		printf("%lld\n", (k - ji) * 2);

	return 0;
}
