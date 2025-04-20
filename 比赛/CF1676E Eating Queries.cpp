#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1.5e5 + 10;

int a[N];
int s[N];

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	int T;
	scanf("%d", &T);

	int n, q, x;
	int l, r, mid;
	while (T--)
	{
		scanf("%d %d", &n, &q);
		for (int i = 1 ; i <= n ; ++i)
			scanf("%d", a + i);

		sort(a + 1, a + 1 + n, cmp);

		for (int i = 1 ; i <= n ; ++i)
			s[i] = a[i] + s[i - 1];
		s[n + 1] = 2e9;

		while (q--)
		{
			scanf("%d", &x);

			l = 1, r = n + 1;
			while (l < r)
			{
				mid = (l + r) >> 1;
				if (s[mid] < x)
					l = mid + 1;
				else
					r = mid;
			}

			printf("%d\n", (l == n + 1) ? -1 : l);
		}
	}
	return 0;
}
