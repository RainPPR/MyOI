#include <bits/stdc++.h>

using namespace std;

#define range(x) x.begin(), x.end()

struct emm {
	int id, x, y;
};

mt19937 rd(time(0) * clock());

int n;
vector<emm> a;
vector<int> ans;

double dis(int x, int y) {
	return sqrt(1.0 * x * x + 1.0 * y * y);
}

double solev() {
	shuffle(range(a), rd);
	int x = 0, y = 0;
	for (auto &[id, i, j] : a) {
		ans[id] = dis(x + i, y + j) < dis(x - i, y - j) ? 1 : -1;
		x += i * ans[id], y += j * ans[id];
	} return dis(x, y);
}

void print() {
	for (int i : ans) cout << i << " ";
	cout << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n; a.resize(n), ans.resize(n);
	for (int i = 0; i < n; ++i) cin >> a[i].x >> a[i].y, a[i].id = i;
	while (1) if (solev() <= 1.5e6) print(), exit(0);
	return 0;
}
