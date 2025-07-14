#include <bits/stdc++.h>

using namespace std;

#define range(x) x.begin(), x.end()
#define ERR { puts("No"), exit(0); }

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int n; cin >> n;
	vector<int> b(n + 1), a(n + 1);
	for (int i = 1; i <= n; ++i) cin >> b[i], a[n] ^= b[i];
	cerr << a[n] << endl;
	int lt = a[n];
	vector<int> ans;
	for (int i = n - 1; i; --i) {
		int pos = -1;
		for (int j = 1; j <= n; ++j) {
			if (b[i] == -1) continue;
			if ((lt ^ b[j]) >= lt) continue;
			if (pos != -1 && (lt ^ b[j]) < (lt ^ b[pos])) continue;
			pos = j;
		}
		if (pos == -1) ERR;
		cerr << i << ": " << pos << " -> " << (lt ^ b[pos]) << endl;
		ans.push_back(b[pos]);
		lt ^= b[pos];
		b[pos] = -1;
	} cout << "Yes" << endl;
	for (int i : ans) cout << i << " ";
	return 0;
}
