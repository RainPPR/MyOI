#include <bits/stdc++.h>

using namespace std;

#define int ll
#define rep(i, l, r) for (decltype(r) i = l; i <= r; ++i)

using ll = long long;

constexpr int N = 2e5 + 10;

int n, c, h[N];
int q[N], f[N];

inline int X(int j) { return h[j]; }
inline int Y(int j) { return f[j] + h[j] * h[j]; }
inline double K(int i, int j) { return 1.0 * (Y(j) - Y(i)) / (X(j) - X(i)); }
inline int V(int i, int j) { return f[j] + (h[i] - h[j]) * (h[i] - h[j]) + c; }

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> c; rep (i, 1, n) cin >> h[i];
	int st = 0, ed = 1;
	q[ed++] = 1, f[1] = 0;
	rep (i, 2, n) {
		while (st + 1 < ed && K(q[st], q[st + 1]) <= 2.0 * h[i]) ++st;
		f[i] = V(i, q[st]);
		while (st + 1 < ed && K(q[ed - 2], q[ed - 1]) >= K(q[ed - 1], i)) --ed;
		q[ed++] = i;
	} cout << f[n] << endl;
	return 0;
}
