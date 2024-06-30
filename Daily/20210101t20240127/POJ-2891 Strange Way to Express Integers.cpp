#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

#define ll long long
#define ull unsigned long long
#define db double
#define ld long double

#define gcd(a, b) __gcd(a, b)

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) return (x = 1, y = 0, a);
    ll d = exgcd(b, a % b, y, x);
    return (y -= a / b * x, d);
}

ll mod(ll a, ll m) {
    return (a % m + m) % m;
}

ll solev(int n) {
    ll m1, a1; cin >> m1 >> a1;
	for (int i = 0; i < n - 1; ++i) {
        ll m2, a2, x, y; cin >> m2 >> a2;
		ll d = exgcd(m1, m2, x, y), m = m1 / d * m2;
		if ((a2 - a1) % d) { for (++i; i < n - 1; ++i) cin >> m2 >> a2; return -1; }
        a1 = mod((a2 - a1) / d * x, m2 / d) * m1 + a1, m1 = m;
	} return mod(a1, m1);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
	int n; while (cin >> n) cout << solev(n) << endl;
	return 0;
}
