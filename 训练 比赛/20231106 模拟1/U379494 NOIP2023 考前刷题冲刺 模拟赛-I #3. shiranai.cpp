#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define gor(i, l, r) for (auto i = l; i < r; ++i)

#define endl '\n'
#define gc() getchar_unlocked()

#define rr read()
inline int read() {
    int n = 0, f = 0, c = gc();
    for (; !isdigit(c); c = gc()) f |= c == '-';
    for (; isdigit(c); c = gc()) n = (n << 3) + (n << 1) + c - '0';
    return n;
}

using vi = vector<int>;

const int N = 5e5 + 10;

int n;
vector<int> a;

namespace lids {
    int f[N][2];
    int g[N][2];
    pair<int, int> solve() {
        int lis = 1, lds = 1;
        rep(i, n) {
            f[i][0] = f[i][1] = 1, g[i][0] = g[i][1] = -1;
            rep(j, i)
                if (a[j] < a[i] && f[i][0] < f[j][0] + 1) {
                    f[i][0] = f[j][0] + 1;
                    g[i][0] = j;
                } else if (a[j] > a[i] && f[i][1] < f[j][1] + 1) {
                    f[i][1] = f[j][1] + 1;
                    g[i][1] = j;
                }
            lis = max(lis, f[i][0]);
            lds = max(lds, f[i][1]);
        } return {lis, lds};
    }
}

int lis, lds;
int vis[N];

vector<int> p, q;

bool dfs2(int k, int l) {
    if (l == lds) return true;
    int lt = k == -1 ? 1e9 : a[k];
    gor(i, k + 1, n) {
        if (a[i] < lt && !vis[i]) {
            q.push_back(i);
            if (dfs2(i, l + 1)) return true;
            q.pop_back();
        }
    } return false;
}

bool dfs1(int k, int l) {
    if (l == lis) {
        if (dfs2(-1, 0)) return true;
        return false;
    } int lt = k == -1 ? -1 : a[k];
    gor(i, k + 1, n) {
        if (a[i] > lt) {
            vis[i] = 1, p.push_back(i);
            if (dfs1(i, l + 1)) return true;
            vis[i] = 0, p.pop_back();
        }
    } return false;
}

void print() {
    printf("%d\n", lis);
    for (int i : p) printf("%d ", i + 1);
    printf("\n%d\n", lds);
    for (int i : q) printf("%d ", i + 1);
}

signed main() {
    n = rr; a.resize(n);
    rep(i, n) a[i] = rr;
    tie(lis, lds) = lids::solve();
    if (!dfs1(-1, 0)) printf("-1\n");
    else print();
    return 0;
}
