#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

#define rev(s, l, r) reverse((s).begin() + (l), (s).begin() + (r) + 1)

void MAIN1(int n, const string &op) {
	vector<int> a(n);
	iota(a.rbegin(), a.rend(), 1);
	for (int i = 0; i < n - 1; ++i) {
		if (op[i] == '>')
			continue;
		int j = i;
		while (j < n - 1 && op[j] == '<')
			++j;
		// [i, j)
		rev(a, i, j);
		i = j;
	}
	for (int i : a)
		cout << i << " ";
	cout << endl;
}

void MAIN2(int n, const string &op) {
	vector<int> a(n);
	iota(a.begin(), a.end(), 1);
	for (int i = 0; i < n - 1; ++i) {
		if (op[i] == '<')
			continue;
		int j = i;
		while (j < n - 1 && op[j] == '>')
			++j;
		// [i, j)
		rev(a, i, j);
		i = j;
	}
	for (int i : a)
		cout << i << " ";
	cout << endl;
}

void MAIN(int n, const string &op) {
	MAIN1(n, op);
	MAIN2(n, op);
}

void Main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		string op;
		cin >> op;
		MAIN(n, op);
	}
	return;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	return Main(), 0;
}

