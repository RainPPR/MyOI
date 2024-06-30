#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)

signed main() {
    int n; cin >> n;
    int isame = -1;
    vector<int> a(n);
    vector<int> appear(1010);
    rep(i, n) {
        cin >> a[i];
        if (++appear[a[i]] > 1) isame = a[i];
    } if (isame != -1) {
        printf("1 1\n");
        int i = 0;
        while (a[i] != isame) ++i;
        printf("%d\n", ++i);
        while (a[i] != isame) ++i;
        printf("%d\n", i + 1);
        return 0;
    } printf("-1\n");
    return 0;
}
