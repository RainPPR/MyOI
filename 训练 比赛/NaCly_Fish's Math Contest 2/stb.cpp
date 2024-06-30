/*
s[0] = 1;
for (int i = 1; i <= n; ++i) s[i] = s[i - 1] * a[i] % p;
sv[n] = qpow(s[n], p - 2, p);
for (int i = n; i >= 1; --i) sv[i - 1] = sv[i] * a[i] % p;
for (int i = 1; i <= n; ++i) inv[i] = sv[i] * s[i - 1] % p;
-----------------------------------------------------------
s[0] = 1;
for (int i = 1; i <= n; ++i) s[i] = s[i - 1] * i % p;
sv[n] = qpow(s[n], p - 2, p);
for (int i = n; i >= 1; --i) sv[i - 1] = sv[i] * i % p;
for (int i = 1; i <= n; ++i) inv[i] = sv[i] * s[i - 1] % p;
*/
/*
ll comb(ll n, ll m, ll p) { return s[n] * sv[m] % p * sv[n - m] % p; }
ll comb2(ll a, ll b, ll p) {
    ll r = 1;
    for (ll i = a, j = 1; j <= b; --i, ++j) r = r * i % p * qpow(j, p - 2, p) % p;
    return r;
}
ll lucas(ll a, ll b, const ll p) {
    ll r = 1;
    while (a >= p || b >= p) r = r * comb2(a % p, b % p, p) % p, a /= p, b /= p;
    return r * comb2(a, b, p) % p;
}
*/
/*
const int N = 1e6 + 10;
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
*/
/*
int primes[N], cnt;
bool is[N];

int phi[N];
int get_phi(int n) {
    phi[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (!is[i]) primes[++cnt] = i, phi[i] = i - 1;
        for (int j = 0; primes[j] <= n / i; ++j) {
            is[primes[j] * i] = 1;
            if (i % primes[j]) phi[primes[j] * i] = phi[i] * (primes[j] - 1);
            else {
                phi[primes[j] * i] = phi[i] * primes[j];
                break;
            }
        }
    }
}
*/