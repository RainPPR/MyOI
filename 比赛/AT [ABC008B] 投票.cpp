#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	map<string, int> cnt;

	string str;
	for (int i = 0 ; i < n ; ++i)
	{
		cin >> str;
		++cnt[str];
	}

	int max_cnt = -2e9;
	for (pair<string, int> i : cnt)
		if (i.second > max_cnt)
			max_cnt = i.second, str = i.first;

	cout << str << endl;
	return 0;
}
