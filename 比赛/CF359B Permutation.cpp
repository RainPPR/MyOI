#include <cstdio>

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 1 ; i <= k ; ++i)
		printf("%d %d ", i * 2, i * 2 - 1);
	for (int i = k + 1 ; i <= n ; ++i)
		printf("%d %d ", i * 2 - 1, i * 2);

	return 0;
}
