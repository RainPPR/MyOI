#include <bits/stdc++.h>

using namespace std;

#define gc() getchar_unlocked()

#define rr read()
inline int read() {
    int n = 0, c = gc();
    while (!isdigit(c)) c = gc();
    for (; isdigit(c); c = gc()) n = (n << 3) + (n << 1) + c - '0';
    return n;
}

vector<int> div(int x) {
    int t = sqrt(x); vector<int> r;
    for (int i = 2; i <= t; ++i)
        while (x % i == 0)
            x /= i, r.push_back(i);
    if (x > 1) r.push_back(x);
    return r;
}

void solve(int n) {
    auto r = div(n);
    if (r.size() == 1) printf("NHM\n");
    else if (r.size() == 2) printf("HNM\n");
    else printf("NHNM\n");
}

signed main() {
    int T = rr;
    while (T--)
    solve(rr);
    return 0;
}
