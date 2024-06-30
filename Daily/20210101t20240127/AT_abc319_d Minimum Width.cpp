#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define gc() getchar_unlocked()
#define rr read()

inline int read() {
    int n = 0, c = gc();
    while (!isdigit(c)) c = gc();
    while (isdigit(c)) n = n * 10 + c - '0', c = gc();
    return n;
}

int n, m;
vector<int> a;

bool check(ll w) {
    ll s = 1, sz = 0;
    for (int &i : a)
    if ((sz += i + 1) > w &&
        (sz = i, ++s) > m)
        return 0;
    return 1;
}

int main() {
    n = rr, m = rr; a.resize(n);
    ll l = 1, r = 1e15;
    for (int &i : a) l = max(l, 1ll * (i = rr));
    --a[0]; while (l < r) {
        ll mid = l + (r - l >> 1);
        if (check(mid)) r = mid;
        else l = mid + 1;
    } printf("%lld\n", l);
    return 0;
}
