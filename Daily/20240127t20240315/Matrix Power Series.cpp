#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

int n, k;

const int m = 10;

struct matrix_int {
	int n; vector<vector<int> > a;
	matrix_int() { }
	matrix_int(int n): n(n) { a.resize(n, vector<int>(n)); }
	void set() { for (int i = 0; i < n; ++i) a[i][i] = 1; }
	void reset(int x = 0) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) a[i][j] = x; }
	void print() { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cout << a[i][j] << (j == n - 1 ? "\n" : " "); }
	friend matrix_int operator +(const matrix_int &a, const matrix_int &b) {
		int n = a.n; matrix_int r(n);
		for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		r.a[i][j] = (a.a[i][j] + b.a[i][j]) % m;
		return r;
	}
	friend matrix_int operator *(const matrix_int &a, const matrix_int &b) {
		int n = a.n; matrix_int r(n);
		for (int i = 0; i < n; ++i)
		for (int k = 0; k < n; ++k)
		for (int j = 0; j < n; ++j)
		r.a[i][j] = (r.a[i][j] + 1ll * a.a[i][k] * b.a[k][j] % m) % m;
		return r;
	}
};

matrix_int zero, one;

struct matrix_matrix {
	int n; vector<vector<matrix_int> > a;
	matrix_matrix() { }
	matrix_matrix(int n): n(n) { a.resize(n, vector<matrix_int>(n)); }
	void set() { for (int i = 0; i < n; ++i) a[i][i] = one; }
	void reset(matrix_int x = zero) { for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) a[i][j] = x; }
	friend matrix_matrix operator *(const matrix_matrix &a, const matrix_matrix &b) {
		int n = a.n; matrix_matrix r(n);
		for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		r.a[i][j] = matrix_int(a.a[0][0].n);
		for (int i = 0; i < n; ++i)
		for (int k = 0; k < n; ++k)
		for (int j = 0; j < n; ++j)
		r.a[i][j] = r.a[i][j] + a.a[i][k] * b.a[k][j];
		return r;
	}
};

template<typename tp>
tp qpow(tp a, int k) {
	tp r = a; --k;
	while (k) {
		if (k & 1) r = r * a;
		a = a * a; k >>= 1;
	} return r;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	while (cin >> n >> k && n) {
		if (n == 0 && k == 0) exit(0);
		matrix_int a(n);
		for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> a.a[i][j];
		zero = matrix_int(n), one = matrix_int(n); one.set();
		matrix_matrix b(2);
		b.a[0][0] = a, b.a[0][1] = zero;
		b.a[1][0] = a, b.a[1][1] = one;
		b = qpow(b, k);
		b.a[1][0].print();
		cout << endl;
	} return 0;
}
