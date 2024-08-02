老师的题解：[https://www.luogu.com/paste/v3qob8cv](https://www.luogu.com/paste/v3qob8cv)。

## A seq

观察图形，注意到数据范围内的结果一定是小于 500 的。

PS：而且直觉上应该大部分不超过 100 吧（）

模拟题意即可。

```cpp
int init(int n) {
    vector<int> f(n + 1);
    f[0] = f[1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int fi = 1; ; ++fi) {
            bool flag = true;
            for (int k = 1; i - 2 * k >= 0; ++k) {
                if (fi - f[i - k] == f[i - k] - f[i - 2 * k]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                f[i] = fi;
                break;
            }
        }
    }
    return f[n];
}
```

不知道复杂度对不对，然后发现极限数据不到半秒出来，然后就过了。

另外，[OEIS A229037](https://oeis.org/A229037) 是个好东西。

## B lcm

类似质数筛，每个人一定会对后面一个等差数列造成影响。

我们排除掉 $1$，每个数 $-1$ 后把倍数直接杀掉，那么就是最小人数。

我们暴力统计，最坏情况下一定是 $x_i$ 尽可能小，即 $x_i=i$，

即便此时，复杂度是，

$$
\sum_{i=1}^n{n\over i}=n\sum_{i=1}^n{1\over i}=nH_n=\mathcal O(n\ln n)
$$

为一个调和级数，复杂度可过。

注意如果 $n=1$，即只记录了一天，但还是需要有人的，特判即可。

```cpp
int n;
cin >> n;
int cnt = 0;
if (n == 1) puts("1"), exit(0);
for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    if (x == 1) continue;
    --x;
    if (vis[x]) continue;
    for (int j = x; j < N; j += x) vis[j] = 1;
    ++cnt;
}
cout << cnt << endl;
```

## C set

设 $f(S)$ 表示集合 $S$ 中的点的最大独立集。

记 $E(x)$ 表示与 $x$ 互斥的点，即有连边的点集，

我们钦定只考虑 $S$ 中的任意一个点 $x\in S$ 分讨，

+ 若不选 $x$，$f(S)\gets f(S\setminus\{x\})$.

+ 若选 $x$，则一定不选 $E(x)$，$f(S)\gets f(S\setminus E(x))$.

直接转移即可，时间复杂度 $\mathcal O(2^n)$。

```cpp
int n, m;

int adj[26], dp[1 << 26];

void Main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u] |= 1 << v;
        adj[v] |= 1 << u;
    }
    int ans = 0;
    for (int i = 1; i < (1 << n); ++i) {
        int j = __builtin_ctz(i), t = 1 << j;
        ans += dp[i] = max(dp[i ^ t], dp[i & ~(adj[j] | t)] + 1);
    }
    cout << ans << endl;
}
```

## D class

容易发现题意就是最大子矩阵和。

这道题我做了一群部分分，其中一部分如下，

+ 部分分一：直接枚举上下左右四个边界，复杂度 $\mathcal O(n^4)$.

+ 部分分二：考虑悬线法，枚举悬线下断点和长度，复杂度 $\mathcal O(n^3)$.

+ 部分分三：枚举上下边界，用列的前缀和计算，跑最大字段和即可，复杂度 $\mathcal O(n^3)$.

然后，第三个部分分就提醒我们做优化了。

注意到枚举下边界是 $\mathcal O(n)$ 的，而此题有性质，

下边界上方的点数量也是 $\mathcal O(n)$ 而分散在 $\mathcal O(n^2)$ 的空间中。

在这 $\mathcal O(n^2)$ 的空间中，使用前缀和显然是不优的，

于是我们用一点数据结构来维护、快速计算最大字段和：线段树。

线段树维护最大字段和请见 [SP1043 GSS1](https://www.luogu.com.cn/problem/SP1043)、[SP1716 GSS3](https://www.luogu.com.cn/problem/SP1716) 这两道题。

注意离散化一下即可。

```cpp
using pii = pair<int, int>;

constexpr int N = 2010;

int n, m;

namespace seg {
    struct val_t {
        int sum, ans;
        int pre, suf;
        val_t() = default;
        val_t(int x): sum(x), ans(x), pre(x), suf(x) {}
        friend val_t operator +(const val_t &a, const val_t &b) {
            val_t res;
            res.sum = a.sum + b.sum;
            res.pre = max(a.pre, a.sum + b.pre);
            res.suf = max(b.suf, b.sum + a.suf);
            res.ans = max({a.ans, b.ans, a.suf + b.pre});
            return res;
        }
    };
    #define ls(x) ((x) << 1)
    #define rs(x) ((x) << 1 | 1)
    struct node {
        int l, r;
        val_t val;
    } a[N << 2];
    void push_up(int k) {
        a[k].val = a[ls(k)].val + a[rs(k)].val;
    }
    void build(int k, int l, int r) {
        a[k].l = l, a[k].r = r;
        if (l == r) return void(a[k].val = val_t(0));
        int mid = l + r >> 1;
        build(ls(k), l, mid);
        build(rs(k), mid + 1, r);
        push_up(k);
    }
    void modify(int k, int x, int v) {
        int l = a[k].l, r = a[k].r;
        if (l == r) return void(a[k].val = val_t(v));
        int mid = l + r >> 1;
        if (x <= mid) modify(ls(k), x, v);
        else modify(rs(k), x, v);
        push_up(k);
    }
    void rebuild() {
        build(1, 1, m);
    }
    void insert(int x, int v) {
        modify(1, x, v);
    }
    int calc() {
        return a[1].val.ans;
    }
}

vector<pii> app[N];

int solev() {
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        seg::rebuild();
        for (int j = i; j; --j) {
            for (auto t : app[j])
                seg::insert(t.first, t.second);
            ans = max(ans, seg::calc());
        }
    }
    return ans;
}

void Main() {
    vector<int> s[2];
    cin >> n;
    vector<pii> v1(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        v1[i] = {x, y};
        s[0].push_back(x);
        s[1].push_back(y);
    }
    cin >> m;
    vector<pii> v2(m);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        v2[i] = {x, y};
        s[0].push_back(x);
        s[1].push_back(y);
    }
    sort(s[0].begin(), s[0].end());
    s[0].erase(unique(s[0].begin(), s[0].end()), s[0].end());
    sort(s[1].begin(), s[1].end());
    s[1].erase(unique(s[1].begin(), s[1].end()), s[1].end());
    #define get_id(x, k) ({ lower_bound(s[k].begin(), s[k].end(), x) - s[k].begin() + 1; })
    int a, b;
    cin >> a >> b;
    n = m = 0;
    for (auto t : v1) {
        int x = get_id(t.first, 0);
        int y = get_id(t.second, 1);
        app[x].emplace_back(y, a);
        n = max(n, x), m = max(m, y);
    }
    for (auto t : v2) {
        int x = get_id(t.first, 0);
        int y = get_id(t.second, 1);
        app[x].emplace_back(y, -b);
        n = max(n, x), m = max(m, y);
    }
    cout << solev() << endl;
}
```