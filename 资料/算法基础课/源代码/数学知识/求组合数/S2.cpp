#include <cstdio>

typedef long long ll;
const int N = 100010, MOD = 1e9 + 7;

int fact[N], infact[N];

int qmi(int a, int k, int p)
{
	int res = 1;
	while (k)
	{
		if (k & 1)
			res = (ll)res * a % p;
		a = (ll)a * a % p;
		k >>= 1;
	}
	return res;
}

int main()
{
	fact[0] = infact[0] = 1;
	for (int i = 1 ; i < N ; ++i)
	{
		fact[i] = (ll)fact[i - 1] * i % MOD;
		infact[i] = (ll)infact[i - 1] * qmi(i, MOD - 2, MOD) % MOD;
	}
	int n, a, b;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d %d", &a, &b);
		printf("%lld\n", (ll)fact[a] * infact[b] % MOD * infact[a - b] % MOD);
	}
	return 0;
}
