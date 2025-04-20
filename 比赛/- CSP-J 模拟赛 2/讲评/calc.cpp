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

int T;
long long a, b, ans;
string op;

void Init(void) {
	cin >> T;
}

void Work(void) {
	while(T--) {
		cin >> op >> a >> b;
		if(op == "plus") {
			ans = a + b;
		}
		else if(op == "redu") {
			ans = a - b;
		}
		else if(op == "muti") {
			ans = a * b;
		}
		else if(op == "bmod") {
			ans = (a % b + b) % b;
		}
		else if(op == "ldiv") {
			if(a * b > 0) {
				ans = a / b;
			}
			else {
				if(a % b == 0) ans = a / b;
				else ans = a / b - 1;
			}
		}
		else {
			if(a * b > 0) {
				if(a % b == 0) ans = a / b;
				else ans = a / b + 1;
			}
			else {
				ans = a / b;
			}
		}
		cout << ans << '\n';
	}
}

int main(void) {
	freopen("calc.in", "r", stdin);
	freopen("calc.out", "w", stdout);
	ios::sync_with_stdio(false);
	Init();
	Work();
	return 0;
}

