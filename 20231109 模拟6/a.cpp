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

#define chmin(a, x) a = min(a, x)
#define chmax(a, x) a = max(a, x)

template<typename tp>
inline tp read() {
    tp n = 0; int f = 0, c = gc();
    for (; !isdigit(c); c = gc()) f |= c == '-';
    for (; isdigit(c); c = gc()) n = (n << 3) + (n << 1) + c - '0';
    return f ? -n : n;
}

signed main() {
    int n = ri, isame = -1;
    cout << n << endl;
    vector<int> a(n);
    vector<int> appear(1010);
    rep(i, n) {
        a[i] = ri;
        if (++appear[a[i]] > 1) isame = a[i];
    } if (isame != -1) {
        printf("1 1\n");
        int i = 0;
        while (a[i] != isame) ++i;
        printf("%d\n", ++i);
        while (a[i] != isame) ++i;
        printf("%d\n", i + 1);
        return 0;
    } else if (n == 2) {
        printf("-1\n");
        return 0;
    }

    printf("-1\n");
    return 0;
}
