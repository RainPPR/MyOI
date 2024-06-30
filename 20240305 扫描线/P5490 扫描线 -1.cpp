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

#define x first
#define y second

using pii = pair<int, int>;

const int N = 1e5 + 10;

int n;
pii l[N], r[N];

ll range(int a, int b) {
    vector<pii> q;
    rep(i, n) if (l[i].x <= a && r[i].x >= b)
        q.push_back({l[i].y, r[i].y});
    if (q.empty()) return 0;
    sort(q.begin(), q.end());
    int st = q[0].x, ed = q[0].y;
    ll res = 0;
    gor(i, 1, (int)q.size()) {
        if (q[i].x <= ed) ed = max(ed, q[i].y);
        else res += ed - st, tie(st, ed) = q[i];
    } return (res + ed - st) * (b - a);
}

signed main() {
    n = ri;
    vector<int> xs;
    rep(i, n) {
        l[i].x = ri, l[i].y = ri;
        r[i].x = ri, r[i].y = ri;
        xs.push_back(l[i].x);
        xs.push_back(r[i].x);
    }
    sort(xs.begin(), xs.end());
    ll res = 0;
    for (int i = 0; i + 1 < xs.size(); ++i)
        if (xs[i] != xs[i + 1]) res += range(xs[i], xs[i + 1]);
    printf("%lld\n", res);
    return 0;
}
