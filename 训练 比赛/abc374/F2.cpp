#include <bits/stdc++.h>
using namespace std;
using ll=long long;
template<class T> bool chmin(T &a,T b){if(a>b){a=b;return 1;}else return 0;}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    ll X;
    cin >> N >> K >> X;
    vector<ll> T(N);
    for (int i = 0; i < N; i++) cin >> T[i];
    vector<ll> S(N + 1);
    for (int i = 0; i < N; i++) S[i + 1] = S[i] + T[i];
    // [l, r) 在时刻 t 时的成本
    auto f = [&](ll l, ll r, ll t) -> ll {
        return t * (r - l) - S[r] + S[l];
    };

    // dp[i][j] 的定义
    // [0, i) 已经处理
    // 前一个操作在 T[j + i] - X 之前
    vector dp(N, vector<ll>(K, 1ll << 60));
    ll ans = (1ll << 60);
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) for (int j = 0; j < K; j++){
        if (j + 1 != K) chmin(dp[i][j + 1], dp[i][j]);
        if (j + i == N) break;
        ll cost = dp[i][j];
        int l = i, r = i + j + 1;
        ll t = T[j + i];
        while (true){
            // 在 t 时刻处理 [l, r) 的订单
            cost += f(l, r, t);
            // 如果 r == N 则结束
            if (r == N){
                chmin(ans, cost);
                break;
            }
            // 上一个时刻是 t，因此
            // 我们希望找到满足 t <= T[r + a] - X 的 a
            int a = 0;
            while (r + a != N && a != K && t > T[r + a] - X) a++;
            // 如果找到了 a，则更新 dp
            if (r + a != N && a != K){
                chmin(dp[r][a], cost);
                // 下一次急需处理的范围是 [r, r + a)
                // 如果 a = 0，则表示 T[r - 1] 和 T[r] 足够远
                if (a == 0){
                    break;
                }
            }
            else{
                // 下一次急需处理的范围是 [r, r + K)
                // r + K 需限制在 N 以内
                a = min(K, N - r);
            }
            // 更新 l, r, t
            l = r;
            r = r + a;
            t += X;
        }
    }
    // 输出答案
    cout << ans << "\n";
}
