#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define gor(i, l, r) for (auto i = (l); i < (r); ++i)
#define xin(i, a) for (auto i : a)

#define gc() getchar_unlocked()
#define endl '\n'

#define ri read<int>()
#define rl read<ll>()

#define chmin(a, x) a = min(a, x)
#define chmax(a, x) a = max(a, x)

template<typename tp>
inline tp read() {
    tp n = 0; int f = 0, c = gc();
    for (; !isdigit(c); c = gc()) f |= c == '-';
    for (; isdigit(c); c = gc()) n = (n << 3) + (n << 1) + c - '0';
    return f ? -n : n;
}

signed main() {
    int n = ri, m = ri;
    vector<int> f(n + 1);
    rep(i, n) f[i + 1] = i + 1;
    int cnt = n;
    function<int(int)> find = [&] (int x) { return x == f[x] ? x : f[x] = find(f[x]); };
    auto merge = [&] (int a, int b) { a = find(a), b = find(b), f[a] = b; cnt -= a != b; };
    while (m--) merge(ri, ri);
    printf("%d\n", cnt - 1);
    return 0;
}
