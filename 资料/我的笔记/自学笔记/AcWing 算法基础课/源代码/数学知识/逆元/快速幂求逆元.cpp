#include <cstdio>

using namespace std;
typedef long long ll;

ll quick_pow(int a, int k, int p)
{
	ll res = 1;
	while (k)
	{
		if (k & 1)
			res = (ll)res * a % p;
		k >>= 1;
		a = (ll)a * a % p;
	}
	return res;
}

int main()
{
	int n, a, p;
	scanf("%d", &n);

	while (n--)
	{
		scanf("%d %d", &a, &p);
		ll res = quick_pow(a, p - 2, p);
		if (a % p)
			printf("%lld\n", res);
		else
			printf("impossible\n");
	}
	return 0;
}
