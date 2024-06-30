#include <bits/stdc++.h>

using namespace std;

struct my_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }

  size_t operator()(pair<uint64_t, uint64_t> x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x.first + FIXED_RANDOM) ^
           (splitmix64(x.second + FIXED_RANDOM) >> 1);
  }
};

mt19937 rng(time(0));

using ll = long long;
using grid = pair<int, int>;

struct emm {
    ll x, y;
    emm() = default;
    emm(ll x, ll y): x(x), y(y) {}
    friend ll operator *(const emm &a, const emm &b) {
        return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    }
};

struct fvec {
    emm arr[5]; int tot;
    void push_back(const emm &x) { arr[tot++] = x; }
    emm operator [](int k) { return arr[k]; }
};

ll qwq = 1e18;
double ans = 1e10;

void upd_ans(const emm &a, const emm &b) {
    ll dist = a * b;
    if (dist < qwq) ans = sqrt(dist), qwq = dist;
}

vector<emm> a;

unordered_map<grid, fvec, my_hash> ump;

#define group(e, t) make_pair(e.x / (int)t, e.y / (int)t)

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n; a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i].x >> a[i].y;
    shuffle(a.begin(), a.end(), rng);
    for (int i = 0; i < n; ++i) {
        double lt = ans;
        int tx, ty; tie(tx, ty) = group(a[i], lt);
        for (int kx = tx - 1; kx <= tx + 1; ++kx) {
            for (int ky = ty - 1; ky <= ty + 1; ++ky) {
                auto eq = make_pair(kx, ky);
                if (!ump.count(eq)) continue;
                for (int k = 0; k < ump[eq].tot; ++k) upd_ans(a[i], ump[eq][k]);
            }
        }
        if (ans == 0) break;
        if (ans != lt) {
            ump = decltype(ump)();
            for (int j = 0; j < i; ++j) ump[group(a[j], ans)].push_back(a[j]);
        }
        ump[group(a[i], ans)].push_back(a[i]);
    }
    cout << ans << endl;
    return 0;
}