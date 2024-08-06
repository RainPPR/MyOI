#ifndef M_DEBUG
#define NDEBUG 1
#define FAST_IO 1
#define D(x) ({ void(0); })
#else
#define D(x) ({ cerr << "| DEBUG #" << __LINE__ << " IN " << __FUNCTION__ << "() \t| \t" << #x << " = \t[" << (x) << "]\n"; void(0); })
#endif

#include <bits/stdc++.h>

#ifdef FAST_IO
#define endl "\n"
#endif

using namespace std;

// -----------------------------------------------------------------------------

void Main() {
    int n, x;
    cin >> n >> x;
    vector<int> m(n);
    for (int &i : m) cin >> i;
    set<int> a, b;
    int ans = 3;
    for (int i : m) {
        if (a.count(i))
            ans = min(ans, 0);
        if (b.count(i) || a.count(i & x))
            ans = min(ans, 1);
        if (b.count(i & x))
            ans = min(ans, 2);
        a.insert(i);
        b.insert(i & x);
    }
    cout << (ans == 3 ? -1 : ans) << endl;
}

// -----------------------------------------------------------------------------

signed main() {
    #ifdef FAST_IO
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    #endif
    Main();
    return 0;
}