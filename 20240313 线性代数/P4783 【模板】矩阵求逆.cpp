#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1010;
constexpr int mod = 1e9 + 7;

int n;

int qpow(int a, int b) {
    int r = 1; while (b) {
        if (b & 1) r = 1ll * r * a % mod;
        a = 1ll * a * a % mod, b >>= 1;
    } return r;
}

#define inv(x) qpow(x, mod - 2)

struct matrix {
    vector<vector<int>> a;
    matrix() { a.resize(n + 1, vector<int>(2 * n + 1)); }
    int best_row(int row, int col) {
        int mi = 0, mc = -1;
        for (; row <= n; ++row) if (abs(a[row][col]) > mc)
        mi = row, mc = abs(a[row][col]);
        return mi;
    }
    void clear_row(int row, int col) {
        int v = inv(a[row][col]);
        for (int i = col; i <= 2 * n; ++i) a[row][i] = 1ll * a[row][i] * v % mod;
    }
    void clear_matrix(int row, int col) {
        for (int i = 1; i <= n; ++i) {
            if (i == row || !a[i][col]) continue;
            int v = a[i][col];
            for (int j = col; j <= 2 * n; ++j)
            a[i][j] = (a[i][j] - 1ll * a[row][j] * v % mod + mod) % mod;
        }
    }
    void solev(int &c) {
        int row = 1;
        for (int col = 1; col <= n; ++col) {
            int mi = best_row(row, col);
            if (a[mi][col] == 0) return void(c = -1);
            swap(a[mi], a[row]);
            clear_row(row, col);
            clear_matrix(row++, col);
        } return void(c = 1);
    }
};

void print(matrix &q) {
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j)
    cout << q.a[i][j + n] << (j == n ? '\n' : ' ');
}

signed main() {
    cin >> n; matrix q;
    for (int i = 1; i <= n; ++i) q.a[i][n + i] = 1;
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) cin >> q.a[i][j];
    int c = 0; q.solev(c);
    if (c == -1) puts("No Solution");
    else print(q);
    return 0;
}