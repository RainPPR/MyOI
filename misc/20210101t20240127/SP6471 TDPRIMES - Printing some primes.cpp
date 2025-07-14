#include <cstdio>

using namespace std;

const int M = 1e8;
const int N = 1e8 + 10;

int primes[N], cnt;
bool st[N];
void get_primes(int n)
{
	for (int i = 2; i <= n; ++i)
	{
		if (!st[i])
			primes[cnt++] = i;
		for (int j = 0 ; primes[j] <= n / i ; ++j)
		{
			st[primes[j] * i] = true;
			if (i % primes[j] == 0)
				break;
		}
	}
}

int main()
{
	get_primes(M);

	for (int i = 1 ; primes[i] < M ; i += 100)
		printf("%d\n", primes[i]);

	return 0;
}
