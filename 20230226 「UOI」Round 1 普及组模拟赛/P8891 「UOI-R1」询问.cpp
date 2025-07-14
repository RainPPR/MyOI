#include <cstdio>

using namespace std;

const int N = 1e6 + 10;

int n, m;
long long a[N];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1 ; i <= n ; ++i)
		scanf("%lld", a + i);

	int x, y;
	for (int i = 1 ; i <= m ; ++i)
	{
		scanf("%d %d", &x, &y);
		if ((x >= 1) && (x <= n))
			a[x] -= y;
	}

	for (int i = 1 ; i <= n ; ++i)
		printf("%lld ", a[i]);
	return 0;
}
