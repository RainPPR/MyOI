#pragma GCC optimize("Ofast,fast-math,-ffast-math")
#pragma GCC optimize("no-stack-protector,-funsafe-loop-optimizations")
#pragma GCC optimize("-fthread-jumps,unroll-loops,-funroll-loops")
#pragma GCC optimize("-falign-jumps,-falign-loops,-falign-labels,-falign-functions")
#pragma GCC optimize("-fexpensive-optimizations,-fdelete-null-pointer-checks")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

constexpr ll a[20] = {0, 3, 12, 48, 192, 768, 3072, 12288, 49152, 196608, 786432, 3145728, 12582912, 50331648, 201326592, 805306368, 3221225472, 12884901888, 51539607552};

signed main() {
	freopen("math.in","r",stdin);
	freopen("math.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s; cin >> s; int n = s.size();
    ll r = 0; rep(i, n) {
        if (i == n - 1) r += min(3, s[i] - '0');
        else r += a[n - i - 1] * min(4, s[i] - '0');
        if (s[i] > '3') break;
    } cout << r << endl;
    return 0;
}
