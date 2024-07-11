#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e5 + 10;

#define lowbit(x) ((x) & -(x))

int n, s[N];

// sum [1, x], x <= n
int query(int x) {
    int r = 0;
    for (; x; x -= lowbit(x)) r += s[x];
    return r;
}

// [x] += v
int modify(int x, int v) {
    for (; x <= n; x += lowbit(x)) s[x] += v;
}

int add(int p, int q, int v) {
    modify(p, v);
    modify(q + 1, -v);
}

int at(int x) {
    return query(x);
}

signed main() {
    return 0;
}