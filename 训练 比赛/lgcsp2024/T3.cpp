#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

constexpr int N = 5e5 + 10;

int n, a[N], b[N];

void MaiN() {
	cin >> n;
	for (int i = 1; i <= 2 * n; ++i)
		cin >> a[i];
	for (int i = 0; i < (1 << (2 * n)); ++i) {
		int l = 1, r = 2 * n;
		int m = 0;
		for (int j = 1; j <= n; ++j) {
			if ((i >> (2 * n - j)) & 1)
				b[++m] = a[r--];
			else
				b[++m] = a[l++];
		}
		bool flag = true;
		for (int j = n + 1; j <= 2 * n; ++j) {
			if ((i >> (2 * n - j)) & 1)
				b[++m] = a[r--];
			else
				b[++m] = a[l++];
			if (b[m] != b[2 * n - m + 1]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			for (int j = 1; j <= 2 * n; ++j)
				cout << (((i >> (2 * n - j)) & 1) ? 'R' : 'L');
			cout << endl;
			return;
		}
	}
	cout << "-1" << endl;
}

void Main() {
	int T;
	cin >> T;
	while (T--)
		MaiN();
	return;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	return Main(), 0;
}
