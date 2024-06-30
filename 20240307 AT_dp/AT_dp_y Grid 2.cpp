#include <bits/stdc++.h>

using namespace std;

#define range(x) x.begin(), x.end()
#define rep(i, l, r) for (decltype(r) i = l; i <= r; ++i)
#define per(i, r, l) for (decltype(l) i = r; i >= l; --i)

using ll = long long;

constexpr int mod = 1e9 + 7;
constexpr int Q = 2e5 + 10;

int h, w, n;

struct point {
	int x, y;
	point() = default;
	point(int x, int y): x(x), y(y) { }
	friend bool operator <(const point &a, const point &b) { return a.x == b.x ? a.y < b.y : a.x < b.x; }
};

vector<point> a;

int s[Q], sv[Q], inv[Q];

inline int qpow(int a, int b) {
	int r = 1; for (; b; b >>= 1) {
		if (b & 1) r = 1ll * r * a % mod;
		a = 1ll * a * a % mod;
	} return r;
}

void init() {
	int q = h + w; s[0] = 1;
	rep (i, 1, q) s[i] = 1ll * s[i - 1] * i % mod;
	sv[q] = qpow(s[q], mod - 2);
	per (i, q, 1) sv[i - 1] = 1ll * sv[i] * i % mod;
	rep (i, 1, q) inv[i] = 1ll * sv[i] * s[i - 1] % mod;
}

inline int comb(int n, int m) { return 1ll * s[n] * sv[m] % mod * sv[n - m] % mod; }
inline int g(point a) { return comb(a.x + a.y - 2, a.x - 1); }
inline int g(point a, point b) { return comb(b.x - a.x + b.y - a.y, b.x - a.x); }

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> h >> w >> n; a.resize(n + 1);
	init(); a[0] = point(h, w);
	rep (i, 1, n) cin >> a[i].x >> a[i].y;
	sort(range(a)); vector<int> f(n + 1);
	rep (i, 0, n) { f[i] = g(a[i]);
		rep (j, 0, i - 1) if (a[j].y <= a[i].y)
		f[i] = (f[i] - 1ll * f[j] * g(a[j], a[i]) % mod + mod) % mod;
	} cout << f[n] << endl;
	return 0;
}
