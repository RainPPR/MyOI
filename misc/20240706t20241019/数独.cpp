#pragma GCC optimize("O2")

#include <bits/stdc++.h>

using namespace std;

#define lowbit(x) ((x) & -(x))
#define endl '\n'

// -----------------------------------------------------------------------------

inline int getbit(int &x) {
    if (x == 0) return 0;
    int k;
    x -= k = lowbit(x);
    if (k == 1) return 1;
    if (k == 2) return 2;
    if (k == 4) return 3;
    if (k == 8) return 4;
    if (k == 16) return 5;
    if (k == 32) return 6;
    if (k == 64) return 7;
    if (k == 128) return 8;
    if (k == 256) return 9;
    exit(1);
}

int popcount(int x) {
    int c = 0;
    while (x)
        x -= lowbit(x), ++c;
    return c;
}

struct point {
	int x, y;
	point() = default;
	point(int x, int y) : x(x), y(y) {}
};

struct node {
    int x, y, c;
    node() = default;
    node(int x, int y, int c) : x(x), y(y), c(c) {}
};

// -----------------------------------------------------------------------------

int tot, mp[10][10];

void paint() {
	for (int i = 1; i <= 9; ++i)
		for (int j = 1; j <= 9; ++j)
		    cout << mp[i][j];
    cout << endl;
}

int cover[10][10], bak[100][10][10];

void setbin(int x, int y, int c) {
    c = 0b111111111 ^ (1 << c - 1);
    cover[x][y] &= c;
}

void setcolor(int x, int y, int c) {
    for (int k = 1; k <= 9; ++k)
        setbin(x, k, c), setbin(k, y, c);
    int sx = (x - 1) / 3 * 3 + 1;
    int sy = (y - 1) / 3 * 3 + 1;
    for (int dx = 0; dx < 3; ++dx)
        for (int dy = 0; dy < 3; ++dy)
            setbin(sx + dx, sy + dy, c);
}

// -----------------------------------------------------------------------------

point getpos(int &keep) {
    point res(1, 1);
    for (int i = 1, pc = 100; i <= 9; ++i)
        for (int j = 1; j <= 9; ++j) {
            if (mp[i][j]) continue;
            int e = popcount(cover[i][j]);
            if (e == 0) return keep = 0, res;
            if (e < pc) pc = e, res = point(i, j);
        }
    return keep = 1, res;
}

bool dfs(int k, int keep = 0) {
    if (k == tot) return paint(), true;
    memcpy(bak[k], cover, sizeof cover);
    auto [x, y] = getpos(keep);
    if (!keep) return false;
    int e = cover[x][y], c;
    while (c = getbit(e)) {
    	setcolor(x, y, c);
        mp[x][y] = c;
        if (dfs(k + 1)) return true;
        mp[x][y] = 0;
        memcpy(cover, bak[k], sizeof cover);
    }
    return false;
}

// -----------------------------------------------------------------------------

int convert(const char c) {
	if (c == '.') return ++tot, 0;
	else return c - '0';
}

void solev(string &str) {
	tot = 0;
	for (int i = 1; i <= 9; ++i)
		for (int j = 1; j <= 9; ++j)
			mp[i][j] = convert(str[(i - 1) * 9 + j - 1]);
    for (int i = 1; i <= 9; ++i)
        for (int j = 1; j <= 9; ++j)
            cover[i][j] = 0b111111111;
    for (int i = 1; i <= 9; ++i)
        for (int j = 1; j <= 9; ++j)
            if (mp[i][j]) setcolor(i, j, mp[i][j]);
	dfs(0);
}

// -----------------------------------------------------------------------------

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	string str;
	while (cin >> str && str != "end") solev(str);
	return 0;
}

