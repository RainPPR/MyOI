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
const int mod = 998244353;

int n, p[maxn], f[maxn];
int size[maxn];

int find(int x) {
	if(f[x] == x) return x;
	else return f[x] = find(f[x]); 
}

void Init(void) {
	read(n);
	for(int i = 1; i <= n; i++) {
		read(p[i]); f[i] = i;
	}
}

vector <int> v;

void Work(void) {
	for(int i = 1; i <= n; i++) {
		int fi = find(i), fp = find(p[i]);
		if(fi == fp) continue;
		f[fi] = fp;
	}
	for(int i = 1; i <= n; i++) {
		size[find(i)]++;
	}
	for(int i = 1; i < n; i++) {
		printf("%d ", size[find(i)]);
	}
	printf("%d\n", size[find(n)]);
}

int main(void) {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	Init();
	Work();
	return 0;
}

