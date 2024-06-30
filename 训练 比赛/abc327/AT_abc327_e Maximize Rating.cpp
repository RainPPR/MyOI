#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define gor(i, l, r) for (int i = int(l); i < int(r); ++i)

#define rr read()
inline int read() {
    int num = 0, flag = 1, ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = num * 10 + ch - '0';
    return num * flag;
}

#define conet constexpr

using db = double;

conet int N = 5010;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;

	vector<db> p(n + 1);
	gor(i, 1, n + 1) cin >> p[i];

	vector<vector<db>> f(n + 1, vector<db>(n + 1));
	gor(i, 1, n + 1) gor(j, 1, i + 1) {
		if (j == 1) f[i][j] = max(f[i - 1][1], p[i]);
		else if (j == i) f[i][j] = 0.9 * f[i - 1][j - 1] + p[i];
		else f[i][j] = max(f[i - 1][j], 0.9 * f[i - 1][j - 1] + p[i]);
	}

	double w = 0, res = -1200;
	gor(i, 1, n + 1) {
		w = w * 0.9 + 1;
		res = max(res, f[n][i] / w - 1200 / sqrt(i));
	}

	printf("%.15lf\n", res);
	return 0;
}
