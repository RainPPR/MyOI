#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

using ll = long long;

constexpr int N = 2e5 + 10;

vector<int> primes, isprime;

void euler(int n) {
    isprime.resize(n + 1, 1);
    for (int i = 2; i <= n; ++i) {
        if (isprime[i]) primes.push_back(i);
        for (int j : primes) {
            if (1ll * i * j > n) break;
            isprime[i * j] = 0;
            if (i % j == 0) break;
        }
    }
}

#define kBase 13
#define Base 10000000000000
#define bigTp unsigned long long

class bigint {
private:
    vector<bigTp> a;
public:
    bigint() = delete;
    explicit bigint(ll n = 0) {
        a.clear();
        while (n) a.push_back(n % Base), n /= Base;
    }
    void operator *=(ll x) {
        bigTp lt = 0;
        for (auto &i : a) {
            bigTp c = lt + i * x;
            i = c % Base, lt = c / Base;
        }
        while (lt) a.push_back(lt % Base), lt /= Base;
    }
    void print() {
        for (auto it = a.rbegin(); it != a.rend(); ++it)
            if (it == a.rbegin()) cout << *it;
            else cout << setw(kBase) << setfill('0') << *it;
    }
};

int ctt[N];

void calc(int n, int op) {
    for (int i : primes) {
        if (i > n) break;
        int cnt = 0;
        for (int j = i; j <= n; j *= i) cnt += n / j;
        ctt[i] += cnt * op;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int a, b;
    cin >> a >> b;
    euler(a);
    calc(a, 1);
    calc(b, -1);
    calc(a - b, -1);
    bigint res(1);
    for (int i = 2; i <= a; ++i)
        while (ctt[i]--) res *= i;
    return res.print(), 0;
}