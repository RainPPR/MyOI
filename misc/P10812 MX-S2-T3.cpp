#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

#define multi(op) [] { int T; cin >> T; while (T--) op(); }

constexpr int N = 5010;

int n, mod;

int S[N][N], F[N][N];

int s(int, int);
int f(int, int);

auto Main = ([] {
	memset(S, -1, sizeof S);
	memset(F, -1, sizeof F);
	cin >> n >> mod;
	cout << s(1, 2) << endl;
	return;
});

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	return Main(), 0;
}

int f(int i, int j) {
	if (F[i][j] != -1)
		return F[i][j];
	int res = 0;
	if (i == n)
		res = (j == n + 1);
	if (i == 1 && j == 2)
		res = 2 * s(2, 3) % mod;
	if (j == i + 1)
		res = s(i + 1, i + 2);
	if (j % i == 0)
		for (int k = i + 1; k <= j; ++k)
			res = (res + s(k, j)) % mod;
	return F[i][j] = res;
}

int s(int i, int j) {
	if (S[i][j] != -1)
		return S[i][j];
	int res = 0;
	for (int k = j; k <= n; ++k)
		res = (res + f(i, k)) % mod;
	return S[i][j] = res;
}

