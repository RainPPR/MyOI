#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 1e6 + 10;

int primes[N], cnt;
int phi[N];
bool st[N];

ll get_eulers(int n)

{
	phi[1] = 1;
	for (int i = 2 ; i <= n ; ++i)
	{
		if (!st[i])
		{
			primes[cnt++] = i;
			phi[i] = i - 1;
		}
		for (int j = 0 ; primes[j] <= n / i ; ++j)
		{
			st[primes[j] * i] = true;
			if (i % primes[j] == 0)
			{
				phi[i * primes[j]] = phi[i] * primes[j];
				break;
			}
			phi[primes[j] * i] = phi[i] * (primes[j] - 1);
		}
	}

	ll res = 0;
	for (int i = 1 ; i <= n ; ++i)
		res += phi[i];

	return res;
}

int main()
{
	int n;

	scanf("%d", &n);

	printf("%lld\n", get_eulers(n));

	return 0;
}
