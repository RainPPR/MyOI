#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

std::random_device gen;
std::mt19937 rnd(gen());

namespace seg {
    #define lowbit(x) ((x) & -(x))
    int s[int(1e7) + 10];
    int cnt = 0;
    void add(int x, int v) {
        cnt += v;
        for (; x <= 1e7; x += lowbit(x))
            s[x] += v;
    }
    int sum(int x) {
        int r = 0;
        for (; x; x -= lowbit(x))
            r += s[x];
        return r;
    }
    int sed(int x) {
        return cnt - sum(x - 1);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    ifstream fin("config.txt");
    int n, q;
    fin >> n >> q;
    fin.close();
    cerr << n << " " << q << endl;
    cout << n << " " << q << endl;
    multiset<int> appr;
    int lt = -1e9;
    for (int i = 1; i <= q; ++i) {
        int op = rnd() % 10 + 1;
        if (appr.empty() || op <= 3) {
            int x = rnd() % n + 1;
            if (!appr.count(x) || rnd() % 5 <= 2) {
                cout << "1 " << x << endl;
                appr.insert(x);
                seg::add(x, 1);
            }
            else {
                cout << "2 " << x << endl;
                appr.erase(appr.find(x));
                seg::add(x, -1);
            }
        }
        else {
            int l = rnd() % n + 1;
            if (appr.lower_bound(l) == appr.end()) {
                l = max(1, l - n / 3);
                if (appr.lower_bound(l) == appr.end())
                    l = 1;
            }
            l = max(1, int(l - rnd() % int(1.14514 * l)));
            int maxk = seg::sed(l);
            assert(maxk != 0);
            int k = rnd() % maxk + 1;
            cout << "3 " << l << " " << k << endl;
        }
        if ((clock() & 0x1ff) == 0 && i - lt > 100) {
            cerr << "# " << pow(i, 4.5) * 100.0 / pow(q, 4.5) << "%" << endl;
            lt = i;
        }
    }
    cerr << "# 100%" << endl;
    return 0;
}