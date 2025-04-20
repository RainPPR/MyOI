// Coakira

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 401;
int N, YSum, KSum, OSum;
//int F[MAXN][MAXN][MAXN][2];//前i个F前j个K前k个其他字符中是不是F 的代价
int sum[1010][3], sub[1010][3];
int pool[MAXN * MAXN * MAXN + 10];
string S;
int Query(int x, int y, int z, int st) {
    int QWQ;
    if (st == 0)
        QWQ = sub[x][0];
    if (st == 1)
        QWQ = sub[y][1];
    if (st == 2)
        QWQ = sub[z][2];
    return QWQ - min(x, sum[QWQ][0]) - min(y, sum[QWQ][1]) - min(z, sum[QWQ][2]);
}
int main() {
    scanf("%d", &N);
    cin >> S;

    for (int i = 1; i <= N; i++) {
        sum[i][0] = sum[i - 1][0];
        sum[i][1] = sum[i - 1][1];
        sum[i][2] = sum[i - 1][2];
        if (S[i - 1] == 'Y') sum[i][0]++, sub[++YSum][0] = i;
        if (S[i - 1] == 'K') sum[i][1]++, sub[++KSum][1] = i;
        if (S[i - 1] != 'Y' && S[i - 1] != 'K') sum[i][2]++, sub[++OSum][2] = i;
    }

    int (&F)[YSum + 5][KSum + 5][OSum + 5][2] = decltype(F)(pool);

    for (int i = 0; i <= YSum; i++)
        for (int j = 0; j <= KSum; j++)
            for (int k = 0; k <= OSum; k++)
                F[i][j][k][0] = F[i][j][k][1] = 1e9 + 10;

    F[0][0][0][0] = 0;
    for (int i = 0; i <= YSum; i++)
        for (int j = 0; j <= KSum; j++)
            for (int k = 0; k <= OSum; k++) {
                F[i + 1][j][k][1] = min(F[i + 1][j][k][1], min(F[i][j][k][0], F[i][j][k][1]) + Query(i + 1, j, k, 0)); //多一个F
                F[i][j + 1][k][0] = min(F[i][j + 1][k][0], F[i][j][k][0] + Query(i, j + 1, k, 1)); //多一个K
                F[i][j][k + 1][0] = min(F[i][j][k + 1][0], min(F[i][j][k][0], F[i][j][k][1]) + Query(i, j, k + 1, 2)); //多一个别的
            }

    printf("%d", min(F[YSum][KSum][OSum][0], F[YSum][KSum][OSum][1]));
    return 0;
}
