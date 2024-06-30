#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define gor(i, l, r) for (int i = int(l); i < int(r); ++i)

#define endl "\n"
#define gc() getchar_unlocked()

#define SWS ios::sync_with_stdio(false)
#define TIE cin.tie(nullptr), cout.tie(nullptr)

inline int readint() {
    int n = 0, c = gc();
    while (!isdigit(c)) c = gc();
    for (; isdigit(c); c = gc()) n = (n << 3) + (n << 1) + c - '0';
    return n;
}

signed main() {
    int n = readint();
    vector<int> a(n + 1);
    rep(i, n) a[i] = readint();
    int res = 0;
    rep(i, n) res += a[i] > a[i + 1];
    printf("%d\n", res);
    return 0;
}
