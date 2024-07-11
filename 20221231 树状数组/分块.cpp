#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

using ll = long long;

constexpr int N = 1e5 + 10;

int n, m, siz, cnt;
int belong[N], L[N], R[N];
ll a[N], sum[N], tag[N];

void build() {
    siz = sqrt(n), cnt = (n - 1) / siz + 1;
    for (int i = 1; i <= n; ++i) belong[i] = (i - 1) / siz + 1;
    for (int i = 1; i <= cnt; ++i) L[i] = (i - 1) * siz + 1, R[i] = i * siz;
    R[cnt] = n;
}

void modify(int l, int r, int v) {
    int p = belong[l], q = belong[r];
    if (p == q) {
        for (int i = l; i <= r; ++i) a[i] += v, sum[p] += v;
        return;
    }
    for (int i = l; i <= R[p]; ++i) a[i] += v, sum[p] += v;
    for (int i = p + 1; i <= q - 1; ++i) tag[i] += v, sum[i] += v * siz;
    for (int i = L[q]; i <= r; ++i) a[i] += v, sum[q] += v;
}

ll query(int l, int r) {
    int p = belong[l], q = belong[r];
    ll res = 0;
    if (p == q) {
        for (int i = l; i <= r; ++i) res += a[i] + tag[p];
        return res;
    }
    for (int i = l; i <= R[p]; ++i) res += a[i] + tag[p];
    for (int i = p + 1; i <= q - 1; ++i) res += sum[i];
    for (int i = L[q]; i <= r; ++i) res += a[i] + tag[q];
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i], sum[belong[i]] += a[i];
    build();
    while (m--) {
        char op[3];
        int l, r;
        cin >> op >> l >> r;
        if (op[0] == 'Q')
            cout << query(l, r) << endl;
        else {
            int x; cin >> x;
            modify(l, r, x);
        }
    }
    return 0;
}