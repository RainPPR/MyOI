#include <bits/stdc++.h>

using namespace std;

namespace id {
    unordered_map<int, int> lst;
    int getid(int x) {
        if (lst.count(x)) return lst[x];
        else return lst[x] = lst.size() + 1;
    }
}

using namespace id;

struct dsu {
    vector<int> fa;
    dsu() = default;
    dsu(int n): fa(n) { iota(fa.begin(), fa.end(), 0); }
    int getfa(int x) { return x == fa[x] ? x : fa[x] = getfa(fa[x]); }
    void unite(int x, int y) { fa[getfa(x)] = getfa(y); }
};

void solev() {
    int n;
    cin >> n;
    lst.clear();
    vector<pair<int, int>> q[2];
    for (int i = 0; i < n; ++i) {
        int x, y, op;
        cin >> x >> y >> op;
        x = getid(x), y = getid(y);
        q[op].emplace_back(x, y);
    }
    dsu a = dsu(2 * n + 1);
    for (auto i : q[1]) a.unite(i.first, i.second);
    for (auto i : q[0])
        if (a.getfa(i.first) == a.getfa(i.second))
        {
            puts("NO");
            return;
        }
    puts("YES");
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T; while (T--) solev();
    return 0;
}