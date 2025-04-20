#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, q;

struct : set<int> {
	public:

	int front() {
		return *begin();
	}

	int back() {
		return *rbegin();
	}
} p;

double query(int x) {
//	cout << "| ";
//	for (int i : p)
//		cout << i << " ";
//	cout << endl;
	auto calc = [] (int ps, int ne) {
		int l = p.front(), r = p.back();
		// [l] ... [ps] -> [ne] ... [r]
		double res = abs(ps - ne) / 2.0;
		double lt = l + res, rt = r - res;
		double pos = min(ps, ne) + res;
		double ans = max(rt - pos, pos - lt) / 2.0;
		return res + ans;
	};
	auto it = p.lower_bound(x);
	if (it == p.begin()) {
		return (p.back() - x) / 2.0;
		// [x] ...
	}
	else if (next(it) == p.end()) {
		return (x - p.front()) / 2.0;
		// ... [x]
	}
	else {
		auto l = prev(it), r = next(it);
		return min(calc(*it, *l), calc(*it, *r));
	}
	return 0;
}

void Main() {
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		p.insert(x);
	}
	while (q--) {
		char op;
		int x;
		cin >> op >> x;
		if (op == '+')
			p.insert(x);
		else if (op == '-')
			p.erase(x);
		else
			printf("%.2lf\n", query(x));
	}
	return;
}

signed main() {
	freopen("secret.in", "r", stdin);
	freopen("secret.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	return Main(), 0;
}
