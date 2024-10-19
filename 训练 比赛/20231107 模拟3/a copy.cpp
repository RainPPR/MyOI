#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define gor(i, l, r) for (auto i = l; i < r; ++i)

#define gc() getchar_unlocked()
#define endl '\n'

#define rr read()
inline int read() {
    int n = 0, f = 0, c = gc();
    for (; !isdigit(c); c = gc()) f |= c == '-';
    for (; isdigit(c); c = gc()) n = (n << 3) + (n << 1) + c - '0';
    return f ? -n : n;
}

signed main() {
    int n = rr;
    vector<int> a(n + 2);
    a[0] = -1, a[n + 1] = 2e9;
    rep(i, n) a[i + 1] = rr;
    sort(a.begin(), a.end());
    rep(i, n + 1) {
        int k = (a[i] + 1) - (a[i] & 1) + 1;
        if (a[i + 1] > k + 1) printf("%d\n", k >>= 1), exit(0);
    } return 0;
}
