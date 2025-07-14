#include <cstdio>

using namespace std;

typedef unsigned int ui;
typedef long long ll;

const int N = 1e5 + 10;

ui a[N];

int main()
{
	int T, n;
	ll k;
	ui x;

	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %lld", &n, &k);

		x = 0;
		for (int i = 0 ; i < n ; ++i)
		{
			scanf("%u", a + i);
			x ^= a[i];
		}

		if ((n & 1) || (k & 1))
			for (int i = 0 ; i < n ; ++i)
				printf("%u ", x ^ a[i]);
		else
			for (int i = 0 ; i < n ; ++i)
				printf("%u ", a[i]);

		putchar('\n');
	}

	return 0;
}
