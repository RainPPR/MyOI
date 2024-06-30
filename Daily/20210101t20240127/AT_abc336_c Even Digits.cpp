#pragma GCC optimize("Ofast,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,bmi,bmi2,lzcnt,tune=native")

#include <immintrin.h>
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define gc() getchar_unlocked()
#define rr read()

inline ll read() {
    ll n = 0; int c = gc();
    while (!isdigit(c)) c = gc();
    while (isdigit(c)) n = n * 10 + c - '0', c = gc();
    return n;
}

int main() {
    ll n = rr - 1;
    if (n == 0) printf("0"), exit(0);
    vector<int> a;
    while (n) a.push_back(n % 5 * 2), n /= 5;
    reverse(a.begin(), a.end());
    for (int &i : a) printf("%d", i);
    return 0;
}
