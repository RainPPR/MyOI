#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

using ll = long long;

#define int ll

int n, x;

struct pt {
    int a, p;
    int b, q;
};

vector<pt> process;

bool check(int W) {
    int rest = x;
    for (auto [a, p, b, q] : process) {
        int cost = rest + 1;
        for (int x0 = 0; x0 < b; ++x0) {
            int w = (max(0ll, W - a * x0) + b - 1) / b;
            int base = p * x0 + q * w;
            int add = p * b - q * a;
            int lx = 0, rx = w / a;
            cost = min({
                cost,
                p * (x0 + b * (rx + 1)),
                base + add * lx,
                base + add * rx
            });
        }
        if ((rest -= cost) < 0)
            return false;
    }
    return true;
}

void Main() {
    cin >> n >> x;
    process.resize(n);
    for (auto &[a, p, b, q] : process)
        cin >> a >> p >> b >> q;
    int l = 0, r = 1e9;
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid))
            ans = mid, l = mid + 1;
        else
            r = mid - 1;
    }
    cout << ans << endl;
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    return Main(), 0;
}

