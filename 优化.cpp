#define _GLIBCXX_DEBUG

#pragma GCC optimize(1,2,"inline","Ofast,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,bmi,bmi2,lzcnt,tune=native")

#include <immintrin.h>

#define fO0 __attribute__ ((__optimize__ ("-O0")))
// #pragma GCC unroll 8

#include <bits/stdc++.h>

using namespace std;

#define DEBUG 0

#ifdef __linux__
#define getchar() getchar_unlocked()
#define putchar(c) putchar_unlocked(c)
#endif

struct IO {
// getchar & putchar
#if DEBUG
    char gc() { return getchar(); }
    void pc(char c) { putchar(c); }
#else
    #define MSIZE (1 << 20)
    char buf[MSIZE], *p1, *p2;
    char pbuf[MSIZE], *pp;
    IO(): p1(buf), p2(buf), pp(pbuf) {}
    ~IO() { fwrite(pbuf, 1, pp - pbuf, stdout); }
    char gc() { return (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, MSIZE, stdin), p1 == p2) ? EOF : *p1++); }
    void pc(char c) { (pp - pbuf == MSIZE && (pp = (fwrite(pbuf, 1, MSIZE, stdout), pbuf))), *pp++ = c; }
    #undef MSIZE
#endif
// input & output
    #define nline(c) (c == '\n' || c == '\r')
    #define blank(c) (c == ' ' || c == '\t' || nline(c))
    void read(char &c) { do c = gc(); while (blank(c)); }
    void read(char *s) { char c = gc(); while (blank(c)) c = gc(); while (!blank(c)) *s++ = c, c = gc(); *s = 0; }
    void readline(char *s) { char c = gc(); while (nline(c)) c = gc(); while (!nline(c)) *s++ = c, c = gc(); *s = 0; }
    template<typename t> void read(t &x) {
        int f = 0; char c = gc(); x = 0;
        for (; !isdigit(c); c = gc()) f |= c == '-';
        for (; isdigit(c); c = gc()) x = x * 10 + (c - '0');
        if (f) x = -x;
    }
    template<typename t> void write(t x, char ed = '\n') {
        if (x < 0) pc('-'), x = -x;
        static t stk[35]; t top = 0;
        do stk[top++] = x % 10, x /= 10; while (x);
        while (top) pc(stk[--top] + '0');
        pc(ed);
    }
    #undef nline
    #undef blank
} io;

signed main() {
    char s[256];
    io.readline(s);
    cout << s << endl;
    return 0;
}