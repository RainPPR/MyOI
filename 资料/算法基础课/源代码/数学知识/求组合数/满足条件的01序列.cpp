#include <cstdio>

using namespace std;

const int N = 200010;
const int MOD = 1e9 + 7;
int n;
int fact[N], infact[N];

int quick_pow(int a, int k)
{
	int res = 1;
	while (k)
	{
		if (k & 1)
			res = (long long)res * a % MOD;
		a = (long long)a * a % MOD;
		k >>= 1;
	}
	return res;
}

int main()
{
	fact[0] = infact[0] = 1;
	for (int i = 1; i < N; i++)
	{
		fact[i] = (long long)fact[i - 1] * i % MOD;
		infact[i] = (long long)infact[i - 1] * quick_pow(i, MOD - 2) % MOD;
	}

	scanf("%d", &n);
	int res = (long long)fact[2 * n] * infact[n] % MOD * infact[n] % MOD * quick_pow(n + 1, MOD - 2) % MOD;
	printf("%d\n", res);

	return 0;
}
