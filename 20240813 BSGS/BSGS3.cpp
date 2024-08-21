// Source: 洛谷
// Problem: P3846 [TJOI2007] 可爱的质数/【模板】BSGS
// Algorithm: BSGS
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// Author: RainPPR
// Datetime: 2024-08-13 19:54

#ifndef M_DEBUG
#define NDEBUG 1
#define FAST_IO 1

#define D(x) ({ void(0); })
#else
#define D(x) ({ auto t = (x); cerr << "| DEBUG #" << __LINE__ << " IN " << __FUNCTION__ << "() \t| \t" << #x << " = \t[" << t << "]\n"; void(0); })
#endif

#include <bits/stdc++.h>

#ifdef FAST_IO
#define endl "\n"
#endif

using namespace std;

// -----------------------------------------------------------------------------

using ll = long long;

ll qpow(ll a, ll b, ll p) {
	ll r = 1;
	for (; b; b >>= 1) {
		if (b & 1)
			r = (__int128)r * a % p;
		a = (__int128)a * a % p;
	}
	return r % p;
}

ll bsgs(ll a, ll b, ll p) {
	a %= p;
	b %= p;
	if (b == 1)
		return 0;
	ll m = ceil(sqrtl(p)), r;
	unordered_map<ll, int> bucket;
	r = b;
	for (int B = 0; B < m; ++B) {
		bucket[r] = B;
		r = (__int128)r * a % p;
	}
	ll am = qpow(a, m, p);
	r = 1;
	for (int A = 1; A <= m; ++A) {
		r = (__int128)r * am % p;
		if (bucket.count(r))
			return A * m - bucket[r];
	}
	return -1;
}

void Main() {
	ll a, b, p;
	cin >> p >> a >> b;
	ll r = bsgs(a, b, p);
	if (r == -1)
		puts("no solution");
	else
		cout << r << endl;
	return;
}

// -----------------------------------------------------------------------------

signed main() {
#ifdef FAST_IO
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
#endif
	Main();
	return 0;
}
