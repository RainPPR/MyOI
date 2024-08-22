#include <bits/stdc++.h>

using namespace std;

#define range(x) x.begin(), x.end()

class seg {

private:

int n;

struct emm {
	int l, r;
	int mx, cmx;
	int mxc, cmxc;
	emm() : mx(-1), cmx(-1) { }
	emm(int a, int b) : mx(a), cmx(b) { }
	emm(int l, int r, int a, int ac, int b, int bc) : l(l), r(r), mx(a), mxc(ac), cmx(b), cmxc(bc) { }
	friend emm operator +(const emm &a, const emm &b) {
		map<int, int> q; q[-1] += 1;
		q[a.mx] += a.mxc; q[a.cmx] += a.cmxc;
		q[b.mx] += b.mxc; q[b.cmx] += b.cmxc;
		pair<int, int> a1, a2;
		for (auto i : q) a2 = a1, a1 = i;
		return emm(a.l, b.r, a1.first, a1.second, a2.first, a2.second);
	}
};

vector<emm> a;
	
void push_up(int k) {
	a[k] = a[k * 2] + a[k * 2 + 1];
}

void build(vector<int> &q, int k, int l, int r) {
	a[k].l = l, a[k].r = r;
	if (l == r) return void((a[k].mx = l >= n ? -1 : q[l], a[k].cmx = -1, a[k].mxc = a[k].cmxc = 1));
	int mid = l + (r - l >> 1);
	build(q, k * 2, l, mid);
	build(q, k * 2 + 1, mid + 1, r);
	push_up(k);
}

void modify(int k, int x, int v) {
	int l = a[k].l, r = a[k].r;
	if (l == r) return void((a[k].mx = v, a[k].cmx = -1));
	int mid = l + (r - l >> 1);
	if (x <= mid) modify(k * 2, x, v);
	else modify(k * 2 + 1, x, v);
	push_up(k);
}

emm query(int k, int p, int q) {
	int l = a[k].l, r = a[k].r;
	if (p <= l && q >= r) return a[k];
	int mid = l + (r - l >> 1);
	if (q <= mid) return query(k * 2, p, q);
	if (p > mid) return query(k * 2 + 1, p, q);
	return query(k * 2, p, q) + query(k * 2 + 1, p, q);
}

public:

seg(vector<int> &q) { n = q.size(); a.resize(n * 4); build(q, 1, 1, n); }
void change(int x, int c) { modify(1, x, c); }
int cmx(int l, int r) { auto t = query(1, l, r); return t.cmx == -1 ? 0 : t.cmxc; }

};

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int n, q; cin >> n >> q;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i) cin >> a[i];
	seg sg(a);
	while (q--) {
		int o, x, y; cin >> o >> x >> y;
		if (o == 1) sg.change(x, y);
		else cout << sg.cmx(x, y) << endl;
	} return 0;
}
