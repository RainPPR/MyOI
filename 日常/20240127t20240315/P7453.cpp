#include <bits/stdc++.h>

using namespace std;

constexpr int mod = 998244353;

inline int add(int a, int b) { int t = a + b; return t >= mod ? t - mod : t; }
inline int mul(int a, int b) { return (1ll * a * b) % mod; }

struct matrix {
	int n, m;
	vector<vector<int>> a;
	matrix() = default;
	matrix(int n, int m): n(n), m(m) { a.resize(n, vector<int>(m)); }
	matrix(vector<vector<int>> a): a(a) { n = a.size(), m = n ? a[0].size() : 0; }
	friend bool operator ==(const matrix &a, const matrix &b) {
		if (a.n != b.n) return false;
		if (a.m != b.m) return false;
		if (a.a != b.a) return false;
		return true;
	}
	friend matrix operator +(const matrix &a, const matrix &b) {
		int n = a.n, m = a.m;
		matrix r(n, m);
		for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		r.a[i][j] = add(a.a[i][j], b.a[i][j]);
		return r;
	}
	friend matrix operator *(const matrix &a, const matrix &b) {
		int n = a.n, m = b.m, q = a.m;
		matrix r(n, m);
		for (int i = 0; i < n; ++i)
		for (int k = 0; k < q; ++k)
		for (int j = 0; j < m; ++j)
		r.a[i][j] = add(r.a[i][j], mul(a.a[i][k], b.a[k][j]));
		return r;
	}
};

inline matrix op(int o, int v) {
	switch (o) {
		case 1: return matrix({ {1, 1, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1} });
		case 2: return matrix({ {1, 0, 0, 0}, {0, 1, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 1} });
		case 3: return matrix({ {1, 0, 0, 0}, {0, 1, 0, 0}, {1, 0, 1, 0}, {0, 0, 0, 1} });
		case 4: return matrix({ {1, 0, 0, v}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1} });
		case 5: return matrix({ {1, 0, 0, 0}, {0, v, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1} });
		case 6: return matrix({ {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, v}, {0, 0, 0, 1} });
		default: exit(114);
	}
}

class segment_tree {
	
private:
	
	matrix I = matrix({ {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1} });
	
	struct emm {
		int l, r;
		matrix v, tag;
	};
	
	int n; vector<emm> a;
	
	void push_up(int k) {
		a[k].v = a[k * 2].v + a[k * 2 + 1].v;
	}
	
	void action(int k, matrix v) {
		a[k].tag = v * a[k].tag;
		a[k].v = v * a[k].v;
	}
	
	void push_down(int k) {
		if (a[k].tag == I) return;
		action(k * 2, a[k].tag);
		action(k * 2 + 1, a[k].tag);
		a[k].tag = I;
	}
	
	void build(vector<matrix> &q, int k, int l, int r) {
		a[k].l = l, a[k].r = r, a[k].tag = I;
		if (l == r) return void(a[k].v = q[l]);
		int mid = l + (r - l >> 1);
		build(q, k * 2, l, mid);
		build(q, k * 2 + 1, mid + 1, r);
		push_up(k);
	}
	
	matrix query(int k, int p, int q) {
		int l = a[k].l, r = a[k].r;
		if (l >= p && r <= q) return a[k].v;
		push_down(k);
		int mid = l + (r - l >> 1);
		if (mid + 1 > q) return query(k * 2, p, q);
		if (mid < p) return query(k * 2 + 1, p, q);
		return query(k * 2, p, q) + query(k * 2 + 1, p, q);
		return matrix({ {0}, {0}, {0}, {0} });
	}
	
	void modify(int k, int p, int q, matrix v) {
		int l = a[k].l, r = a[k].r;
		if (l >= p && r <= q) return void(action(k, v));
		push_down(k);
		int mid = l + (r - l >> 1);
		if (mid >= p) modify(k * 2, p, q, v);
		if (mid + 1 <= q) modify(k * 2 + 1, p, q, v);
		push_up(k);
	}
	
public:
	
	segment_tree(vector<matrix> &q) { n = q.size(); a.resize(n * 4); build(q, 1, 1, n - 1); }
	matrix sum(int l, int r) { return query(1, l, r); }
	void change(int l, int r, matrix v) { modify(1, l, r, v); }

};

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int n, a, b, c, m, o, l, r, v;
	cin >> n; matrix t;
	vector<matrix> nums(n);
	nums.push_back(matrix({ {0}, {0}, {0}, {0} }));
	for (int i = 1; i <= n; ++i) cin >> a >> b >> c, nums[i] = matrix({ {a}, {b}, {c}, {1} });
	segment_tree seg(nums); cin >> m;
	while (m--) {
		cin >> o >> l >> r;
		if (o == 7) t = seg.sum(l, r), cout << t.a[0][0] << " " << t.a[1][0] << " " << t.a[2][0] << endl;
		else if (o <= 3) seg.change(l, r, op(o, 0));
		else cin >> v, seg.change(l, r, op(o, v));
	} return 0;
}
