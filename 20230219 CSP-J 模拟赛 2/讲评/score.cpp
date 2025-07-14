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

unordered_map <long long, int> mp;

int n, m, cnt;
const int maxn = 100000 +7;

struct xiaoke {
	long long S; int id; 
}S[17];

bool cmp(xiaoke a, xiaoke b) {
	return a.S < b.S;
}

bool cmp2(xiaoke a, xiaoke b) {
	return a.id < b.id;
}

struct contest {
	long long uni, scr;
};

struct player {
	long long id;
	int tot;
	contest c[17];
	void add(long long p, int s) {
		bool exist = false;
		for(int i = 1; i <= tot; i++) {
			if(c[i].uni == p) {
				exist = true;
				c[i].scr += s;
				break;
			}
		}
		if(exist == false) {
			c[++tot].uni = p;
			c[tot].scr += s;
		}
	}
}a[maxn];

string s;
long long id, uni;
int scr;

void doit(void) {
	id = uni = 0;
	for(int i = 0 ; i < 10; i++) {
		uni = uni * 10 + s[i] - '0';
	}
	for(int i = 10; i < 24; i++) {
		id = id * 10 + s[i] - '0';
	}
}

void Init(void) {
	cin >> n >> m;
	for(int i = 1; i <= 2 * n; i++) {
		cin >> s >> scr; doit();
		if(mp[id] == 0) {
			mp[id] = ++cnt;
			a[cnt].add(uni, scr);
		}
		else {
			int oid = mp[id];
			a[oid].add(uni, scr);
		}
	}
	for(int i = 1; i <= m; i++) {
		cin >> S[i].S; S[i].id = i;
	}
}

bool comp(contest a, contest b) {
	if(a.scr == b.scr) return a.uni < b.uni;
	else return a.scr < b.scr;
}

void Work(void) {
	sort(S + 1, S + m + 1, cmp);
	for(int i = 1; i <= cnt; i++) {
		sort(a[i].c + 1, a[i].c + m + 1, comp);
		for(int j = 1; j <= m; j++) {
			a[i].c[j].scr = (a[i].c[j].scr + 1) / 2;
//			cout << "***" << i << " " << j << " "<< a[i].c[j].scr << endl; 
		}
		bool ok = true;
		for(int j = 1; j <= m; j++) {
			if(S[j].S != a[i].c[j].scr) {
				ok = false;
				break;
			}
		}
		if(ok) {
			sort(S + 1, S + m + 1, cmp2);
			for(int j = 1; j <= m; j++) {
				for(int p = 1; p <= m; p++) {
					if(S[j].S == a[i].c[p].scr) cout << a[i].c[p].uni << endl;
				}
			}
			return;
		}
	}
}

int main(void) {
	freopen("score.in", "r", stdin);
	freopen("score.out", "w", stdout);
	ios::sync_with_stdio(false);
	Init();
	Work();
	return 0;
}

