#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

void solve(const string &str) {
    int ans = 0;
    for (char c : str)
        ans += (c == '+' ? 1 : -1);
   	vector<int> delta(str.size());
    for (size_t i = 0; i < str.size(); ++i)
        delta[i] = ((i & 1) ? -1 : 1) - (str[i] == '+' ? 1 : -1);
    sort(delta.begin(), delta.end(), greater<>());
    cout << ans << " ";
    for (int i : delta) {
        ans += i;
        cout << ans << " ";
    }
    cout << endl;
}

void Main() {
	int T;
	cin >> T;
	while (T--) {
		string str;
		cin >> str;
		solve(str);
	}
	return;
}

signed main() {
//	freopen("confess.in", "r", stdin);
//	freopen("confess.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	return Main(), 0;
}
