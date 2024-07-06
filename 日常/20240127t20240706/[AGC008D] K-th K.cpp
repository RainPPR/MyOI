#include <bits/stdc++.h>

using namespace std;

#define range(x) x.begin(), x.end()
#define rep(i, n) for (int i = 0; i < n; ++i)

#define endl '\n'
#define ERR { puts("No"), exit(0); }

struct emm {
	int id, pos;
	friend bool operator <(const emm &a, const emm &b) {
		return a.pos < b.pos;
	}
};

int n, tot;
vector<int> arr;

int put_end(int x) {
	do { ++tot; } while (arr[tot]);
	return arr[tot] = x, tot;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n; vector<emm> a(n); arr.resize(n * n + 1);
	rep(i, n) arr[cin >> a[i].pos, a[i].pos] = a[i].id = i + 1;
	sort(range(a));
	rep(i, n) rep(j, a[i].id - 1) if (put_end(a[i].id) >= a[i].pos) ERR;
	rep(i, n) rep(j, n - a[i].id) if (put_end(a[i].id) <= a[i].pos) ERR;
	cout << "Yes" << endl;
	for (int i = 1; i <= n * n; ++i) cout << arr[i] << " ";
	cout << endl;
	return 0;
}
