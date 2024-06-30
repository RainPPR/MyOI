#include <bits/stdc++.h>

using namespace std;

mt19937 rd(time(0) * clock());

signed main() {
    int T = 2e7;
    fstream fout("in.txt");
    fout << T << endl;
    while (T--) {
        int n = rd() % int(1e5 + 1) + int(1e7 - 1e5);
        fout << n << endl;
    } return 0;
}