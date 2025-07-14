#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

void Main();

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	return Main(), 0;
}

using ll = long long;

#define int ll

#define ctz(x) __builtin_ctz(x)

int mygcd(int a, int b) {
	if (!a || !b)
		return a + b;
	int az = ctz(a), bz = ctz(b);
	int zz = min(az, bz);
	a >>= az, b >>= bz;
	while (a != b) {
		int diff = b - a;
		az = ctz(diff);
		b = min(a, b);
		a = abs(diff) >> az;
	}
	return a << zz;
}

int phi(int n) {
	int r = n, up = sqrt(n);
	for (int i = 2; i <= up; ++i) {
		if (n % i != 0)
			continue;
		r = r / i * (i - 1);
		while (n % i == 0)
			n /= i;
	}
	if (n > 1)
		r = r / n * (n - 1);
	return r;
}

void Main() {
	int T;
	cin >> T;
	while (T--) {
		int a, m;
		cin >> a >> m;
		int g = mygcd(a, m);
		cout << phi(m / g) << endl;
	}
	return;
}
