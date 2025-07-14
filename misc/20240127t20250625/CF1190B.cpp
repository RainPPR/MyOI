#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

#define get(x) (cnt.count(x) ? cnt[x] : 0)

bool check(int n, auto &cnt) {
	if (get(0) >= 2)
		return false;
	long long sum = 0;
	int g2 = 0, g3 = 0;
	for (auto i : cnt) {
		if (i.second >= 2 && get(i.first - 1) >= 1)
			return false;
		g2 += i.second >= 2;
		g3 += i.second >= 3;
		sum += 1ll * i.first * i.second;
	}
	if (g3 || g2 >= 2)
		return false;
	return (sum - n * (n - 1) / 2) & 1;
}

void Main() {
	int n;
	cin >> n;
	unordered_map<int, int> cnt;
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		++cnt[x];
	}
	puts(check(n, cnt) ? "sjfnb" : "cslnb");
	return;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	return Main(), 0;
}

