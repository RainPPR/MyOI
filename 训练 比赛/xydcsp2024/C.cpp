#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

constexpr long long mod = 1e9 + 7;

int n, m;

int calc(const vector<int> &a) {
	deque<int> q;
	for (int i = 1; i <= m; ++i)
		q.push_back(0);
	for (int i : a) {
		if (q.front() < i) {
			q.pop_front();
			q.push_back(i);
		}
	}
	long long ans = 0;
	for (int i : q)
		ans = (ans + i) % mod;
	return ans;
}

void Main() {
	cin >> n >> m;
	vector<int> a(n);
	for (int &i : a)
		cin >> i;
	long long ans = 0;
	do {
		ans = (ans + calc(a)) % mod;
	} while (next_permutation(a.begin(), a.end()));
	cout << ans << endl;
	return;
}

signed main() {
	freopen("potential.in", "r", stdin);
	freopen("potential.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	return Main(), 0;
}
