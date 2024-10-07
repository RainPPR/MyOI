#include <bits/stdc++.h>

using namespace std;

// -----------------------------------------------------------------------------

void Main() {
	long long x = 1e18, y, z;
	cout << "? " << x << endl;
	cin >> y;
	cout << "? " << x - y - 1 << endl;
	cin >> z;
	cout << "! " << z + 1 << endl;
}

// -----------------------------------------------------------------------------

signed main() {
	int T;
	cin >> T;
	while (T--)
		Main();
	return 0;
}
