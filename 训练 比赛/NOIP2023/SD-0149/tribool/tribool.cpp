// rp++ what do your do at the end of the world?
// Y@2L32#
// T#YMS@4
// node: 0+998244710

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define rep(i, n) for (decltype(n) i = 0; i < n; ++i)
#define gor(i, l, r) for (decltype(r) i = l; i < r; ++i)

#ifdef __unix
#define getchar() getchar_unlocked()
#endif

#define endl '\n'
#define rr read<int>()
#define rl read<ll>()

template<typename tp>
inline tp read() {
    tp n = 0; int f = 0, c = getchar();
    for (; !isdigit(c); c = getchar()) f |= c == '-';
    for (; isdigit(c); c = getchar()) n = (n << 3) + (n << 1) + c - '0';
    return f ? -n : n;
}

#define open(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
#define IOS ios::sync_with_stdio(false)
#define TIE cin.tie(nullptr), cout.tie(nullptr)

template<typename tp> inline tp Max(const tp a, const tp b) { return a > b ? a : b; }
template<typename tp> inline tp Min(const tp a, const tp b) { return a < b ? a : b; }
template<typename tp> inline tp Abs(const tp a) { return a < 0 ? -a : a; }

#define chmin(a, x) ((a) = Min(a, x))
#define chmax(a, x) ((a) = Max(a, x))

/*struct node {
    int who, nolim; // 0, const; 1, var; nolimit?
    // for 0
    int val;        // value
    // for 1
    int tar, cpl;   // who, is compl
    // function
    node() { who = 0, nolim = 1; }
    void setval(char op) {
        who = 0, nolim = 0;
        if (op == 'T') val = 2;
        else if (op == 'F') val = 0;
        else val = 1;
    } void setop(int t, int c) {
        who = 1, nolim = 0;
        tar = t, cpl = c;
    }
    // debug
    void debug1() {
        if (nolim) cout << "NOLIMIT" << endl;
        else if (who == 0) {
            cout << "Set by val " << val << endl;
        } else {
            cout << "Set by" << (cpl ? " !" : " ") << tar << endl;
        }
    }
};*/


struct idk {
    struct node_t {
        int isset, isval;
        int val;
        int fa, cpl;
        node_t() { isset = isval = val = fa = cpl = 0; }
    };

    vector<node_t> a;

    idk(int n) { a.resize(n + 1); }

    void set_val(int i, char op) {
        a[i].isset = a[i].isval = 1;
        if (op == 'T') a[i].val = 2;
        else if (op == 'F') a[i].val = 0;
        else a[i].val = 1;
    }

    void set_op(int i, int j, int cpl) {
        while (1) {
            if (a[j].isval) {
                // is a val
                a[i].isset = 1, a[i].isval = 1;
                a[i].val = cpl ? 2 - a[j].val : a[j].val;
                break;
            } else if (a[j].isset) {
                // not val but set => iterator
                cpl ^= a[j].cpl, j = a[j].fa;
            } else {
                // not val and not set => unknown
                a[i].isset = 1, a[i].isval = 0;
                a[i].fa = j, a[i].cpl = cpl;
                break;
            }
        }
    }

    void debug0() {
        cout << "DEBUG0: " << endl;
        for (int i = 1; i < a.size(); ++i) {
            cout << "a[" << i << "] <- ";
            if (!a[i].isset) cout << "unknown" << endl;
            else if (a[i].isval) cout << a[i].val << endl;
            else cout << (a[i].cpl ? "!a[" : "a[") << a[i].fa << "]" << endl;
        } cout << "END." << endl;
    }

    int solve(int n) {
        vector<int> f(n + 1), sz(n + 1, 1);
        vector<int> tag(n + 1, -1);
        iota(f.begin(), f.end(), 0); int cnt = n;
        function<int(int)> find = [&] (int x) -> int { return x == f[x] ? x : f[x] = find(f[x]); };
        auto merge = [&] (int a, int b) -> void {
            a = find(a), b = find(b);
            if (a == b) return (void)("chtholly");
            f[b] = a, sz[a] += sz[b], --cnt;
            if (tag[b] != -1) tag[a] = tag[b];
            return (void)("chtholly!");
        }; auto add_tag = [&] (int x, int v) -> void {
            /*x = find(x);*/ tag[x] = v;
        }; vector<pii> _g;
        /*for (int i = 1; i <= n; ++i) {
            if (!a[i].isset) continue;
            if (a[i].isval) add_tag(i, a[i].val);
            else if (!a[i].cpl) merge(i, a[i].fa);
            else if (a[i].fa == i) add_tag(i, 1);
            else _g.push_back({i, a[i].fa});
        }*/ for (int i = 1; i <= n; ++i) {
            if (!a[i].isset) continue;
            if (a[i].isval) add_tag(i, a[i].val)/*, cerr << "Tag " << i << " " << a[i].val << endl*/;
            else if (!a[i].cpl) continue/*, cerr << "Merge " << i << " " << a[i].fa << endl*/;
            else if (a[i].fa == i) add_tag(i, 1)/*, cerr << "Tag " << i << " " << 1 << endl*/;
            else _g.push_back({i, a[i].fa})/*, cerr << i << " <-> " << a[i].fa << endl*/;
        } for (int i = 1; i <= n; ++i) {
            if (!a[i].isset) continue;
            if (!a[i].isval && !a[i].cpl) merge(i, a[i].fa)/*, cerr << "Merge " << i << " " << a[i].fa << endl*/;
        } vector<vector<int>> g(n + 1);
        for (pii i : _g) {
            i.first = find(i.first), i.second = find(i.second);
            g[i.first].push_back(i.second), g[i.second].push_back(i.first);
        } auto tag_bak = tag;
        function<void(int)> dfs_spe = [&] (int u) -> void {
            tag[u] = 1; for (int v : g[u]) {
                if (tag[v] == -1) dfs_spe(v);
            } return (void)("are you busy?");
        }; function<bool(int, int)> dfs = [&] (int u, int c) -> bool {
            tag[u] = c; for (int v : g[u]) {
                if (tag[v] == -1) { if (!dfs(v, 2 - c)) return false; }
                else if (tag[v] == c) return false;
            } return true;
        }; for (int i = 1; i <= n; ++i) {
            if (f[i] != i) continue;
            if (tag_bak[i] == -1) continue;
            if (tag_bak[i] == 1) dfs_spe(i);
            else dfs(i, tag_bak[i]);
        } for (int i = 1; i <= n; ++i) {
            if (f[i] != i) continue;
            if (tag[i] != -1) continue;
            if (!dfs(i, 0)) dfs_spe(i);
        } int ans = 0; for (int i = 0; i <= n; ++i) {
            if (f[i] != i) continue;
            if (tag[i] == 1) ans += sz[i];
        } return ans;
    }
};

int solve() {
    int n = rr, m = rr;
    idk q(n); rep(_, m) {
        char op[3]; scanf("%s", op);
        if (op[0] == '+' || op[0] == '-') {
            int i = rr, j = rr, cpl = op[0] == '-';
            q.set_op(i, j, cpl);
        } else q.set_val(rr, op[0]);
    } return q.solve(n);
}

namespace sub2 {
    int solve() {
        int n = rr, m = rr;
        vector<char> op(n + 1, 'T');
        rep(_, m) {
            char o[3];
            scanf("%s", o);
            int i = rr;
            op[i] = o[0];
        } int ans = 0;
        for (char i : op) ans += i == 'U';
        return ans;
    }
}

/*namespace sub3 {
    int solve() {
        int n = rr, m = rr;
        vector<char> op(n + 1, 'T');
        vector<int> isu(n + 1);
        rep(_, m) {
            char o[3];
            scanf("%s", o);
            if (o[0] == 'U') {
                int i = rr;
                op[i] = 'U';
                isu[i] = 1;
            } else {
                int i = rr, j = rr;
                if (op[j] == 'U' && op[i] == 'U' && isu[i]) isu[i] = 0;
                if (op[j] != 'U' && isu[i]) isu[j] = 1;
                op[i] = op[j];
            }
        } int ans = 0;
        for (char i : op) ans += isu[i];
        return ans;
    }
}*/

signed main() {
    // calc each var to var
    // forall var: self-cir: 1
    // forall var: con: edge
    // forall con: bi-graph, if not: 1, else: gen
    open("tribool");
    int c = rr, t = rr;
    if (c == 3 || c == 4) { while (t--) printf("%d\n", sub2::solve()); }
    //else if (c == 5 || c == 6) { while (t--) printf("%d\n", sub3::solve()); }
    //else { while (t--) printf("%d\n", solve()); }
    return 0;
}
