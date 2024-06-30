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
    int n = rr, mid = rr, a; printf("%d\n", mid);
    priority_queue<int, vector<int>, less<int>>    cmin;
    priority_queue<int, vector<int>, greater<int>> cmax;
    for (int i = 0; i < n - 1; ++i) {
        ((a = rr) < mid) ? cmin.push(a) : cmax.push(a);
        while (cmin.size() > cmax.size()) {
            a = cmin.top(); cmin.pop();
            cmax.push(mid); mid = a;
        } while (cmax.size() > cmin.size()) {
            a = cmax.top(); cmax.pop();
            cmin.push(mid); mid = a;
        } if (i & 1) printf("%d\n", mid);
    } return 0;
}