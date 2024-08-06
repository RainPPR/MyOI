#define NDEBUG

#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

#ifdef NDEBUG
#define D(x) ({ void(0); })
#else
#define D(x) ({ cerr << "| DEBUG #" << __LINE__ << " IN " << __FUNCTION__ << "() \t| \t" << #x << " = " << (x) << endl; void(0); })
#endif

constexpr int MAXN = 2e5 + 10;

int N, M, a[MAXN];

namespace decmp {
    int UP, siz, cnt;
    int belong[MAXN];
    int L[MAXN], R[MAXN];
    void init() {
        UP = N + 5, siz = sqrt(UP), cnt = (UP - 1) / siz + 1;
        for (int i = 1; i <= UP; ++i) belong[i] = (i - 1) / siz + 1;
        for (int i = 1; i <= cnt; ++i) R[i] = i * siz, L[i] = R[i] - siz + 1;
        R[cnt] = UP;
    }
    int bucket[MAXN], appr[MAXN];
    void add(int x) {
        if (x > UP) return;
        if (!bucket[x]) ++appr[belong[x]];
        ++bucket[x];
    }
    void del(int x) {
        if (x > UP) return;
        --bucket[x];
        if (!bucket[x]) --appr[belong[x]];
    }
    int get_ans() {
        int inner = 1;
        while (inner <= cnt && appr[inner] == R[inner] - L[inner] + 1) ++inner;
        for (int i = L[inner]; i <= R[inner]; ++i) if (!bucket[i]) return i;
        return UP + 1;
    }
}

namespace mo_algo {
    int siz, belong[MAXN];
    struct query {
        int id, l, r;
        friend bool operator <(const query &a, const query &b) {
            if (mo_algo::belong[a.l] != mo_algo::belong[b.l]) return a.l < b.l;
            return mo_algo::belong[a.l] & 1 ? a.r < b.r : a.r > b.r;
        }
    } Q[MAXN];
    void init() {
        siz = max(1, int(N / sqrt(2 * M / 3.0)));
        for (int i = 1; i <= N; ++i) belong[i] = (i - 1) / siz + 1;
        sort(Q + 1, Q + M + 1);
        decmp::init();
    }
}

using namespace mo_algo;

int ans[MAXN];

void Main() {
    cin >> N >> M;
    vector<int> s(N);
    for (int i = 1; i <= N; ++i) cin >> a[i], s[i - 1] = a[i];
    for (int i = 1; i <= M; ++i) cin >> Q[i].l >> Q[i].r, Q[i].id = i;
    init();
    int l = 1, r = 0;
    for (int i = 1; i <= M; ++i) {
        int p = Q[i].l, q = Q[i].r;
        while (p < l) decmp::add(a[--l] + 1);
        while (q > r) decmp::add(a[++r] + 1);
        while (p > l) decmp::del(a[l++] + 1);
        while (q < r) decmp::del(a[r--] + 1);
        ans[Q[i].id] = decmp::get_ans() - 1;
    }
    copy_n(ans + 1, M, ostream_iterator<int>(cout, "\n"));
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    // int T; cin >> T;
    int T = 1;
    while (T--) Main();
    return 0;
}