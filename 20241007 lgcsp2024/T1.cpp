#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

constexpr int N = 1e5 + 10;

int n, m1, m2;

struct node {
	int l, r;
	friend bool operator <(const node &a, const node &b) {
		return a.l < b.l;
	}
} a[N], b[N];

int calc(int p, int q) {
	int ans = 0;
	if (p != 0) {	// a, p
		priority_queue<int, vector<int>, greater<>> pheap;
		for (int i = 1; i <= p; ++i)
			pheap.push(0);
		for (int i = 1; i <= m1; ++i) {
			int l = a[i].l, r = a[i].r;
			if (pheap.top() > l)
				continue;
			pheap.pop();
			pheap.push(r);
			++ans;
		}
	}
	if (q != 0) {	// b, q
		priority_queue<int, vector<int>, greater<>> qheap;
		for (int i = 1; i <= q; ++i)
			qheap.push(0);
		for (int i = 1; i <= m2; ++i) {
			int l = b[i].l, r = b[i].r;
			if (qheap.top() > l)
				continue;
			qheap.pop();
			qheap.push(r);
			++ans;
		}
	}
	// cerr << p << " " << q << ": " << ans << endl;
	return ans;
}

int calc(int x) {
	return calc(x, n - x);
}

void Main() {
	cin >> n >> m1 >> m2;
	for (int i = 1; i <= m1; ++i)
		cin >> a[i].l >> a[i].r;
	for (int i = 1; i <= m2; ++i)
		cin >> b[i].l >> b[i].r;
	sort(a + 1, a + m1 + 1);
	sort(b + 1, b + m2 + 1);
	int ans = -1;
	if (n <= 5000) {
		for (int i = 0; i <= n; ++i)
			ans = max(ans, calc(i, n - i));
	}
	else {
		int l = 0, r = n;
		while (r - l >= 4) {
			int mid1 = (l + r) >> 1;
			int mid2 = mid1 + 1;
			int aa = calc(mid1);
			int bb = calc(mid2);
			ans = max({ans, aa, bb});
			if (aa > bb)
				r = mid2;
			else
				l = mid1;
		}
		mt19937 rnd(time(0) + 114514);
		for (int i = 0; i < 100; ++i)
			ans = max(ans, calc(rnd() % (n + 1)));
		for (int i = l; i <= r; ++i)
			ans = max(ans, calc(i));
	}
	cout << ans << endl;
	return;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	return Main(), 0;
}
