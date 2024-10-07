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
    // [l, r) ��ʱ�� t ʱ�ĳɱ�
    auto f = [&](ll l, ll r, ll t) -> ll {
        return t * (r - l) - S[r] + S[l];
    };

    // dp[i][j] �Ķ���
    // [0, i) �Ѿ�����
    // ǰһ�������� T[j + i] - X ֮ǰ
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
            // �� t ʱ�̴��� [l, r) �Ķ���
            cost += f(l, r, t);
            // ��� r == N �����
            if (r == N){
                chmin(ans, cost);
                break;
            }
            // ��һ��ʱ���� t�����
            // ����ϣ���ҵ����� t <= T[r + a] - X �� a
            int a = 0;
            while (r + a != N && a != K && t > T[r + a] - X) a++;
            // ����ҵ��� a������� dp
            if (r + a != N && a != K){
                chmin(dp[r][a], cost);
                // ��һ�μ��账��ķ�Χ�� [r, r + a)
                // ��� a = 0�����ʾ T[r - 1] �� T[r] �㹻Զ
                if (a == 0){
                    break;
                }
            }
            else{
                // ��һ�μ��账��ķ�Χ�� [r, r + K)
                // r + K �������� N ����
                a = min(K, N - r);
            }
            // ���� l, r, t
            l = r;
            r = r + a;
            t += X;
        }
    }
    // �����
    cout << ans << "\n";
}
