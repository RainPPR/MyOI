#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

struct query_t {
    int l, r;
    bool iseven;
};

struct dsu_t {
    vector<int> fa;
    dsu_t(int n): fa(n) { iota(fa.begin(), fa.end(), 0); }
    int getfa(int x) { return x == fa[x] ? x : fa[x] = getfa(fa[x]); }
    void unite(int l, int r) { fa[getfa(l)] = getfa(r); }
} dsu(1e4 + 10);

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> s(m * 2);
    vector<query_t> a(m);
    for (int i = 0; i < m; ++i) {
        int l, r; string op;
        cin >> l >> r >> op;
        --l;
        s[i] = l, s[i + m] = r;
        a[i] = (query_t){l, r, op == "even"};
    }
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    n = s.size();
    #define getid(x) (lower_bound(s.begin(), s.end(), x) - s.begin() + 1)
    for (int i = 0; i < m; ++i) {
        int op = a[i].iseven;
        int l = getid(a[i].l), r = getid(a[i].r);
        // cout << "MERGE " << l << " " << r << " " << op << " WA " << n << endl;
        if (op == 1) {
            if (dsu.getfa(l) == dsu.getfa(r + n) || dsu.getfa(l + n) == dsu.getfa(r))
                cout << i << endl, exit(0);
            dsu.unite(l, r), dsu.unite(l + n, r + n);
        } else {
            if (dsu.getfa(l) == dsu.getfa(r) || dsu.getfa(l + n) == dsu.getfa(r + n))
                cout << i << endl, exit(0);
            dsu.unite(l, r + n), dsu.unite(l + n, r);
        }
    }
    cout << m << endl;
    return 0;
}