#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n, a; cin >> n;
    unordered_map<int, int> vcc;
    for (int i = 1; i <= n; ++i) cin >> a, ++vcc[a];
    int m; cin >> m;
    vector<int> b(m), c(m);
    for (int &i : b) cin >> i;
    for (int &i : c) cin >> i;
    int bi, hp = -1, bhp = -1;
    #define gett(a, b) (a.count(b) == 0 ? 0 : a[b])
    for (int i = 0; i < m; ++i) {
        int hpt = gett(vcc, b[i]), bhpt = gett(vcc, c[i]);
        if (hpt > hp) bi = i, hp = hpt, bhp = bhpt;
        else if (hpt == hp and bhpt > bhp) bi = i, bhp = bhpt;
    }
    cout << bi + 1 << endl;
    return 0;
}