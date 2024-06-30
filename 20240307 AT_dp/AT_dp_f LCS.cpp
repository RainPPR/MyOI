#include <bits/stdc++.h>

using namespace std;

constexpr int N = 3010;

string s, t; int n, m;
int f[N][N], g[N][N];

void print(int x = n, int y = m) {
	stack<char> str; while (f[x][y]) {
		if (g[x][y] == 1) str.push(s[x]), x = x - 1, y = y - 1;
		else if (g[x][y] == 2) x = x - 1; else y = y - 1;
	} while (str.size()) putchar(str.top()), str.pop();
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> s >> t; n = s.size(), m = t.size(); s = "#" + s, t = "#" + t;
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) {
		if (s[i] == t[j]) f[i][j] = f[i - 1][j - 1] + 1, g[i][j] = 1;
		else if (f[i - 1][j] > f[i][j - 1]) f[i][j] = f[i - 1][j], g[i][j] = 2;
		else f[i][j] = f[i][j - 1], g[i][j] = 3;
	} print(n, m);
	return 0;
}
