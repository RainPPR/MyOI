#include <bits/stdc++.h>

using namespace std;

constexpr int N = 2e5 + 10;
constexpr int K = 20;

int n, a[N];

int st[N][K];

#define pow2(x) (1 << (x))

void build() {
    for (int i = 1; i <= n; ++i) st[i][0] = a[i];
    for (int k = 1; k < K; ++k) for (int i = 1; i + pow2(k) - 1 <= n; ++i) st[i][k] = max(st[i][k - 1], st[i + pow2(k - 1)][k - 1]);
}

int query(int p, int q) {
    int k = log2(q - p + 1);
    return max(st[p][k], st[q - pow2(k) + 1][k]);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    copy_n(istream_iterator<int>(cin), n, a + 1);
    build();
    int q, l, r; cin >> q;
    while (q--) cin >> l >> r, cout << query(l, r) << endl;
    return 0;
}