#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ill;
typedef __int128 ll;

ll exgcd(ll a, ll b, ll &x, ll &y)
{
	if (!b)
	{
		x = 1, y = 0;
		return a;
	}
	
	ll d = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return d;
}

int main()
{
	int n;
	scanf("%d", &n);
	
	ill m1t, a1t, m2t, a2t;
	ll x = 0, m1, a1, m2, a2, k1, k2;
	scanf("%lld %lld", &m1t, &a1t);
	m1 = m1t, a1 = a1t;
	for (int i = 0; i < n - 1; i ++)
	{
		scanf("%lld %lld", &m2t, &a2t);
		m2 = m2t, a2 = a2t;
		ll d = exgcd(m1, m2, k1, k2);
		if ((a2 - a1) % d)
		{
			x = -1;
			break;
		}
		
		k1 *= (a2 - a1) / d;
		k1 = (k1 % (m2 / d) + m2 / d) % (m2 / d);
		
		x = k1 * m1 + a1;
		
		ll m = abs(ill(m1 / d * m2));
		a1 = k1 * m1 + a1;
		m1 = m;
	}
	
	if (x != -1)
		x = (a1 % m1 + m1) % m1;
	
	ill xx = x;
	printf("%lld\n", xx);
	
	return 0;
}
