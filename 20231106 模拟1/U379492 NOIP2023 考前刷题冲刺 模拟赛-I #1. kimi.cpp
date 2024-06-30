#include <bits/stdc++.h>

using namespace std;

signed main() {
    int n, d, e;
    scanf("%d%d%d", &n, &d, &e);
    e *= 5;

    int ans = n;
    for (int i = 0; i <= n; i += e)
        ans = min(ans, (n - i) % d);
    
    printf("%d\n", ans);
    return 0;
}
