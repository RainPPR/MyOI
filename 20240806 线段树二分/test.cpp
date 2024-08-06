#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

std::random_device gen;
std::mt19937 rnd(gen());

signed main() {
    //int t;
    //cin >> t;
    for (int x = 1; x <= 10; ++x) {
        string sx = to_string(x);
        system(("gen.exe > maximum" + sx + ".in").c_str());
        system(("\"分块.exe\" < maximum" + sx + ".in > maximum" + sx + ".ans").c_str());
    }
    return 0;
}
