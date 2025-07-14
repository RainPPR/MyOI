#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

constexpr int N = 5e5 + 10;

using ll = long long;

#define int ll

int n, m;

string str;

namespace seg {
	struct vtt {
		int i, o, io, oi, ioi;
		vtt() = default;
		vtt(char c): i(c == 'I'), o(c == 'O') {}
		friend vtt operator +(const vtt &a, const vtt &b) {
			vtt r;
			r.i = a.i + b.i;
			r.o = a.o + b.o;
			r.io = a.io + b.io + a.i * b.o;
			r.oi = a.oi + b.oi + a.o * b.i;
			r.ioi = a.ioi + b.ioi + a.io * b.i + a.i * b.oi;
			return r;
		}
	};

	#define ls(x) ((x) << 1)
	#define rs(x) ((x) << 1 | 1)

	struct node {
		int l, r;
		vtt v;
	} a[N << 2];

	void push_up(int k) {
		a[k].v = a[ls(k)].v + a[rs(k)].v;
	}

	void build(int k, int l, int r) {
		a[k] = node{l, r, vtt()};
		if (l == r) {
			a[k].v = vtt(str[l]);
			return;
		}
		int mid = (l + r) >> 1;
		build(ls(k), l, mid);
		build(rs(k), mid + 1, r);
		push_up(k);
	}

	void modify(int k, int p, char x) {
		int l = a[k].l, r = a[k].r;
		if (l == r) {
			a[k].v = vtt(x);
			str[p] = x;
			return;
		}
		int mid = (l + r) >> 1;
		if (p <= mid)
			modify(ls(k), p, x);
		else
			modify(rs(k), p, x);
		push_up(k);
	}

	vtt query(int k, int p, int q) {
		int l = a[k].l, r = a[k].r;
		if (l >= p && r <= q)
			return a[k].v;
		int mid = (l + r) >> 1;
		if (q <= mid)
			return query(ls(k), p, q);
		if (p >= mid + 1)
			return query(rs(k), p, q);
		return query(ls(k), p, q) + query(rs(k), p, q);
	}
}

void Main() {
	cin >> n >> m;
	cin >> str, str = "#" + str;
	seg::build(1, 1, n);
	while (m--) {
		int op;
		cin >> op;
		if (op == 1) {
			int p;
			char c;
			cin >> p >> c;
			seg::modify(1, p, c);
		}
		else {
			int l, r;
			cin >> l >> r;
			cout << seg::query(1, l, r).ioi << endl;
		}
	}
	return;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	return Main(), 0;
}

