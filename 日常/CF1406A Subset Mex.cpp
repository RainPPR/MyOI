#define NDEBUG

#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

#ifdef NDEBUG
#define D(x) ({ cerr << "| DEBUG #" << __LINE__ << " IN " << __FUNCTION__ << "() \t| \t" << #x << " = " << (x) << endl; void(0); })
#else
#define D(x) ({ void(0); })
#endif

template<typename it>
it m_find(it l, it r) {
    for (int i = 0; l != r; ++i, ++l)
        if (*l != i) return l;
    return r;
}

void Main() {
    int n;
    cin >> n;
    vector<int> a(n);
    copy_n(istream_iterator<int>(cin), n, a.begin());
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    auto it = m_find(a.begin(), a.end());
    int ans = 0;
    if (it == a.begin()) ans = *a.begin() - 1;
    else if (it == a.end()) ans = n;
    else ans = it - a.begin();
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while (T--) Main();
    return 0;
}
