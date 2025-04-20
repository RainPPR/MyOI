#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void solve(int a, int b, int c, int d) {
	vector<pair<int, int>> operations;
	for (int i = 0; i < 65; ++i) {
		if (a == c && b == d) {
			cout << operations.size() << "\n";
			for (auto &op : operations) {
				cout << op.first << " " << op.second << "\n";
			}
			return;
		}
		if (a > c && a % c == 0) {
			int k = a / c;
			a /= k;
			b *= k;
			operations.emplace_back(1, k);
		} else if (b > d && b % d == 0) {
			int k = b / d;
			b /= k;
			a *= k;
			operations.emplace_back(2, k);
		} else {
			break;
		}
	}
	cout << "-1\n";
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		solve(a, b, c, d);
	}
	return 0;
}