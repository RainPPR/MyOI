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

template<typename tp>
inline tp read() {
    tp n = 0; int f = 0, c = gc();
    for (; !isdigit(c); c = gc()) f |= c == '-';
    for (; isdigit(c); c = gc()) n = (n << 3) + (n << 1) + c - '0';
    return f ? -n : n;
}

vector<ll> a;

pair<int, ll> build_segment_tree(int l, int r) {
    if (l == r) return {a[l] , a[l]};
    int mid = (l + r) >> 1;
    int lval, rval; ll lsum, rsum;
    tie(lval, lsum) = build_segment_tree(l, mid);
    tie(rval, rsum) = build_segment_tree(mid+1, r) ;
    return {max(lval, rval), lsum + rsum + max(lval, rval)};
}

signed main() {
    auto modify = [&] (int x, int v) { a[x] = v; };
    auto query = [&] (int l, int r) { return build_segment_tree(l, r).second; };
    int n = ri, q = ri; a.resize(n + 1);
    rep(i, n) a[i + 1] = ri;
    while (q--) {
        int op = ri, x = ri, y = ri;
        if (op) modify(x, y);
        else printf("%lld\n", query(x, y));
    } return 0;
}
