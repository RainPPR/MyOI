#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pli = pair<long long, int>;
using pil = pair<int, long long>;

#define rr read()
inline ll read() {
    ll num = 0, flag = 1;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') flag = -1;
    for (; isdigit(ch); ch = getchar()) num = num * 10 + ch - '0';
    return num * flag;
}

#define tp(t) template<typename t> inline t

#define max _max
tp(t) _max(const t a, const t b) { return a > b ? a : b; }
#define min _min
tp(t) _min(const t a, const t b) { return a < b ? a : b; }
#define abs _abs
tp(t) _abs(const t x) { return x < 0 ? -x : x; }

#define open(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout);
#define close() fclose(stdin), fclose(stdout);

const int M = 1e5 + 10;

struct obj {
    ll a, b;
    ll up, c;
} o[M];

vector<ll> e;
vector<ll> ans;

int main() {
    // open(paradise);
    int T = rr, op = rr;
    while (T--) {
        int m = rr, q = rr;
        // clear objects
        int idx = 0; for (int i = 1; i <= m; ++i) {
            ++idx, o[idx].a = rr, o[idx].b = rr; o[idx].c = 0;
            if (idx > 1 && (1.0 * o[idx].b / o[idx].a) >= (1.0 * o[idx - 1].b / o[idx - 1].a)) --idx;
        } m = idx;
        // calculate up to next
        o[m].up = 4e18; for (int i = 1; i < m; ++i) o[i].up = o[i + 1].a / o[i].a;
        // clear query
        e.clear(); for (int i = 0; i < q; ++i) e.push_back(rr);
        // calculate
        ans.clear(); ans.push_back(0);
        for (ll i = 1; i < e.back(); ++i) {
            ll use = 0; for (int i = 1; i <= m; ++i) {
                use += o[i].b;
                if (++o[i].c < o[i].up) break;
                use -= o[i].b * o[i].up;
                o[i].c = 0;
            } ans.push_back(ans.back() + use);
        }
        // output
        for (ll i = 1; i < ans.size(); ++i) ans[i] += ans[i - 1];
        for (int i = 0; i < q; ++i) printf("%lld\n", ans[e[i] - 1]);
    }
    // close();
    return 0;
}

// ������Ʒ����Ȼ������Ҫ�� a Խ��ģ��Լ۱�Խ����һ���ϸ����
// һ�����ַ��ǣ����Ե��Ƴ���ÿ�� n �ǵ����
// ����һ��������£�����һ�� 1 �ţ�������� a2 �������� a1 �� a2���Դ�����
