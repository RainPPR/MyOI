#pragma GCC optimize("Ofast,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,bmi,bmi2,lzcnt,tune=native")

#include <immintrin.h>
#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (decltype(n) i = 0; i < n; ++i)
#define gor(i, l, r) for (decltype(r) i = l; i < r; ++i)

#define gc() getchar_unlocked()
#define rr read()

inline int read() {
    int n = 0, c = gc();
    while (!isdigit(c)) c = gc();
    while (isdigit(c)) n = n * 10 + c - '0', c = gc();
    return n;
}

constexpr int N = 1e6 + 10;
constexpr int Q = 2e5 + 10;

struct point { int x, y; };

class snk {
private:
int hd, tl; point pos[N + Q];
void push_up() {
    point &bak = pos[tl++]; ++hd;
    pos[tl] = {bak.x, bak.y + 1};
} void push_down() {
    point &bak = pos[tl++]; ++hd;
    pos[tl] = {bak.x, bak.y - 1};
} void push_left() {
    point &bak = pos[tl++]; ++hd;
    pos[tl] = {bak.x - 1, bak.y};
} void push_right() {
    point &bak = pos[tl++]; ++hd;
    pos[tl] = {bak.x + 1, bak.y};
} public:
snk(int n) { tl = n, hd = 1; rep(i, n) pos[i + 1] = {n - i, 0}; }
point query(int q) { return pos[tl - q + 1]; }
void action(char op) { switch (op) {
    case 'U': push_up(); break;
    case 'D': push_down(); break;
    case 'L': push_left(); break;
    case 'R': push_right(); break;
    default: throw "UNKNOWN OPERATOR";
}} };

signed main() {
    snk a(rr); int q = rr;
    while (q--) if (rr == 1) {
        char s[20];
        scanf("%s", s);
        a.action(s[0]);
    } else {
        auto r = a.query(rr);
        printf("%d %d\n", r.x, r.y);
    } return 0;
}