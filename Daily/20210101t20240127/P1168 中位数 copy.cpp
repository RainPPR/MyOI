#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (decltype(n) i = 0; i < (n); ++i)
#define gor(i, l, r) for (decltype(r) i = (l); i < (r); ++i)

#define gc() getchar_unlocked()
#define endl '\n'

#define rr read<int>()
#define rl read<ll>()

template<typename tp>
inline tp read() {
    tp n = 0; int f = 0, c = gc();
    for (; !isdigit(c); c = gc()) f |= c == '-';
    for (; isdigit(c); c = gc()) n = (n << 3) + (n << 1) + c - '0';
    return f ? -n : n;
}

signed main() {
    int n = rr; set<int> a;
    for (int i = 1; i <= n; ++i) {
        a.emplace(rr); if (i & 1)
        printf("%d\n", *next(a.begin(), i >> 1));
    } return 0;
}