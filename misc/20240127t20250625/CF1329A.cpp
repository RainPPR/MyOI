#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

constexpr int N = 1e5 + 10;

int n, m;

int l[N], p[N];

long long suf[N];

void Main() {
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> l[i];
		if (l[i] + i - 1 > n) {
			cout << "-1" << endl;
			return;
		}
	}
	for (int i = m; i >= 1; --i)
		suf[i] = suf[i + 1] + l[i];
	if (suf[1] < n) {
		cout << "-1" << endl;
		return;
	}
	cout << "1 ";
	for (int i = 2; i <= m; ++i) {
		if (i + suf[i] - 1 >= n)
			cout << i << " ";
		else
			cout << n - suf[i] + 1 << " ";
	}
	return;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	return Main(), 0;
}

