#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr int N = 1e4 + 10;
constexpr int K = 110;

constexpr int mod = 1e9 + 7;

int n, d;
string k;

int mem[N][K];
int dfs(int pos, int limit, int r) {
	if (pos == n) return r == 0;
	if (!limit && mem[pos][r] != -1) return mem[pos][r];
	int res = 0, up = limit ? k[pos] - '0' : 9;
	rep (i, 0, up) res = (res + dfs(pos + 1, limit && (i == up), (r + i) % d)) % mod;
	if (!limit) mem[pos][r] = res;
	return res;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> k >> d; n = k.size();
	memset(mem, -1, sizeof mem);
	cout << (dfs(0, 1, 0) - 1 + mod) % mod << endl;
	return 0;
}
