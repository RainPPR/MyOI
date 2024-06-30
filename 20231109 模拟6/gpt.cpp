#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

int main() {
    string S;
    cin >> S;
    int n = S.length();

    vector<vector<int>> dp(n, vector<int>(n, 0));

    // ��ʼ������Ϊ 1 ���Ӵ�
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    // ���㳤�ȴ��� 1 ���Ӵ�
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (S[i] == '(' && S[j] == ')') {
                dp[i][j] = (dp[i+1][j-1] + 2);
            }
            for (int k = i; k < j; k++) {
                dp[i][j] = dp[i][j] + (dp[i][k] * dp[k+1][j]);
            }
        }
    }

    // ������
    int ans = 0;
    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
            ans = (ans + ((l + 1) ^ (r + 1) ^ dp[l][r])) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}