#include <bits/stdc++.h>

using namespace std;

using ll = long long;

stack<int> num;
stack<char> op;

int qpow(int a, int b) {
	int r = 1;
	for (; b; b >>= 1) {
		if (b & 1) r = r * a;
		a = a * a;
	}
	return r;
}

void eval() {
	int b = num.top(); num.pop();
	int a = num.top(); num.pop();
	char c = op.top(); op.pop();
	switch (c) {
		case '+': num.push(a + b); break;
		case '-': num.push(a - b); break;
		case '*': num.push(a * b); break;
		case '/': num.push(a / b); break;
		case '^': num.push(qpow(a, b)); break;
		default: break;
	}
}

unordered_map<char, int> priority = {
	{'+', 1}, {'-', 1},
	{'*', 2}, {'/', 2},
	{'^', 3}
};

int solev(string s) {
	int n = s.size();
	int fl = 0;
	for (int i = 0; i < n; ++i) {
		char c = s[i];
		if (isdigit(c)) {
			int x = 0, j = i;
			while (j < n && isdigit(s[j]))
				x = x * 10 + s[j] - '0', ++j;
			num.push(fl ? -x : x), i = j - 1;
			fl = 0;
		}
		else if (c == '(') op.push(c);
		else if (c == ')') {
			while (op.top() != '(') eval();
			op.pop();
		}
		else {
			if (c == '-' && (i == 0 || (!isdigit(s[i - 1]) && s[i - 1] != ')'))) {
				num.push(-1), op.push('*');
				continue;
			}
			while (op.size() && priority[op.top()] >= priority[c]) eval();
			op.push(c);
		}
	}
	while (op.size()) eval();
	return num.top();
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	string str; cin >> str;
	int lk = count(str.begin(), str.end(), '(');
	int rk = count(str.begin(), str.end(), ')');
	int delta;
	if (lk < rk) { delta = rk - lk; while (delta--) str = "(" + str; }
	else if (rk < lk) { delta = lk - rk; while (delta--) str.push_back(')'); }
	cout << solev(str) << endl;
	return 0;
}

