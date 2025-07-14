/* SOLUTION 1
С M ��һ������Ϊ $n$ ������ $v_1,v_2,\ldots,v_n$����ʼʱ������Ԫ�ص�ֵ��Ϊ $1$��

1. ѡ��һ���±� $i$��$1\le i\le n$�������ҽ� $v_1,v_2,\ldots,v_i$ ��ֵȫ����Ϊ $0$�����ֲ����Ĵ����� $a_i$��
2. ѡ��һ���±� $i$��$1\le i\le n$�������ҽ� $v_i$ ��ֵ��Ϊ $0$�����ֲ����Ĵ����� $b_i$��
3. ѡ��һ���±� $i$��$1\le i\le n$�������ҽ� $v_i$ ��ֵ��Ϊ $1$�����ֲ����Ĵ����� $c_i$��

������ $q$ ��ѯ�ʣ�ÿ��ѯ���и���һ������ $P$����ϣ���������ɴβ���������Ϊ $0$����ʹ�ã����� $v$ ���±�λ�ڸü��ϵ�Ԫ�ص�ֵΪ $1$������λ�õ�ֵΪ $0$��**��ʽ����˵���������� $\bm{1\le i\le n}$���� $\bm{i\in P}$���� $\bm{v_i=1}$������ $\bm{v_i=0}$��** ���ң�����Ҫ��С�����ѯ�������в������ܴ��ۡ�

dp[i][0/1] ��ʾ��ȫ 0/1 �����е�ǰ i λ��ȷƥ�����С����

dp[i][0] =
- if i in P��f[i - 1][0] + c[i]
- if i notin P��f[i - 1][0]
dp[i][1] =
- if i in P��f[i - 1][1]
- if i notin P��min(f[i - 1][1] + b[i], a[i] + f[i - 1][0])

��Ϊ dp[n][1]*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int INF = 1e9;
const ll INF64 = 4e18;

#define rr read()
inline int read() {
    int num = 0, flag = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = num * 10 + ch - '0';
    return num * flag;
}

#define tp(t) template<typename t> inline t

#define max(a, b) _max(a, b)
tp(t) _max(const t a, const t b) { return a > b ? a : b; }
#define min(a, b) _min(a, b)
tp(t) _min(const t a, const t b) { return a < b ? a : b; }
#define abs(x) _abs(x)
tp(t) _abs(const t x) { return x < 0 ? -x : x; }

const int N = 5e5 + 10;

int a[N], b[N], c[N], p[N];
ll f[N][2];

signed main() {
    int n = rr;
    for (int i = 1; i <= n; ++i) a[i] = rr;
    for (int i = 1; i <= n; ++i) b[i] = rr;
    for (int i = 1; i <= n; ++i) c[i] = rr;
    int q = rr; while (q--) {
        int m = rr; for (int i = 1; i <= m; ++i) p[rr] = 1;
        for (int i = 1; i <= n; ++i) {
            if (p[i]) f[i][0] = f[i - 1][0] + c[i], f[i][1] = min(f[i - 1][1], a[i] + f[i - 1][0] + c[i]);
            else f[i][0] = f[i - 1][0], f[i][1] = min(f[i - 1][1] + b[i], f[i - 1][0] + a[i]);
        } printf("%lld\n", f[n][1]);
        for (int i = 1; i <= n; ++i) p[i] = 0;
    }
    return 0;
}
