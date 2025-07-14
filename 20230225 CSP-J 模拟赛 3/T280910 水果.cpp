#include <cstdio>
#include <cmath>

using namespace std;

typedef long long ll;

int main()
{
	ll n, c = 1, k;
	scanf("%lld %lld", &n, &k);

	ll d, cnt = 0;
	while (n > 0)
	{
		d = ceil(n / (k * 2.0));
		n -= d * k;
		cnt += c * d;
		c <<= 1;
	}

	printf("%lld", cnt);
	return 0;
}
