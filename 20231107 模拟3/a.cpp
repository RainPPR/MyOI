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
    unordered_set<int> a;
    rep(i, n) a.insert(rr);
    rep(i, 1e9)
    if (!a.count(i + i) && !a.count(i + i + 1))
        printf("%d\n", i), exit(0);
    return 0;
}
