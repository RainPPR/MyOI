#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define puts(x) ([] () { cout << x << endl; } ())

#define for_sigma(c) for (int c = 0; c < 26; ++c)

constexpr int N = 1e5 + 10;

int n, str[N];

int cnt[30];

int res;
vector<int> ans[N];

bool input() {
	string tmp;
	cin >> n >> tmp;
	for (int i = 1; i <= n; ++i)
		++cnt[str[i] = tmp[i - 1] - 'a'];
	for_sigma (i)
		if (cnt[i] >= (n + 1) / 2)
			return true;
	return false;
}

void fail() {
	puts("Shuiniao");
}

bool solutionA() {
	res = n >> 1;
	array<vector<int>, 256> pos;
	for (int i = 1; i <= n; ++i)
		pos[str[i]].push_back(i);
	vector<int> q{0};
	for_sigma (i)
		for (auto j : pos[i])
			q.push_back(j);
	for (int i = 1; i <= (n >> 1); ++i) {
		ans[i].push_back(q[i]);
		ans[i].push_back(q[i + (n >> 1)]);
	}
	if (n & 1)
		ans[1].push_back(q[n]);
	return true;
}

bool solutionB() {
	return false;
}

void print() {
	puts("Huoyu");
}

void MAIN() {
	if (input()) {
		if (solutionA())
			print();
		else
			fail();
	}
	else {
		if (solutionB())
			print();
		else
			fail();
	}
	return;
}

void Main() {
	int c, q;
	cin >> c >> q;
	while (q--)
		MAIN();
	return;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	return Main(), 0;
}
