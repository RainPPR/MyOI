#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

template < typename Tp >
void read(Tp &x) {
	x = 0; int fh = 1; char ch = 1;
	while(ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
	if(ch == '-') fh = -1, ch = getchar();
	while(ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	x *= fh;
}

const int maxn = 100000 + 7;
const int maxm = 200000 + 7;
const int mod = 998244353;

int n, a[maxn], s[maxn];
int Head[maxn], to[maxm], Next[maxm], tot;

void add(int x, int y) {
	to[++tot] = y, Next[tot] = Head[x], Head[x] = tot;
}

void Init(void) {
	read(n);
	for(int i = 1; i <= n; i++) read(a[i]);
	for(int i = 1, x, y; i < n; i++) {
		read(x); read(y);
		add(x, y); add(y, x);
	}
}

long long ans;
int cnt, zer[maxn], one[maxn];

void dfs(int x, int f) {
	s[x] ^= s[f]; zer[x] = one[x] = 0;
	for(int i = Head[x]; i; i = Next[i]) {
		int t = to[i]; if(t == f) continue;
		dfs(t, x);
		if(s[x] ^ s[f]) {
			cnt = (cnt + zer[t] * zer[x] % mod) % mod;
			cnt = (cnt + one[t] * one[x] % mod) % mod;
		}
		else {
			cnt = (cnt + zer[t] * one[x] % mod) % mod;
			cnt = (cnt + one[t] * zer[x] % mod) % mod;
		}
		zer[x] += zer[t], one[x] += one[t];
	}
	if(s[x] ^ s[f]) cnt++;
	if(s[f]) cnt += zer[x];
	else cnt += one[x];
	cnt %= mod;
	if(s[x]) one[x]++;
	else zer[x]++;
}

int solve(int id) {
	for(int i = 1; i <= n; i++) {
		s[i] = (a[i] >> id) & 1;
	}
	cnt = 0; dfs(1, 0);
	return cnt;
}

void Work(void) {
	for(int i = 0; i <= 15; i++) {
		ans = (ans + solve(i) * (1ll << i) % mod) % mod;
	}
	printf("%lld\n", ans);
}

int main(void) {
	freopen("jasmine.in", "r", stdin);
	freopen("jasmine.out", "w", stdout);
	Init();
	Work();
	return 0;
}

