#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int ABS(double n)
{
	return (n < 0) ? -n : n;
}

int Round(double n)
{
	return int(n + 0.5);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	string str;

	scanf("%d", &n);

	while (n--)
	{
		cin >> str;

		set<char> s;
		for (char i : str)
			s.insert(i);

		int pos = s.size() / 2;

		int target;
		int j = 0;
		for (char i : s)
		{
			if (j++ == pos)
			{
				target = (int)i;
				break;
			}
		}

		int ans = 0;
		for (char i : str)
			ans += ABS((int)i - target);
		printf("%d\n", ans);
	}

	return 0;
}
