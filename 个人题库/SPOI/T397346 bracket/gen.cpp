// 9-20

#include <bits/extc++.h>

using namespace std;

#define cmd(x) system(string(x).c_str())
#define open(x) ofstream fout(x)

string td = "bracket";

mt19937 rd(time(0) * clock());

char getrd() {
    int op = rd() % 2;
    return op ? '(' : ')';
}

string gen(int q) {
    string r;
    while (q--) r.push_back(getrd());
    return r;
}

void solve(int k) {
    string K = to_string(k);
    int cnt = rd() % 101 + 400;
    vector<string> op;
    while (cnt) {
        int th = rd() % 201 + 200;
        th = min(th, cnt);
        op.push_back(gen(th));
        cnt -= th;
    } open(td + K + ".in");
    fout << op.size() << endl;
    for (auto i : op) {
        fout << i << endl;
    } fout.close();
    cmd("time ./std.out <" + td + K + ".in>" + td + K + ".out");
}

signed main() {
    int l = 9, r = 20;
    for (int i = l; i <= r; ++i) solve(i);
    return 0;
}
