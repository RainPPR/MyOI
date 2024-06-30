#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (decltype(n) i = 0; i < n; ++i)
#define gor(i, l, r) for (decltype(r) i = l; i < r; ++j)

#define gc() getchar_unlocked()
#define endl '\n'

#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
#define Abs(x) ((x) < 0 ? -(x) : (x))
#define Swap(a, b) ((a) ^= (b), (b) ^= (a), (a) ^= (b))

#define rr read()
inline int read() {
    int n = 0, f = 0, c = gc();
    for (; !isdigit(c); c = gc()) f |= c == '-';
    for (; isdigit(c); c = gc()) n = (n << 3) + (n << 1) + c - '0';
    return f ? -n : n;
}

const int N = 1010;

int n, m;
int col[N], lc[N], rc[N], arr[N];

bool solve() {
    for (int pos = 1)
}

signed main() {
    n = rr, m = rr;
    for (int i = 1, op; i <= n; ++i) {
        col[i] = rr, op = rr;
        if (op == 2) arr[i] = rr;
        else lc[i] = rr, rc[i] = rr;
    } if (!solve()) printf("-1\n");
}