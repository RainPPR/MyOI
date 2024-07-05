#include <bits/stdc++.h>

using namespace std;

#define lowbit(x) ((x) & -(x))

using ll = long long;
constexpr int N = 3e5 + 10;

int n, s[N];

int sum(int x) {
    int r = 0;
    for (; x; x -= lowbit(x)) r += s[x];
    return r;
}

void add(int x) {
    for (; x <= n; x += lowbit(x)) ++s[x];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n; vector<int> a(n);
    ll res = 0; for (int &i : a) cin >> i, ++i;
    for (int i = 0; i < n; ++i) res += sum(a[i]), add(a[i]);
    cout << res << endl;
    return 0;
}