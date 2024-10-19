#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

constexpr int N = 1e6 + 10;

int n;

int a[N];

vector<int> pos[N];

string ans;

bool solve(int l1, int r1, int l2, int r2) {
	// cout << "| " << l1 << " " << r1 << " " << l2 << " " << r2 << endl;
	string op1, op2;
	for (int i = 1; i <= n - 1; ++i) {
		if (l1 < r1 && a[l1] == a[r1]) {
			op1.push_back('L');
			op2.push_back('L');
			++l1, --r1;
			// cout << "  LL" << endl;
		}
		else if (l1 <= r1 && l2 <= r2 && a[l1] == a[l2]) {
			op1.push_back('L');
			op2.push_back('R');
			++l1, ++l2;
			// cout << "  LR" << endl;
		}
		else if (l1 <= r1 && l2 <= r2 && a[r1] == a[r2]) {
			op1.push_back('R');
			op2.push_back('L');
			--r1, --r2;
			// cout << "  RL" << endl;
		}
		else if (l2 < r2 && a[l2] == a[r2]) {
			op1.push_back('R');
			op2.push_back('R');
			// cout << "  RR" << endl;
			++l2, --r2;
		}
		else
			return 0;
	}
	reverse(op2.begin(), op2.end());
	ans = op1 + op2;
	return 1;
}

void Main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; ++i)
			pos[i].clear();
		for (int i = 1; i <= 2 * n; ++i)
			cin >> a[i], pos[a[i]].push_back(i);
		if (solve(2, pos[a[1]][1] - 1, pos[a[1]][1] + 1, 2 * n))
			cout << "L" << ans << "L" << endl;
		else if (solve(1, pos[a[n]][0] - 1, pos[a[n]][0] + 1, 2 * n))
			cout << "R" << ans << "L" << endl;
		else
			cout << "-1" << endl;
	}
	return;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	return Main(), 0;
}

