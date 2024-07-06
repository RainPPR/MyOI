#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr int mod = 998244353;

inline int add(int a, int b) { return (a + b) % mod; }
inline int mul(int a, int b) { return (1ll * a * b) % mod; }

struct mat {
	int a[4][4]; mat() {
		a[0][0] = a[0][1] = a[0][2] = a[0][3] = 0;
		a[1][0] = a[1][1] = a[1][2] = a[1][3] = 0;
		a[2][0] = a[2][1] = a[2][2] = a[2][3] = 0;
		a[3][0] = a[3][1] = a[3][2] = a[3][3] = 0;
	} mat(vector<vector<int>> t) {
		a[0][0] = t[0][0], a[0][1] = t[0][1], a[0][2] = t[0][2], a[0][3] = t[0][3];
		a[1][0] = t[1][0], a[1][1] = t[1][1], a[1][2] = t[1][2], a[1][3] = t[1][3];
		a[2][0] = t[2][0], a[2][1] = t[2][1], a[2][2] = t[2][2], a[2][3] = t[2][3];
		a[3][0] = t[3][0], a[3][1] = t[3][1], a[3][2] = t[3][2], a[3][3] = t[3][3];
	} friend bool operator ==(const mat &a, const mat &b) {
		if (a.a[0][0] != b.a[0][0]) return false;
		if (a.a[0][1] != b.a[0][1]) return false;
		if (a.a[0][2] != b.a[0][2]) return false;
		if (a.a[0][3] != b.a[0][3]) return false;
		if (a.a[1][0] != b.a[1][0]) return false;
		if (a.a[1][1] != b.a[1][1]) return false;
		if (a.a[1][2] != b.a[1][2]) return false;
		if (a.a[1][3] != b.a[1][3]) return false;
		if (a.a[2][0] != b.a[2][0]) return false;
		if (a.a[2][1] != b.a[2][1]) return false;
		if (a.a[2][2] != b.a[2][2]) return false;
		if (a.a[2][3] != b.a[2][3]) return false;
		if (a.a[3][0] != b.a[3][0]) return false;
		if (a.a[3][1] != b.a[3][1]) return false;
		if (a.a[3][2] != b.a[3][2]) return false;
		if (a.a[3][3] != b.a[3][3]) return false;
		return true;
	}
};

const mat I = mat({ {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1} });

struct vec {
	int a[4];
	vec() { a[0] = a[1] = a[2] = a[3] = 0; }
	vec(vector<int> t) { a[0] = t[0], a[1] = t[1], a[2] = t[2], a[3] = t[3]; }
};

inline mat mul(const mat &a, const mat &b) {
	mat r;
	r.a[0][0] = add(r.a[0][0], mul(a.a[0][0], b.a[0][0]));
	r.a[0][0] = add(r.a[0][0], mul(a.a[0][1], b.a[1][0]));
	r.a[0][0] = add(r.a[0][0], mul(a.a[0][2], b.a[2][0]));
	r.a[0][0] = add(r.a[0][0], mul(a.a[0][3], b.a[3][0]));
	r.a[0][1] = add(r.a[0][1], mul(a.a[0][0], b.a[0][1]));
	r.a[0][1] = add(r.a[0][1], mul(a.a[0][1], b.a[1][1]));
	r.a[0][1] = add(r.a[0][1], mul(a.a[0][2], b.a[2][1]));
	r.a[0][1] = add(r.a[0][1], mul(a.a[0][3], b.a[3][1]));
	r.a[0][2] = add(r.a[0][2], mul(a.a[0][0], b.a[0][2]));
	r.a[0][2] = add(r.a[0][2], mul(a.a[0][1], b.a[1][2]));
	r.a[0][2] = add(r.a[0][2], mul(a.a[0][2], b.a[2][2]));
	r.a[0][2] = add(r.a[0][2], mul(a.a[0][3], b.a[3][2]));
	r.a[0][3] = add(r.a[0][3], mul(a.a[0][0], b.a[0][3]));
	r.a[0][3] = add(r.a[0][3], mul(a.a[0][1], b.a[1][3]));
	r.a[0][3] = add(r.a[0][3], mul(a.a[0][2], b.a[2][3]));
	r.a[0][3] = add(r.a[0][3], mul(a.a[0][3], b.a[3][3]));
	r.a[1][0] = add(r.a[1][0], mul(a.a[1][0], b.a[0][0]));
	r.a[1][0] = add(r.a[1][0], mul(a.a[1][1], b.a[1][0]));
	r.a[1][0] = add(r.a[1][0], mul(a.a[1][2], b.a[2][0]));
	r.a[1][0] = add(r.a[1][0], mul(a.a[1][3], b.a[3][0]));
	r.a[1][1] = add(r.a[1][1], mul(a.a[1][0], b.a[0][1]));
	r.a[1][1] = add(r.a[1][1], mul(a.a[1][1], b.a[1][1]));
	r.a[1][1] = add(r.a[1][1], mul(a.a[1][2], b.a[2][1]));
	r.a[1][1] = add(r.a[1][1], mul(a.a[1][3], b.a[3][1]));
	r.a[1][2] = add(r.a[1][2], mul(a.a[1][0], b.a[0][2]));
	r.a[1][2] = add(r.a[1][2], mul(a.a[1][1], b.a[1][2]));
	r.a[1][2] = add(r.a[1][2], mul(a.a[1][2], b.a[2][2]));
	r.a[1][2] = add(r.a[1][2], mul(a.a[1][3], b.a[3][2]));
	r.a[1][3] = add(r.a[1][3], mul(a.a[1][0], b.a[0][3]));
	r.a[1][3] = add(r.a[1][3], mul(a.a[1][1], b.a[1][3]));
	r.a[1][3] = add(r.a[1][3], mul(a.a[1][2], b.a[2][3]));
	r.a[1][3] = add(r.a[1][3], mul(a.a[1][3], b.a[3][3]));
	r.a[2][0] = add(r.a[2][0], mul(a.a[2][0], b.a[0][0]));
	r.a[2][0] = add(r.a[2][0], mul(a.a[2][1], b.a[1][0]));
	r.a[2][0] = add(r.a[2][0], mul(a.a[2][2], b.a[2][0]));
	r.a[2][0] = add(r.a[2][0], mul(a.a[2][3], b.a[3][0]));
	r.a[2][1] = add(r.a[2][1], mul(a.a[2][0], b.a[0][1]));
	r.a[2][1] = add(r.a[2][1], mul(a.a[2][1], b.a[1][1]));
	r.a[2][1] = add(r.a[2][1], mul(a.a[2][2], b.a[2][1]));
	r.a[2][1] = add(r.a[2][1], mul(a.a[2][3], b.a[3][1]));
	r.a[2][2] = add(r.a[2][2], mul(a.a[2][0], b.a[0][2]));
	r.a[2][2] = add(r.a[2][2], mul(a.a[2][1], b.a[1][2]));
	r.a[2][2] = add(r.a[2][2], mul(a.a[2][2], b.a[2][2]));
	r.a[2][2] = add(r.a[2][2], mul(a.a[2][3], b.a[3][2]));
	r.a[2][3] = add(r.a[2][3], mul(a.a[2][0], b.a[0][3]));
	r.a[2][3] = add(r.a[2][3], mul(a.a[2][1], b.a[1][3]));
	r.a[2][3] = add(r.a[2][3], mul(a.a[2][2], b.a[2][3]));
	r.a[2][3] = add(r.a[2][3], mul(a.a[2][3], b.a[3][3]));
	r.a[3][0] = add(r.a[3][0], mul(a.a[3][0], b.a[0][0]));
	r.a[3][0] = add(r.a[3][0], mul(a.a[3][1], b.a[1][0]));
	r.a[3][0] = add(r.a[3][0], mul(a.a[3][2], b.a[2][0]));
	r.a[3][0] = add(r.a[3][0], mul(a.a[3][3], b.a[3][0]));
	r.a[3][1] = add(r.a[3][1], mul(a.a[3][0], b.a[0][1]));
	r.a[3][1] = add(r.a[3][1], mul(a.a[3][1], b.a[1][1]));
	r.a[3][1] = add(r.a[3][1], mul(a.a[3][2], b.a[2][1]));
	r.a[3][1] = add(r.a[3][1], mul(a.a[3][3], b.a[3][1]));
	r.a[3][2] = add(r.a[3][2], mul(a.a[3][0], b.a[0][2]));
	r.a[3][2] = add(r.a[3][2], mul(a.a[3][1], b.a[1][2]));
	r.a[3][2] = add(r.a[3][2], mul(a.a[3][2], b.a[2][2]));
	r.a[3][2] = add(r.a[3][2], mul(a.a[3][3], b.a[3][2]));
	r.a[3][3] = add(r.a[3][3], mul(a.a[3][0], b.a[0][3]));
	r.a[3][3] = add(r.a[3][3], mul(a.a[3][1], b.a[1][3]));
	r.a[3][3] = add(r.a[3][3], mul(a.a[3][2], b.a[2][3]));
	r.a[3][3] = add(r.a[3][3], mul(a.a[3][3], b.a[3][3]));
	return r;
}

inline vec mul(const mat &a, const vec &b) {
	vec r;
	r.a[0] = add(r.a[0], mul(a.a[0][0], b.a[0]));
	r.a[0] = add(r.a[0], mul(a.a[0][1], b.a[1]));
	r.a[0] = add(r.a[0], mul(a.a[0][2], b.a[2]));
	r.a[0] = add(r.a[0], mul(a.a[0][3], b.a[3]));
	r.a[1] = add(r.a[1], mul(a.a[1][0], b.a[0]));
	r.a[1] = add(r.a[1], mul(a.a[1][1], b.a[1]));
	r.a[1] = add(r.a[1], mul(a.a[1][2], b.a[2]));
	r.a[1] = add(r.a[1], mul(a.a[1][3], b.a[3]));
	r.a[2] = add(r.a[2], mul(a.a[2][0], b.a[0]));
	r.a[2] = add(r.a[2], mul(a.a[2][1], b.a[1]));
	r.a[2] = add(r.a[2], mul(a.a[2][2], b.a[2]));
	r.a[2] = add(r.a[2], mul(a.a[2][3], b.a[3]));
	r.a[3] = add(r.a[3], mul(a.a[3][0], b.a[0]));
	r.a[3] = add(r.a[3], mul(a.a[3][1], b.a[1]));
	r.a[3] = add(r.a[3], mul(a.a[3][2], b.a[2]));
	r.a[3] = add(r.a[3], mul(a.a[3][3], b.a[3]));
	return r;
}

inline vec add(const vec &a, const vec &b) {
	vec r;
	r.a[0] = add(a.a[0], b.a[0]);
	r.a[1] = add(a.a[1], b.a[1]);
	r.a[2] = add(a.a[2], b.a[2]);
	r.a[3] = add(a.a[3], b.a[3]);
	return r;
}

inline mat op(int o, int v) {
	switch (o) {
		case 1: return mat({ {1, 1, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1} });
		case 2: return mat({ {1, 0, 0, 0}, {0, 1, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 1} });
		case 3: return mat({ {1, 0, 0, 0}, {0, 1, 0, 0}, {1, 0, 1, 0}, {0, 0, 0, 1} });
		case 4: return mat({ {1, 0, 0, v}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1} });
		case 5: return mat({ {1, 0, 0, 0}, {0, v, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1} });
		case 6: return mat({ {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, v}, {0, 0, 0, 1} });
	}
}

class segment_tree {
	
private:
	
	struct emm {
		int l, r;
		vec v; mat tag;
	};
	
	int n; vector<emm> a;
	
	void push_up(int k) {
		a[k].v = add(a[k * 2].v, a[k * 2 + 1].v);
	}
	
	void action(int k, mat v) {
		a[k].tag = mul(v, a[k].tag);
		a[k].v = mul(v, a[k].v);
	}
	
	void push_down(int k) {
		if (a[k].tag == I) return;
		action(k * 2, a[k].tag);
		action(k * 2 + 1, a[k].tag);
		a[k].tag = I;
	}
	
	void build(vector<vec> &q, int k, int l, int r) {
		a[k].l = l, a[k].r = r, a[k].tag = I;
		if (l == r) return void(a[k].v = q[l]);
		int mid = l + (r - l >> 1);
		build(q, k * 2, l, mid);
		build(q, k * 2 + 1, mid + 1, r);
		push_up(k);
	}
	
	vec query(int k, int p, int q) {
		int l = a[k].l, r = a[k].r;
		if (l >= p && r <= q) return a[k].v;
		push_down(k);
		int mid = l + (r - l >> 1);
		if (mid + 1 > q) return query(k * 2, p, q);
		if (mid < p) return query(k * 2 + 1, p, q);
		return add(query(k * 2, p, q), query(k * 2 + 1, p, q));
	}
	
	void modify(int k, int p, int q, mat v) {
		int l = a[k].l, r = a[k].r;
		if (l >= p && r <= q) return void(action(k, v));
		push_down(k);
		int mid = l + (r - l >> 1);
		if (mid >= p) modify(k * 2, p, q, v);
		if (mid + 1 <= q) modify(k * 2 + 1, p, q, v);
		push_up(k);
	}
	
public:
	
	segment_tree(vector<vec> &q) { n = q.size(); a.resize(n * 4); build(q, 1, 1, n - 1); }
	vec sum(int l, int r) { return query(1, l, r); }
	void change(int l, int r, mat v) { modify(1, l, r, v); }

};

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int n, a, b, c, m, o, l, r, v;
	cin >> n; vec t;
	vector<vec> nums(n);
	nums.push_back(vec({ 0, 0, 0, 0 }));
	for (int i = 1; i <= n; ++i) cin >> a >> b >> c, nums[i] = vec({ a, b, c, 1 });
	segment_tree seg(nums); cin >> m;
	while (m--) {
		cin >> o >> l >> r;
		if (o == 7) t = seg.sum(l, r), cout << t.a[0] << " " << t.a[1] << " " << t.a[2] << endl;
		else if (o <= 3) seg.change(l, r, op(o, 0));
		else cin >> v, seg.change(l, r, op(o, v));
	} return 0;
}
