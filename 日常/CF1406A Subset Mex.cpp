#define NDEBUG

#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

#ifdef NDEBUG
#define D(x) ({ cerr << "| DEBUG #" << __LINE__ << " IN " << __FUNCTION__ << "() \t| \t" << #x << " = " << (x) << endl; void(0); })
#else
#define D(x) ({ void(0); })
#endif

constexpr int N = 110;

array<int, N> a, b;

void Main() {
    int n;
    cin >> n;
    a.fill(0), b.fill(0);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++(a[x] ? b : a)[x];
    }
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if (!a[i]) {
            ans += i;
            break;
        }
    }
    for (int i = 0; i < N; ++i) {
        if (!b[i]) {
            ans += i;
            break;
        }
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T; cin >> T;
    while (T--) Main();
    return 0;
}
