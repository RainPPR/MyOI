#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

constexpr int N = 1e5 + 10;
constexpr int K = 17;

int n, a[N];

namespace trie {
    int ch[N * K][2], idx;
    int cnt[N * K];

    void add(int x) {
        int root = 0;
        for (int i = K; ~i; --i) {
            int c = (x >> i) & 1;
            if (!ch[root][c]) ch[root][c] = ++idx;
            root = ch[root][c], ++cnt[root];
        }
    }

    int get(int k) {
        int root = 0, res = 0;
        for (int i = K; ~i; --i) {
            int go = 0;
            if (cnt[ch[root][0]] < k)
                k -= cnt[ch[root][0]], go = 1;
            root = ch[root][go];
            --cnt[root];
            res = res << 1 | go;
        }
        return res;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> n; vector<int> ans(n);
    for (int i = 1; i <= n; ++i) trie::add(i);
    copy_n(istream_iterator<int>(cin), n + 1, a + 2);
    for (int i = n; i >= 1; --i) ans[i - 1] = trie::get(a[i] + 1);
    for (int i = 1; i <= n; ++i) cout << ans[i - 1] << endl;
    return 0;
}