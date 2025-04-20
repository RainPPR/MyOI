#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <unordered_set>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string str;
	int n;
	cin >> str >> n;

	if (str.size() < n)
		printf("impossible\n");
	else
	{
		unordered_set<char> s;

		for (char i : str)
			s.insert(i);

		int ans = n - s.size();
		if (ans < 0)
			ans = 0;

		printf("%d", ans);
	}
	return 0;
}
