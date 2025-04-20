#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

using ll = long long;

struct emm {
    int l, r;
};

bool cmpr(const emm &a, const emm &b) {
    return a.r < b.r;
}

signed main() {
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n; vector<emm> a(n);
    cout << "EERR" << n << endl << endl;
    for (int i = 0; i < n; ++i) cin >> a[i].l >> a[i].r;
    cout << "EERR" << endl;
    sort(a.begin(), a.end(), cmpr);
    set<int> setofr; ll ans = 0;
    setofr.insert(2e9);
    for (int i = 0; i < n; ++i) {
        int l = a[i].l, r = a[i].r;
        cout << "WOW ";
        ans += distance(setofr.lower_bound(l), setofr.begin());
        cout << l << " " << r << ": " << distance(setofr.lower_bound(l), setofr.begin()) << endl;
        setofr.insert(r);
    }
    cout << ans << endl;
    return 0;
}
