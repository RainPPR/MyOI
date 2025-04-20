#include <cstdio>

using namespace std;

const int N = 1e5 + 10;

int n;
int p[N];

int c[N], ct[N];
bool check()
{
	for (int i = 1 ; i <= n ; ++i)
		if (c[i] != i)
			return false;
	return true;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1 ; i <= n ; ++i)
	{
		scanf("%d", p + i);
		c[i] = i;
	}

	long long ans = 0;
	do
	{
		for (int i = 1 ; i <= n ; ++i)
			ct[p[i]] = c[i];

		for (int i = 1 ; i <= n ; ++i)
			c[i] = ct[i];

		++ans;
	} while (!check());

	for (int i = 1 ; i <= n ; ++i)
		printf("%lld ", ans);

	return 0;
}
