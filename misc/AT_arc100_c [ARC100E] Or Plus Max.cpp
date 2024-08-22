#pragma GCC optimize("O3","Ofast","unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,bmi,bmi2,lzcnt,tune=native")

#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

#define gc() getchar()

inline int read() {
    int n = 0, c = gc();
    while (!isdigit(c)) c = gc();
    for (; isdigit(c); c = gc()) n = n * 10 + c - '0';
    return n;
}

constexpr int N = 1 << 19;

int a[N], b[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    const int n = read(), m = 1 << n;
    for (int i = 0; i < m; ++i) a[i] = read();
    for (int i = 0; i < m; ++i) for (int j = i + 1; j < m; ++j) if (a[i] + a[j] > b[i | j]) b[i | j] = a[i] + a[j];
    for (int i = 1; i < m; ++i) cout << b[i] << endl, b[i + 1] = max(b[i + 1], b[i]);
    return 0;
}