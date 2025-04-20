#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

using ll = long long;

#define int ll

int n, m, c, k;

void Main() {
    cin >> n >> m >> c >> k;
    int all = 0;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        all |= x;
    }
    unordered_set<int> used;
    vector<pair<int, int>> T;
    for (int i = 1; i <= m; ++i) {
        int p, q;
        cin >> p >> q;
        T.emplace_back(p, q);
        if ((all >> p) & 1)
            used.insert(q);
    }
    unordered_set<int> miss;
    for (auto t : T) {
        int p, q;
        tie(p, q) = t;
        // cerr << "[" << p << ", " << q << endl;
        if (used.count(q) == 0)
            miss.insert(p);
    }
    // cerr << int(miss.size()) << endl;
    __int128 res = (__int128(1) << (k - int(miss.size()))) - n;
    __int128 lim = (__int128(1) << 64);
    assert(res <= lim);
    if (res == lim)
        cout << "18446744073709551616" << endl;
    else
        cout << (unsigned long long)res << endl;
    return;
}

signed main() {
    // freopen("zoo3.in", "r", stdin);
    // freopen("zoo.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    return Main(), 0;
}