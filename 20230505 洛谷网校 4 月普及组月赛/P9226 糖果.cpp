#include <cstdio>

using namespace std;

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	n = k - (n % k);

	printf("%d\n", n);
	return 0;
}
