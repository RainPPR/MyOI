#include <bits/stdc++.h>

using namespace std;

using db = long double;

constexpr db eps = 1e-8;

#define abs(x) ((x) < 0 ? -(x) : (x))

struct matrix {
	int n; vector<db> b;
	vector<vector<db>> a;
	void input() {
		cin >> n; b.resize(n + 1);
		a.resize(n + 1, vector<db>(n + 1));
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) cin >> a[i][j];
			cin >> b[i];
		}
	}
	int best_row(int row, int col) {
		int mi = 0; double cm = -1;
		for (int i = row; i <= n; ++i) if (abs(a[i][col]) > cm) cm = abs(a[i][col]), mi = i;
		return mi;
	}
	void clear_row(int row, int col) {
		double t = a[row][col]; b[row] /= t;
		for (int i = col; i <= n; ++i) a[row][i] /= t;
	}
	void clear_matrix(int row, int col) {
		for (int i = 1; i <= n; ++i) {
			if (i == row || a[i][col] == 0) continue;
			double t = a[i][col]; b[i] -= t * b[row];
			for (int j = col; j <= n; ++j) a[i][j] -= t * a[row][j];
		}
	}
	vector<db> gauss(int &opc) {
		opc = 1; int row = 1;
		for (int col = 1; col <= n; ++col) {
			int mi = best_row(row, col);
			if (abs(a[mi][col]) < eps) continue;
			swap(a[row], a[mi]), swap(b[row], b[mi]);
			clear_row(row, col);
			clear_matrix(row++, col);
		} if (row == n + 1) return b;
		for (; row <= n; ++row) if (abs(b[row]) > eps) return (opc = -1, vector<db>());
		return (opc = 0, vector<db>());
	}
};

void print(vector<db> q) {
	for (int i = 1; i < q.size(); ++i) cout << "x" << i << "=" << q[i] << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	matrix x; x.input(); int c;
	vector<db> res = x.gauss(c);
	if (c != 1) cout << c << endl;
	else print(res);
	return 0;
}
