#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

std::random_device gen;
std::mt19937 rnd(gen());

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int M = 5e5;
    cout << M << " " << M << endl;
    cout << "1 " << M << endl;
    for (int i = 1; i < M; ++i) {
        cout << "3 2 1" << endl;
    }
    return 0;
}