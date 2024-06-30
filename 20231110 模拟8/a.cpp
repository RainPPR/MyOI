#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr ll per = 1e6;

signed main() {
    ll b, c, r, d;
    scanf("%lld%lld%lld%lld", &b, &c, &r, &d);
    ll ans = (b * per + c) / r;
    #define now (u * r % per)
    for (ll u = 1; u <= per; ++u)
    if (now > c and now + d < per) {
        ans = min(ans, u - 1);
        break;
    } printf("%lld\n", ans);
    return 0;
}
