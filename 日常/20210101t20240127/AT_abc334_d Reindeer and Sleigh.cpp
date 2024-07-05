#pragma GCC optimize(1,2,"Ofast,fast-math")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

using vi = vector<int>;
using vl = vector<ll>;

#define rep(i, n) for (decltype(n) i = 0; i < n; ++i)
#define gor(i, l, r) for (decltype(r) i = l; i < r; ++i)

#define range(x) x.begin(), x.end()

#define endl '\n'
#define gc() getchar_unlocked()

#define ur uread<unsigned>()
#define url uread<ull>()

template<typename tp>
inline tp uread() {
    tp n = 0; int c = gc();
    while (!isdigit(c)) c = gc();
    while (isdigit(c)) n = n * 10 + c - '0', c = gc();
    return n;
}

signed main() {
    int n = ur, q = ur;
    vector<ll> R(n);
    for (ll &i : R) i = ur;
    sort(range(R));
    partial_sum(range(R), R.begin());
    while (q--) {
        auto it = upper_bound(range(R), url);
        if (it == R.begin()) printf("0\n");
        else printf("%ld\n", it - R.begin());
    } return 0;
}
